#ifndef ADVANCED_RECIPE
#define ADVANCED_RECIPE

#include <string>
#include <vector>

using namespace std;

class Recipe {
private:
    int id;
    string name;
    vector<string> ingredients;
    int servings;
    string url;

public:
    Recipe() = default;
    Recipe(int id, string name, vector<string> ingredients, int servings, string url);
    
    int getId() const;
    string getName() const;
    vector<string> getIngredients() const;
    int getServings() const;
    string getUrl() const;
    
    void setId(int id);
    void setName(string name);
    void setIngredients(vector<string> ingredients);
    void addIngredient(string ingredient);
    void setServings(int servings);
    void setURL(string url);
};

#endif