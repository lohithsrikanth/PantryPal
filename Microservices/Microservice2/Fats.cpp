#include "Fats.h"

Fats::Fats(double value) : amountInGrams(amountInGrams) {}

double Fats::getAmount() const {
    return amountInGrams;
}

double Fats::calculateCalories() {
    return amountInGrams * 9;
}