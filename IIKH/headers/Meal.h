#ifndef Meal_h
#define Meal_h

#include <string>
#include <vector>

#include "Recipe.h"
#include "RecipeDatabase.h"

class Meal {
private:
    RecipeDatabase* recipeDatabase;
    std::string mealName;
    std::vector<Recipe> recipes;
    int people;

public:
    Meal(RecipeDatabase* recipeDatabase_) : recipeDatabase(recipeDatabase_) {}; //constructor
    // mealName getter,setter
    std::string getMealName();
    void setMealName(std::string mealName);
    // recipes list getter,setter
    std::vector<Recipe> getRecipes();
    void setRecipes(std::vector<Recipe> recipes);
    // people getter setter
    int getPeople();
    void setPeople(int people);

    void print();
    void printGroceryList();
    void showMealMenu();
    void ShowRecipeList();
    void addRecipe();
    void DeleteRecipe();
    void EditPeople();
};

#endif /* Meal_h */
