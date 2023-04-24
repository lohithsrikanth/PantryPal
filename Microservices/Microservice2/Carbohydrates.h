#ifndef ADVANCED_CARBOHYDRATES
#define ADVANCED_CARBOHYDRATES

#include <string>
#include "Nutrients.h"

using namespace std;

class Carbohydrates : public Nutrients {
public:
    explicit Carbohydrates(double amountInGrams);
    string getName() const override;
    double getAmount() const override;
    double calculateCalories() override;

private:
    double amountInGrams;
};

#endif