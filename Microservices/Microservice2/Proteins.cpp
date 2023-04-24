#include "Proteins.h"

Proteins::Proteins(double value) : amountInGrams(amountInGrams) {}

string Proteins::getName() const {
    return "Proteins";
}

double Proteins::getAmount() const {
    return amountInGrams;
}

double Proteins::calculateCalories() {
    return amountInGrams * 4;
}