#include "RecipeService.h"
#include <string>
#include "json.hpp"
#include <stdexcept>

using json = nlohmann::json;

RecipeService::RecipeService() {
    curl_global_init(CURL_GLOBAL_ALL);
    curl_ = curl_easy_init();
    if (!curl_) {
        throw runtime_error("Failed to initialize libcurl");
    }
}

RecipeService::~RecipeService() {
    curl_easy_cleanup(curl_);
    curl_global_cleanup();
}

json RecipeService::makeRequest(string& url) {
    string response;
    curl_easy_setopt(curl_, CURLOPT_URL, url.c_str());
    curl_slist* headers = nullptr;
    
    headers = curl_slist_append(headers, "X-RapidAPI-Key: YOUR_API_KEY");
    headers = curl_slist_append(headers, "X-RapidAPI-Host: spoonacular-recipe-food-nutrition-v1.p.rapidapi.com");
    curl_easy_setopt(curl_, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &response);
    
    CURLcode res = curl_easy_perform(curl_);
    
    if (res != CURLE_OK) {
        throw runtime_error(curl_easy_strerror(res));
    }

    json responseJson = json::parse(response);
    return responseJson;
}

vector<Recipe> RecipeService::findRecipesByIngredients(const vector<string> ingredients, int number=5, bool ignorePantry=false, int ranking=0) {
    string url = "https://spoonacular-recipe-food-nutrition-v1.p.rapidapi.com/recipes/findByIngredients?ingredients=";
    for (int i = 0; i < ingredients.size(); i++) {
        url += ingredients[i];
        if (i < ingredients.size() - 1) {
            url += ",";
        }
    }
    url += "&number=" + std::to_string(number) + "&ignorePantry=" + (ignorePantry ? "true" : "false") + "&ranking=" + std::to_string(ranking);
    json responseJson = makeRequest(url);
    std::vector<Recipe> recipes;
    for (const auto& recipeJson : responseJson) {
        Recipe recipe;
        recipe.setName(recipeJson["title"]);
        // recipe.setURL(recipeJson["sourceUrl"]);
        // recipe.setServings(recipeJson["servings"]);
        for (const auto& ingredientJson : recipeJson["usedIngredients"]) {
            recipe.addIngredient(ingredientJson["name"]);
        }
        recipes.push_back(recipe);
    }
    return recipes;
}

void RecipeService::getRecipeInformation(Recipe& recipe) {
    string url = "https://spoonacular-recipe-food-nutrition";
}
