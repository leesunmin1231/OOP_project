#include <iostream>
#include <string>
#include <vector>

#include "Meal.h"


std::string Meal::getMealName() {
    return this->mealName;
}

void Meal::setMealName(std::string mealName) {
    this->mealName = mealName;
}
std::vector<Recipe> Meal::getRecipes() {
    return this->recipes;
}

void Meal::setRecipes(std::vector<Recipe> recipes) {
    this->recipes = recipes;
}

int Meal::getPeople() {
    return this->people;
}

void Meal::setPeople(int people) {
    this->people = people;
}



void Meal::print() {
    std::cout << this->mealName << std::endl;
}

void Meal::showMealMenu() {
    int input;
    while (1) {
        std::cout << std::endl << "===== Meal Menu =====" << std::endl;
        std::cout << "1. Show recipe list" << std::endl;
        std::cout << "2. Add new Recipe" << std::endl;
        std::cout << "3. Print Grocery list of this meal" << std::endl;
        std::cout << "4. Delete Recipe" << std::endl;
        std::cout << "5. Edit People" << std::endl;
        std::cout << "0. Back" << std::endl;
        std::cout << "=====================" << std::endl << std::endl;

        std::cout << "Select menu: ";
        std::cin >> input;

        switch (input) {
        case 1:
            this->ShowRecipeList();
            break;
        case 2:
            this->addRecipe();
            break;
        case 3:
            this->printGroceryList();
            break;
        case 4:
            this->DeleteRecipe();
            break;
        case 5:
            this->EditPeople ();
            break;
        case 0:
            return;
        default:
            break;
        }
    }
}

void Meal::printGroceryList() { // Output the name of the recipe and the ingredients used in the recipe.   
    std::cout << std::endl << "Ingredients for " << this->people << " people." << std::endl << std::endl;
    std::cout << "===== Grocery List =====" << std::endl;
    for (int i = 0; i < this->recipes.size(); i++) {
        std::vector<std::string> grocery = this->recipes.at(i).getIngredients();
        std::cout << i + 1 << ". " << this->recipes.at(i).getRecipeName() << " : " << std::endl;
        std::cout << "[";

        for (int j = 1; j <= ((grocery.size() + 1) / 2); j++) {
            int amount = std::stoi(grocery.at(j * 2 - 1));
            std::cout << grocery.at(j * 2 - 2) << ": " << amount*this->people<< "g ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "========================" << std::endl;
}

void Meal::addRecipe() { 
    int input;
    std::vector<Recipe> recipeList = this->recipeDatabase->getRecipes();

    // It shows the list of recipes in the recipe database.
    std::cout <<std::endl << "===== Recipe List =====" << std::endl;
    for (int i = 0; i < recipeList.size(); i++) {
        std::cout << i + 1 << ". " << recipeList.at(i).getRecipeName() << std::endl;
    }

    // Receive a recipe number from the user.
    std::cout << "=======================" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter the number of recipe you want to add: ";
    std::cin >> input;

    if (input > recipeList.size()) {
        std::cout << "Recipe index out of range!" << std::endl;
        std::cout << "Total number of recipes: " << recipeList.size() << std::endl;
        return;
    }
    // add a new recipe to the recipe vector.
    this->recipes.push_back(recipeList.at(input - 1));

    std::cout << "Recipe added!" << std::endl;
}

void Meal::DeleteRecipe() {
    int input;

    std::cout << std::endl << "Which number of recipe do you want to delete? ";
    std::cin >> input;

    if (input > this->recipes.size()) {
        std::cout << "Recipe index out of range!" << std::endl;
        std::cout << "Total number of recipes: " << this->recipes.size() << std::endl;
        return;
    }

    this->recipes.erase(this->recipes.begin() + input - 1);

    std::cout << "Recipe deleted!" << std::endl;
}


void Meal::ShowRecipeList() {
    std::cout <<std::endl << "========== " << this->mealName << " ==========" << std::endl;
    for (int i = 0; i < this->recipes.size(); i++) {
        std::cout << i + 1 << ". " << this->recipes.at(i).getRecipeName() << std::endl;
    }
    std::cout << "==============================" << std::endl;
}

void Meal::EditPeople() {
    int input;
    std::cout << std::endl<< "How many people are attending the meal? ";
    std::cin >> input;
    this->people = input;
    std::cout << "Complete!" << std::endl;
}