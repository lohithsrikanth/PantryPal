#ifndef ADVANCED_NUTRIENTS
#define ADVANCED_NUTRIENTS

#include <map>
#include <vector>
#include <string>

using namespace std;

class Nutrients {
public:
    //virtual map<string, double> calculateNutritionalValue() = 0;
    virtual double getAmount() const = 0;
    virtual double calculateCalories() = 0;
    virtual ~Nutrients();
};


#endif