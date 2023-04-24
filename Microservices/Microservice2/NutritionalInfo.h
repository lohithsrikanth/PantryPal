#ifndef ADVANCED_NUTRITIONAL_INFO
#define ADVANCED_NUTRITIONAL_INFO

#include <map>
#include <vector>
#include <string>
#include <memory>
#include "Nutrients.h"
#include "json.hpp"
#include "../Common/Request.h"

using json = nlohmann::json;

using namespace std;

class NutritionalInfo : public Request {
public:
    void addNutrient(Nutrients* nutrient);

    json getNutritionalInfo(int id);
    vector<Nutrients*> getNutrients();
    double calculateTotalNutritionalValue() const;

private:
    vector<Nutrients*> nutrients;
    
    int extractAmount(string value);
};

#endif