#ifndef ADVANCED_PROTEINS
#define ADVANCED_PROTEINS

#include <map>
#include "Nutrients.h"

using namespace std;

class Proteins : public Nutrients {
public:
    explicit Proteins(double value);
    double getAmount() const override;
    // map<string, double> calculateNutritionalValue() override;
    double calculateCalories() override;

private:
    double value;
};

#endif