#include "NutritionalInfo.h"

using json = nlohmann::json;

using namespace std;

void NutritionalInfo::addNutrient(Nutrients* nutrient) {
    nutrients.push_back(nutrient);
}

json NutritionalInfo::getNutritionalInfo(int id) {
    string url = "https://spoonacular-recipe-food-nutrition-v1.p.rapidapi.com/recipes/" + to_string(id) + "/nutritionWidget.json?";
    json responseJson = makeRequest(url);
    json myResponse;    
    return responseJson;
}

int NutritionalInfo::extractAmount(string value) {
    string numStr;
    for (const auto& c : value) {
        if (isdigit(c)) {
            numStr += c;
        } else {
            break;
        }
    } 

    return stoi(numStr);
}

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