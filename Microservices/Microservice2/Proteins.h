#ifndef ADVANCED_PROTEINS
#define ADVANCED_PROTEINS

#include <map>
#include "Nutrients.h"

using namespace std;

class Proteins : public Nutrients {
public:
    explicit Proteins(double amountInGrams);
    double getAmount() const override;
    double calculateCalories() override;

private:
    double amountInGrams;
};

#endif