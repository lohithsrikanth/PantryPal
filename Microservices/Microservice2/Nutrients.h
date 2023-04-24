#ifndef ADVANCED_NUTRIENTS
#define ADVANCED_NUTRIENTS

#include <map>
#include <vector>
#include <string>

using namespace std;

class Nutrients {
public:
    virtual string getName() const = 0;
    virtual double getAmount() const = 0;
    virtual double calculateCalories() = 0;
    virtual ~Nutrients();
};


#endif