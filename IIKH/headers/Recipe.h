#ifndef Recipe_h
#define Recipe_h

#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Recipe{
private:
    std::string recipeName;
    std::vector<string> ingredients;
    std::vector<string> preparationSteps;
    int preparationTime;

public:
    Recipe(std::string recipeName);
    Recipe(std::string recipeName, std::vector<string> ingredients, std::vector<string> preparationSteps, int preparationTime);
    string getRecipeName();
    vector<string> getIngredients();
    vector<string> getPreparationSteps();
    int getPreparationTime();
    void setRecipeName(std::string recipeName);
    void setIngredients(std::vector<string> ingredients);
    void setPrearationSteps(std::vector<string> preparationSteps);
    void setPreparationTime(int preparationTime);
    void print();

};

#endif /* Recipe_h */
