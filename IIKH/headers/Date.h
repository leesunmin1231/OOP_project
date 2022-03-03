#ifndef Date_h
#define Date_h

#include <string>
#include <vector>

#include "Meal.h"

class Date {
private:
    RecipeDatabase* recipeDatabase;
    std::string dateName;
    std::vector<Meal> meals;
    std::string annotation;
    
    void editDateAnnotation();
    
public:
    Date(RecipeDatabase* recipeDatabase_) : recipeDatabase(recipeDatabase_) {};
    
    std::string getDateName();
    void setDateName(std::string dateName);
    std::vector<Meal> getMeals();
    void setMeals(std::vector<Meal> meals);
    std::string getAnnotation();
    void setAnnotation(std::string annotation);
    
    void printGroceryList();
    
    void showDateMenu();
    void showMealList();
    void createMeal();
    void editMealName();
    void deleteMeal();
    void browseMeal();
};

#endif /* Date_h */
