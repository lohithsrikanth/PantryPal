#ifndef ADVANCED_SERVER
#define ADVANCED_SERVER

#include "crow_all.h"
#include "../Microservice1/RecipeService.h"
#include "json.hpp"

using json = nlohmann::json;

using namespace std;

class Server {
public:
    Server();

    void start();
private:
    crow::SimpleApp app_;
    RecipeService recipeService_;
};

#endif