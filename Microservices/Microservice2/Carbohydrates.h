#ifndef ADVANCED_CARBOHYDRATES
#define ADVANCED_CARBOHYDRATES

#include <map>
#include "Nutrients.h"

using namespace std;

class Carbohydrates : public Nutrients {
public:
    explicit Carbohydrates(double amountInGrams);
    double getAmount() const override;
    double calculateCalories() override;

private:
    double amountInGrams;
};

#endif