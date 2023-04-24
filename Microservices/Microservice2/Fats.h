#ifndef ADVANCED_FATS
#define ADVANCED_FATS

#include <map>
#include "Nutrients.h"

using namespace std;

class Fats : public Nutrients {
public:
    explicit Fats(double value);
    double getAmount() const override;
    // map<string, double> calculateNutritionalValue() override;
    double calculateCalories() override;

private:
    double value;
};

#endif