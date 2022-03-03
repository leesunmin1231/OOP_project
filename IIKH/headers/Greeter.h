#ifndef Greeter_h
#define Greeter_h

#include <iostream>
#include "RecipeDatabase.h"
#include "PlanManager.h"

class Greeter {

private:
    RecipeDatabase& recipeDatabase;
    PlanManager& planManager;
    
    void showRecipeManagerMenu();
    void showPlanManagerMenu();

public:
    Greeter(RecipeDatabase& recipeDatabase_, PlanManager& planManager_) : recipeDatabase(recipeDatabase_), planManager(planManager_) {};
    void showWelcome();
    void showMenu();
};

#endif /* Greeter_h */
