#ifndef ADVANCED_NUTRITIONAL_INFO
#define ADVANCED_NUTRITIONAL_INFO

#include <map>
#include <vector>
#include <string>
#include <memory>
#include "Nutrients.h"
#include "json.hpp"

using json = nlohmann::json;

using namespace std;

class NutritionalInfo {
public:
    void addNutrient(Nutrients* nutrient);

    double calculateTotalNutritionalValue() const;
    json getNutritionalInfo(int id);
    vector<Nutrients*> getNutrients();

private:
    vector<Nutrients*> nutrients;
};

#endif