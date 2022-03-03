#include <iostream>
#include "Recipe.h"

Recipe::Recipe(std::string recipeName) {
    this->recipeName = recipeName;
}

Recipe::Recipe(std::string recipeName, std::vector<string> ingredients, std::vector<string> preparationSteps, 
    int preparationTime){
    this->recipeName=recipeName;
    this->ingredients=ingredients;
    this->preparationSteps=preparationSteps;
    this->preparationTime=preparationTime;
};

string Recipe::getRecipeName(){
    return this->recipeName;
}

vector<string> Recipe::getIngredients(){
    return this->ingredients;
}

vector<string> Recipe::getPreparationSteps(){
    return this->preparationSteps;
}

int Recipe::getPreparationTime(){
    return this->preparationTime;
}

void Recipe::setRecipeName(std::string recipeName){
    this->recipeName=recipeName;
};

void Recipe::setIngredients(std::vector<string> ingredients){
    this->ingredients=ingredients;
};

void Recipe::setPrearationSteps(std::vector<string> preparationSteps){
    this->preparationSteps=preparationSteps;
};

void Recipe::setPreparationTime(int preparationTime){
    this->preparationTime=preparationTime;
};

void Recipe::print(){
    std::cout << "===== Recipe of " << this->recipeName << " =====" << std::endl;
    std::cout << "Preparation Time: " << this->preparationTime << "min" << std::endl;
    std::cout << "Ingredients: " << std::endl;
    for (int i = 0; i < this->ingredients.size() / 2; i++) {
        int index = i * 2;
        std::cout << i + 1 << ". " << this->ingredients.at(index) << "(" << this->ingredients.at(index + 1) << "g)" << std::endl;
    }
    std::cout << "Preparation Steps: " << std::endl;
    for (int i = 0; i < this->preparationSteps.size(); i++) {
        std::cout << i + 1 << ". " << this->preparationSteps.at(i) << std::endl;
    }
}
