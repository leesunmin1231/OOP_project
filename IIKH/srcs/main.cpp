#include <iostream>
#include "Greeter.h"
#include "RecipeDatabase.h"
#include "PlanManager.h"

int main() {
    RecipeDatabase recipeDatabase = RecipeDatabase();
    PlanManager planManager = PlanManager(&recipeDatabase);
    
    Greeter greeter = Greeter(recipeDatabase, planManager);
    
    greeter.showWelcome();
    greeter.showMenu();
    
    return 0;
}
