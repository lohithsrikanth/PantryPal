#ifndef ADVANCED_REQUEST
#define ADVANCED_REQUEST

#include <curl/curl.h>
#include <string>
#include "json.hpp"

using namespace std;

using json = nlohmann::json;

class Request {
public:
    json makeRequest(string& url);
    static size_t write_callback(char* ptr, size_t size, size_t nmemb, string* userdata);
};

#endif