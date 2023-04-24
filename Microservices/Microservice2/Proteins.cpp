#include "Proteins.h"

Proteins::Proteins(double value) : amountInGrams(amountInGrams) {}

double Proteins::getAmount() const {
    return amountInGrams;
}

double Proteins::calculateCalories() {
    return amountInGrams * 4;
}