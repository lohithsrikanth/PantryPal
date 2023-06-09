#include "Recipe.h"
#include <stdexcept>

vector<string> Recipe::getIngredients() const {
    return ingredients;
}

int Recipe::getId() const {
    return id;
}

string Recipe::getName() const {
    return name;
}

int Recipe::getServings() const {
    return servings;
}

int Recipe::getCookTime() const {
    return cookTime;
}

string Recipe::getUrl() const {
    return url;
}

void Recipe::setId(int id) {
    this->id = id;
}

void Recipe::setName(string name) {
    this->name = name;
}

void Recipe::setIngredients(vector<string> ingredients) {
    if (ingredients.size() == 0) 
        throw invalid_argument("Please input some ingredients");
    this->ingredients = ingredients;
}

void Recipe::addIngredient(string ingredient) {
    ingredients.push_back(ingredient);
}

void Recipe::setServings(int servings) {
    if (servings <= 0) 
        throw invalid_argument("Please enter a positive number of servings");
    this->servings = servings;
}

void Recipe::setCookTime(int cookTime) {
    if (cookTime <= 0) 
        throw invalid_argument("Please enter a positive value of cook time");
    this->cookTime = cookTime;
}

void Recipe::setURL(string url) {
    this->url = url;
}
