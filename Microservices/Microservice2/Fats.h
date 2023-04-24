#ifndef ADVANCED_FATS
#define ADVANCED_FATS

#include <map>
#include "Nutrients.h"

using namespace std;

class Fats : public Nutrients {
public:
    explicit Fats(double amountInGrams);
    double getAmount() const override;
    double calculateCalories() override;

private:
    double amountInGrams;
};

#endif