#ifndef ADVANCED_PROTEINS
#define ADVANCED_PROTEINS

#include <string>
#include "Nutrients.h"

using namespace std;

class Proteins : public Nutrients {
public:
    explicit Proteins(double amountInGrams);
    string getName() const override;
    double getAmount() const override;
    double calculateCalories() override;

private:
    double amountInGrams;
};

#endif