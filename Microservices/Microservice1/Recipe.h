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
    int cookTime;
    string url;

public:
    int getId() const;
    string getName() const;
    vector<string> getIngredients() const;
    int getServings() const;
    int getCookTime() const;
    string getUrl() const;
    
    void setId(int id);
    void setName(string name);
    void setIngredients(vector<string> ingredients);
    void addIngredient(string ingredient);
    void setServings(int servings);
    void setCookTime(int cookTime);
    void setURL(string url);
};

#endif