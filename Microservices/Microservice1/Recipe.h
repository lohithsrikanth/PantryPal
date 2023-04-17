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
    float prep_time;
    float cook_time;
    float total_time;
    string url;

public:
    Recipe(string name, vector<string> ingredients, int servings,
        float prep_time, float cook_time, float total_time, string url);
    
    vector<string> getIngredients() const;
    int getServings() const;
    float getPrepTime() const;
    float getCookTime() const;
    float getTotalTime() const;
    string getUrl() const;
    
    void setIngredients(vector<string> ingredients);
    void setServings(int servings);
    void setPrepTime(float prepTime);
    void setCookTime(float cookTime);
    void setTotalTime(float totalTime);
    void setURL(string url);
};

#endif