#include "Carbohydrates.h"

Carbohydrates::Carbohydrates(double value) : value(value) {}

double Carbohydrates::getAmount() const {
    return value;
}

// map<string, double> Carbohydrates::calculateNutritionalValue() {
//     double caloriesInCarbs = value * 4;
//     return {{"CarbsInGrams", value}, {"CaloriesInCarbs", caloriesInCarbs}};
// }

double Carbohydrates::calculateCalories() {
    return value * 4;
}