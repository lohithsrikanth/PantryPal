#ifndef ADVANCED_NUTRITIONAL_INFO
#define ADVANCED_NUTRITIONAL_INFO

#include <map>
#include <vector>
#include <string>
#include <memory>
#include "Nutrients.h"
#include "Fats.h"
#include "Proteins.h"
#include "Carbohydrates.h"
#include "json.hpp"
#include "../Common/Request.h"

using json = nlohmann::json;

using namespace std;

class NutritionalInfo : private Request {
public:
    void addNutrient(Nutrients* nutrient);

    json getNutritionalInfo(int id);
    vector<Nutrients*> getNutrients();
    double calculateTotalNutritionalValue() const;
    ~NutritionalInfo();

private:
    vector<Nutrients*> nutrients;
    
    int extractAmount(string value);
};

#endif