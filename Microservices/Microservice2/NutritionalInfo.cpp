#include "NutritionalInfo.h"
#include "Fats.h"
#include "Proteins.h"
#include "Carbohydrates.h"

using json = nlohmann::json;

using namespace std;

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

void NutritionalInfo::addNutrient(Nutrients* nutrient) {
    nutrients.push_back(nutrient);
}

json NutritionalInfo::getNutritionalInfo(int id) {
    string url = "https://spoonacular-recipe-food-nutrition-v1.p.rapidapi.com/recipes/" + to_string(id) + "/nutritionWidget.json?";
    json responseJson = makeRequest(url);
    json myResponse;    
    
    auto fats = new Fats(extractAmount(responseJson["fat"]));
    addNutrient(fats);

    auto proteins = new Proteins(extractAmount(responseJson["protein"]));
    addNutrient(proteins);

    auto carbs = new Carbohydrates(extractAmount(responseJson["carbs"]));
    addNutrient(carbs);

    double totalCalories = calculateTotalNutritionalValue();
    myResponse["totalCalories"] = totalCalories;

    for (const auto& nutrient: getNutrients()) {
        if (nutrient->getName() == "Fats") {
            myResponse["FatInGrams"] = nutrient->getAmount();
            myResponse["FatCalories"] = nutrient->calculateCalories();
        } 
        else if (nutrient->getName() == "Proteins") {
            myResponse["ProteinInGrams"] = nutrient->getAmount();
            myResponse["ProteinCalories"] = nutrient->calculateCalories();
        }
        else if (nutrient->getName() == "Carbohydrates") {
            myResponse["CarbsInGrams"] = nutrient->getAmount();
            myResponse["CarbsCalories"] = nutrient->calculateCalories();
        }
    }

    // Deallocate memory
    delete fats;
    delete proteins;
    delete carbs;

    // Return my JSON response
    return myResponse;
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