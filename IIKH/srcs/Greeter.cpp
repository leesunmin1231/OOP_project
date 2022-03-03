#include "Greeter.h"
#include "RecipeDatabase.h"
#include "PlanManager.h"

void Greeter::showWelcome() {
    std::cout << std::endl;
    std::cout << "========== Welcome to IIKH Program ==========" << std::endl;
    std::cout << "|  Interactive Intelligent Kitchen Helper   |" << std::endl;
    std::cout << "=============================================" << std::endl;
    std::cout << std::endl;
};

void Greeter::showMenu() {
    int input;
    
    while (1) {
        std::cout << "======= Menu =======" << std::endl;
        std::cout << "1. Manage recipes" << std::endl;
        std::cout << "2. Manage plans" << std::endl;
        std::cout << "0. Save & Quit" << std::endl;
        std::cout << "====================" << std::endl;
        std::cout << std::endl;
        std::cout << "Select menu: ";
        std::cin >> input;
        
        switch (input) {
            case 1:
                this->showRecipeManagerMenu();
                break;
            case 2:
                this->showPlanManagerMenu();
                break;
            case 0:
                this->recipeDatabase.save();
                this->planManager.save();
                return;
            default:
                std::cout << "Wrong number!" << std::endl;
                break;
        }
    }
}

void Greeter::showRecipeManagerMenu() {
    int input;
    
    while (1) {
        std::cout << "===== Recipe Manager =====" << std::endl;
        std::cout << "1. Browse recipes" << std::endl;
        std::cout << "2. Create recipe" << std::endl;
        std::cout << "3. Edit recipe" << std::endl;
        std::cout << "4. Delete recipe" << std::endl;
        std::cout << "0. Back" << std::endl;
        std::cout << "==========================" << std::endl;
        std::cout << std::endl;
        std::cout << "Select menu: ";
        std::cin >> input;
        
        switch (input) {
            case 1:
                this->recipeDatabase.browseRecipes();
                break;
            case 2:
                this->recipeDatabase.addRecipe();
                break;
            case 3:
                this->recipeDatabase.editRecipe();
                break;
            case 4:
                this->recipeDatabase.deleteRecipe();
                break;
            case 0:
                return;
            default:
                std::cout << "Wrong number!" << std::endl;
                break;
        }
    }
    
}

void Greeter::showPlanManagerMenu() {
    int input;
    
    while (1) {
        std::cout << "===== Plan Manager =====" << std::endl;
        std::cout << "1. Show plan list" << std::endl;      // ls
        std::cout << "2. Create plan" << std::endl;             // mkdir
        std::cout << "3. Edit plan name" << std::endl;
        std::cout << "4. Delete plan" << std::endl;             // rmdir
        std::cout << "5. Browse plan" << std::endl;             // cd
        std::cout << "0. Back" << std::endl;
        std::cout << "========================" << std::endl;
        std::cout << std::endl;
        std::cout << "Select menu: ";
        std::cin >> input;
        
        switch (input) {
            case 1:
                this->planManager.showPlanList();
                break;
            case 2:
                this->planManager.createPlan();
                break;
            case 3:
                this->planManager.editPlanName();
                break;
            case 4:
                this->planManager.deletePlan();
                break;
            case 5:
                this->planManager.browsePlan();
            case 0:
                return;
            default:
                std::cout << "Wrong number!" << std::endl;
                break;
        }
    }
    
}
