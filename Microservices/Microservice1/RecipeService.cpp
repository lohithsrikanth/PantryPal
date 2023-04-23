#include "RecipeService.h"
#include <string>
#include "json.hpp"
#include <stdexcept>
#include <fstream>
#include <iostream>

using json = nlohmann::json;
using namespace std;

size_t RecipeService::write_callback(char* ptr, size_t size, size_t nmemb, string* userdata) {
    userdata->append(ptr, size * nmemb);
    return size * nmemb;
}

json RecipeService::readFile(string fileName) {
    ifstream file(fileName);

    json jsonData;
    file >> jsonData;
    return jsonData;
}

json RecipeService::makeRequest(string& url) {
    string response;
    CURL *curl_ = curl_easy_init();

    curl_easy_setopt(curl_, CURLOPT_CUSTOMREQUEST, "GET");
    curl_easy_setopt(curl_, CURLOPT_URL, url.c_str());
    curl_slist* headers = nullptr;
    
<<<<<<< HEAD
=======
    headers = curl_slist_append(headers, "X-RapidAPI-Key: 7ba169ddc1msh262f271b67b1d7cp1c6d27jsn5557275e88f3");
    headers = curl_slist_append(headers, "X-RapidAPI-Host: spoonacular-recipe-food-nutrition-v1.p.rapidapi.com");
>>>>>>> 865ed6ffcdc595c21565f88fa9189d50ca86550c
    curl_easy_setopt(curl_, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &response);
    
    CURLcode res = curl_easy_perform(curl_);
    
    if (res != CURLE_OK) {
        throw runtime_error(curl_easy_strerror(res));
    }

    curl_easy_cleanup(curl_);
    curl_slist_free_all(headers);

    json responseJson = json::parse(response);
    return responseJson;
}

vector<Recipe> RecipeService::findRecipesByIngredients(const vector<string>& ingredients, int number, bool ignorePantry, int ranking) {
    string url = "https://spoonacular-recipe-food-nutrition-v1.p.rapidapi.com/recipes/findByIngredients?ingredients=";
    for (int i = 0; i < ingredients.size(); i++) {
        url += ingredients[i];
        if (i < ingredients.size() - 1) {
            url += ",";
        }
    }
    url += "&number=" + std::to_string(number) + "&ignorePantry=" + (ignorePantry ? "true" : "false") + "&ranking=" + std::to_string(ranking);
    json responseJson = makeRequest(url);
    // json responseJson = readFile("output.json");
    vector<Recipe> recipes;
    int count = 0;
    for (const auto& recipeJson : responseJson) {
        // only include recipes that have the missedIngredientCount as 0

        if (recipeJson["missedIngredientCount"] == 0) {
            Recipe recipe;
            recipe.setId(recipeJson["id"]);
            recipe.setName(recipeJson["title"]);
            getRecipeInformation(recipe);
            recipes.push_back(recipe);
            ++count;
        }
        // Recipe recipe;
        // recipe.setId(recipeJson["id"]);
        // recipe.setName(recipeJson["title"]);
        // getRecipeInformation(recipe);
        // recipes.push_back(recipe);
        // count++;
        
    }
    return recipes;
}

void RecipeService::getRecipeInformation(Recipe& recipe) {
    string url = "https://spoonacular-recipe-food-nutrition-v1.p.rapidapi.com/recipes/" + to_string(recipe.getId()) + "/information";
    json responseJson = makeRequest(url);
    //json responseJson = readFile("recipe_info.json");
    recipe.setName(responseJson["title"]);
    recipe.setServings(responseJson["servings"]);
    recipe.setCookTime(responseJson["readyInMinutes"]);
    recipe.setURL(responseJson["sourceUrl"]);
    for (const auto& ingredientJson : responseJson["extendedIngredients"]) {
        recipe.addIngredient(ingredientJson["name"]);
    }
}
