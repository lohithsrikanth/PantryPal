#include "Recipe.h"
#include <stdexcept>

Recipe::Recipe() {}

Recipe::Recipe(int id, string name, vector<string> ingredients, int servings, string url) :
        id(id), name(name), ingredients(ingredients), servings(servings), url(url) {}

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

void Recipe::setURL(string url) {
    this->url = url;
}
