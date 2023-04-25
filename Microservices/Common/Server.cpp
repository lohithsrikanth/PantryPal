#include "Server.h"
#include "json.hpp"

using json = nlohmann::json;

using namespace std;

Server::Server() : app_{}, recipeService_{} {}

void Server::start() {
    CROW_ROUTE(app_, "/recipes").methods("POST"_method)([&](const crow::request& req) {
        // Parse request body to get the list of ingredients
        json requestJson = json::parse(req.body);
        vector<string> ingredients = requestJson["ingredients"].get<vector<string>>();

        // Get recipes based on the ingredients
        vector<Recipe> recipes = recipeService_.findRecipesByIngredients(ingredients);
        
        // Build response JSON
        json responseJson;
        for (const auto& recipe: recipes) {
            json recipeJson;
            recipeJson["id"] = recipe.getId();
            recipeJson["name"] = recipe.getName();
            recipeJson["servings"] = recipe.getServings();
            recipeJson["url"] = recipe.getUrl();
            recipeJson["cookTime"] = recipe.getCookTime();
            responseJson.push_back(recipeJson);
        }

        // Set response content type to JSON
        crow::response response = crow::response(200, responseJson.dump());

        // Set response headers to allow CORS
        response.set_header("Access-Control-Allow-Origin", "*");
        response.set_header("Access-Control-Allow-Headers", "Content-Type");

        return response;
    });

    app_.port(8080).multithreaded().run();
}