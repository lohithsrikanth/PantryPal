#ifndef ADVANCED_FATS
#define ADVANCED_FATS

#include <string>
#include "Nutrients.h"

using namespace std;

class Fats : public Nutrients {
public:
    explicit Fats(double amountInGrams);
    string getName() const override;
    double getAmount() const override;
    double calculateCalories() override;

private:
    double amountInGrams;
};

#endif