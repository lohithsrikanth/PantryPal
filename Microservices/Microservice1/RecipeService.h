#ifndef ADVANCED_RECIPE_SERVICE
#define ADVANCED_RECIPE_SERVICE

#include <curl/curl.h>
#include <string>
#include "Recipe.h"
#include "json.hpp"

using namespace std;

using json = nlohmann::json;

class RecipeService {
public:
    vector<Recipe> findRecipesByIngredients(const vector<string>& ingredients, int number=100, 
                                        bool ignorePantry=true, int ranking=1);

private:
    CURL* curl_;
    static size_t write_callback(char* ptr, size_t size, size_t nmemb, string* userdata);
    json makeRequest(string& url);
    void getRecipeInformation(Recipe& recipe);
    json readFile(string fileName);
};   

#endif