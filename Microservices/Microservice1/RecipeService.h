#ifndef ADVANCED_RECIPE_SERVICE
#define ADVANCED_RECIPE_SERVICE

#include <curl/curl.h>
#include <string>
#include "Recipe.h"
#include "json.hpp"
#include "../Common/Request.h"

using namespace std;

using json = nlohmann::json;

class RecipeService : private Request {
public:
    vector<Recipe> findRecipesByIngredients(const vector<string>& ingredients, int number=100, 
                                        bool ignorePantry=true, int ranking=1);

private:
    void getRecipeInformation(Recipe& recipe);
    json readFile(string fileName);
    
};   

#endif