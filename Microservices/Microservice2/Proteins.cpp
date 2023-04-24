#include "Proteins.h"

Proteins::Proteins(double value) : value(value) {}

double Proteins::getAmount() const {
    return value;
}

// map<string, double> Proteins::calculateNutritionalValue() {
//     double caloriesInProteins = value * 4;
//     return {{"ProteinsInGrams", value}, {"CaloriesInProteins", caloriesInProteins}};
// }

double Proteins::calculateCalories() {
    return value * 4;
}