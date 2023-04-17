#include "Recipe.h"
#include <stdexcept>

Recipe::Recipe(string name, vector<string> ingredients, int servings,
        float prep_time, float cook_time, float total_time, string url):
        name(name), ingredients(ingredients), servings(servings), prep_time(prep_time),
        cook_time(cook_time), total_time(total_time), url(url) {}

vector<string> Recipe::getIngredients() const {
    return ingredients;
}

string Recipe::getName() const {
    return name; 
}

int Recipe::getServings() const {
    return servings;
}

float Recipe::getPrepTime() const {
    return prep_time;
}

float Recipe::getCookTime() const {
    return cook_time;
}

float Recipe::getTotalTime() const {
    return total_time;
}

string Recipe::getUrl() const {
    return url;
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

void Recipe::setPrepTime(float prepTime) {
    if (prepTime <= 0) 
        throw invalid_argument("Please enter a valid prep time");
    prep_time = prepTime;
}

void Recipe::setCookTime(float cookTime) {
    if (cookTime <= 0) 
        throw invalid_argument("Please enter a valid cook time");
    cook_time = cookTime;
}

void Recipe::setTotalTime(float totalTime) {
    if (totalTime <= 0) 
        throw invalid_argument("Please enter a valid total time");
    total_time = prep_time + cook_time;
}

void Recipe::setURL(string url) {
    this->url = url;
}
