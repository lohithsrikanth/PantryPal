#ifndef ADVANCED_CARBOHYDRATES
#define ADVANCED_CARBOHYDRATES

#include <map>
#include "Nutrients.h"

using namespace std;

class Carbohydrates : public Nutrients {
public:
    explicit Carbohydrates(double value);
    double getAmount() const override;
    // map<string, double> calculateNutritionalValue() override;
    double calculateCalories() override;

private:
    double value;
};

#endif