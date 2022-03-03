#ifndef RecipeDatabase_h
#define RecipeDatabase_h

#include <iostream>
#include <string>
#include <vector>
#include "Recipe.h"
using namespace std;

class RecipeDatabase{
private:
    std::vector<Recipe> recipes;
    
    void showAllRecipes();
    void showSingleRecipe();
    void searchRecipe();
    
    void changeRecipeName(Recipe& recipe);
    void changeIngredients(Recipe& recipe);
    void changePreparationSteps(Recipe& recipe);
    void changePreparationTime(Recipe& recipe);

public:
    RecipeDatabase();
    void browseRecipes();
    void editRecipe();
    void addRecipe();
    void save();
    void deleteRecipe();
    vector<Recipe> getRecipes();
};

#endif /* RecipeDatabase_h */
