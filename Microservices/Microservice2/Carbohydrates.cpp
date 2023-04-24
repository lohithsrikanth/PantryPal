#include "Carbohydrates.h"

Carbohydrates::Carbohydrates(double amountInGrams) : amountInGrams(amountInGrams) {}

string Carbohydrates::getName() const {
    return "Carbohydrates";
}

double Carbohydrates::getAmount() const {
    return amountInGrams;
}

double Carbohydrates::calculateCalories() {
    return amountInGrams * 4;
}