#include "NutritionalInfo.h"
#include "../Common/Request.h"

using json = nlohmann::json;

using namespace std;

void NutritionalInfo::addNutrient(Nutrients* nutrient) {
    nutrients.push_back(nutrient);
    //nutrients.push_back(nutrient);
}

// json NutritionalInfo::getNutritionalInfo(int id) {
//     Request request;
//     string url = "https://spoonacular-recipe-food-nutrition-v1.p.rapidapi.com/recipes/" + to_string(id) + "/nutritionWidget.json?";
//     json responseJson = request.makeRequest(url);
//     return responseJson;
// }

double NutritionalInfo::calculateTotalNutritionalValue() const {
    double totalCalories;
    for (const auto& nutrient : nutrients) {
        totalCalories += nutrient->calculateCalories();
    }
    return totalCalories;
}

vector<Nutrients*> NutritionalInfo::getNutrients() {
    return nutrients;
}