#include "Carbohydrates.h"

Carbohydrates::Carbohydrates(double amountInGrams) : amountInGrams(amountInGrams) {}

double Carbohydrates::getAmount() const {
    return amountInGrams;
}

double Carbohydrates::calculateCalories() {
    return amountInGrams * 4;
}