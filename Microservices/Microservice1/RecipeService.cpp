#include "RecipeService.h"
#include <string>
#include "json.hpp"
#include <stdexcept>
#include <fstream>
#include <iostream>

using json = nlohmann::json;
using namespace std;

json RecipeService::readFile(string fileName) {
    ifstream file(fileName);

    json jsonData;
    file >> jsonData;
    return jsonData;
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
