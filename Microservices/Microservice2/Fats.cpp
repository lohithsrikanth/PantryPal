#include "Fats.h"

Fats::Fats(double amountInGrams) : amountInGrams(amountInGrams) {}

string Fats::getName() const {
    return "Fats";
}

double Fats::getAmount() const {
    return amountInGrams;
}

double Fats::calculateCalories() {
    return amountInGrams * 9;
}