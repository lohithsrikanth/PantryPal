#include <iostream>
#include "gumbo.h"
#include <string>
#include <curl/curl.h>
#include <cstring>
#include "algorithm"

using namespace std;

typedef size_t( * curl_write)(char *, size_t, size_t, string *);

string request(string word) {
    CURLcode res_code = CURLE_FAILED_INIT;
    CURL* curl = curl_easy_init();
    string result;
    string url = "https://www.merriam-webster.com/dictionary/" + word;

    curl_global_init(CURL_GLOBAL_ALL);

    if (curl) {
        curl_easy_setopt(curl,
        CURLOPT_WRITEFUNCTION,
        static_cast<curl_write> ([](char* contents, size_t size,
            size_t nmemb, string* data)->size_t {
                size_t new_size = size * nmemb;
                if (data == NULL) {
                    return 0;
                }
                data->append(contents, new_size);
                return new_size;
            }));
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "simple scraper");

        res_code = curl_easy_perform(curl);

        if (res_code != CURLE_OK) {
            return curl_easy_strerror(res_code);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return result;
}

string str_replace(string search, string replace, string& subject) {
    size_t count;
    for (string::size_type pos{};
        subject.npos != (pos = subject.find(search.data(), pos, search.length()));
        pos += replace.length(), ++count) {
            subject.replace(pos, search.length(), replace.data(), replace.length());
    }

    return subject;
}

string extract_text(GumboNode* node) {
    if (node->type == GUMBO_NODE_TEXT) {
        return string(node->v.text.text);
    }
    else if (node->type == GUMBO_NODE_ELEMENT &&
            node->v.element.tag != GUMBO_TAG_SCRIPT &&
            node->v.element.tag != GUMBO_TAG_STYLE) {
                string contents = "";
                GumboVector* children = &node->v.element.children;
                for (unsigned int i = 0; i < children->length; ++i) {
                    string text = extract_text((GumboNode *)children->data[i]);
                    if (i != 0 && !text.empty()) 
                        contents.append("");
                    
                    contents.append(str_replace(":", ">", text));
                }
            
            return contents;
    }
    else {
        return "";
    }
}

string find_definitions(GumboNode* node) {
    string res = "";
    GumboAttribute* attr;
    if (node->type != GUMBO_NODE_ELEMENT) {
        return res;
    }

    if ((attr = gumbo_get_attribute(&node->v.element.attributes, "class")) &&
        strstr(attr->value, "dtText") != NULL) {
            res += extract_text(node);
            res += "\n";
        }

    GumboVector* children = &node->v.element.children;
    for (int i = 0; i < children->length; ++i) {
        res += find_definitions(static_cast<GumboNode*>(children->data[i]));
    }

    return res;
}

string scrape(string markup) {
    string res = "";
    GumboOutput* output = gumbo_parse_with_options(&kGumboDefaultOptions, markup.data(), markup.length());

    res += find_definitions(output->root);

    gumbo_destroy_output(&kGumboDefaultOptions, output);

    return res;
}


string strtolower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    return str; 
}

int main(int argc, char **argv) {
    // GumboOutput* output = gumbo_parse("<h1>Hello, World!</h1>");
    // // Do stuff with output->root
    // std::cout << "I'm the best" << "\n";
    // gumbo_destroy_output(&kGumboDefaultOptions, output);
    if (argc != 2) {
        cout << "Please provide a valid English word" << endl;
        exit(EXIT_FAILURE);
    }

    string arg = argv[1];
    string res = request(arg);
    cout << scrape(res) << endl;

    return EXIT_SUCCESS;
}