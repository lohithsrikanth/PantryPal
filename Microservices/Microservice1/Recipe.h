#ifndef ADVANCED_RECIPE
#define ADVANCED_RECIPE

#include <string>
#include <vector>

using namespace std;

class Recipe {
private:
    string name;
    vector<string> ingredients;
    int servings;
    string url;

public:
    Recipe(string name, vector<string> ingredients, int servings, string url);
    
    string getName() const;
    vector<string> getIngredients() const;
    int getServings() const;
    string getUrl() const;
    
    void setName(string name);
    void setIngredients(vector<string> ingredients);
    void setServings(int servings);
    void setURL(string url);
};

#endif