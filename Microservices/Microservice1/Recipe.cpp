#include "Recipe.h"
#include <stdexcept>

Recipe::Recipe(string name, vector<string> ingredients, int servings, string url):
        name(name), ingredients(ingredients), servings(servings), url(url) {}

vector<string> Recipe::getIngredients() const {
    return ingredients;
}

string Recipe::getName() const {
    return name; 
}

int Recipe::getServings() const {
    return servings;
}

string Recipe::getUrl() const {
    return url;
}

void Recipe::setName(string name) {
    this->name = name;
}

void Recipe::setIngredients(vector<string> ingredients) {
    if (ingredients.size() == 0) 
        throw invalid_argument("Please input some ingredients");
    this->ingredients = ingredients;
}

void Recipe::setServings(int servings) {
    if (servings <= 0) 
        throw invalid_argument("Please enter a positive number of servings");
    this->servings = servings;
}

void Recipe::setURL(string url) {
    this->url = url;
}
