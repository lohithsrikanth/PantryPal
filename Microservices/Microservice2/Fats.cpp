#include "Fats.h"

Fats::Fats(double value) : value(value) {}

double Fats::getAmount() const {
    return value;
}

// map<string, double> Fats::calculateNutritionalValue() {
//     double caloriesInFats = value * 9;
//     return {{"FatsInGrams", value}, {"CaloriesInFats", caloriesInFats}};
// }

double Fats::calculateCalories() {
    return value * 9;
}