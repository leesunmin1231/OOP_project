#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "Date.h"
#include "Meal.h"

std::string Date::getDateName() {
    return this->dateName;
}

void Date::setDateName(std::string dateName) {
    // "YYYY-MM-DD"
    std::regex re("\\d{4}-\\d{2}-\\d{2}");
    if (!std::regex_match(dateName, re)) {
        std::cout << "Wrong date format! (YYYY-MM-DD)" << std::endl;
        return;
    }
    this->dateName = dateName;
}

std::vector<Meal> Date::getMeals() {
    return this->meals;
}

void Date::setMeals(std::vector<Meal> meals) {
    this->meals = meals;
}

std::string Date::getAnnotation() {
    return this->annotation;
}

void Date::setAnnotation(std::string annotation) {
    this->annotation = annotation;
}

void Date::showDateMenu() {
    int input;
    
    while (1) {
        std::cout << "===== Date '" << this->dateName << "' =====" << std::endl;
        if (!this->annotation.empty()) {
            std::cout << "(" << this->annotation << ")" << std::endl;
        }
        std::cout << "1. Show meal List" << std::endl;
        std::cout << "2. Create meal" << std::endl;
        std::cout << "3. Edit meal name" << std::endl;
        std::cout << "4. Edit date annotation" << std::endl;
        std::cout << "5. Delete meal" << std::endl;
        std::cout << "6. Browse meal" << std::endl;
        std::cout << "0. Back" << std::endl;
        std::cout << "==============================";
        std::cout << std::endl;
        std::cout << "Select menu: ";
        std::cin >> input;
        
        switch (input) {
            case 1:
                this->showMealList();
                break;
            case 2:
                this->createMeal();
                break;
            case 3:
                this->editMealName();
                break;
            case 4:
                this->editDateAnnotation();
                break;
            case 5:
                this->deleteMeal();
                break;
            case 6:
                this->browseMeal();
                break;
            case 0:
                return;
            default:
                break;
        }
    }
}

void Date::editDateAnnotation() {
    std::string annotation;
    
    std::cin.ignore();
    std::cout << "Enter annotation for this date: ";
    getline(std::cin, annotation, '\n');
    
    this->setAnnotation(annotation);
    
    std::cout << "Annotation changed!" << std::endl;
}

void Date::showMealList() {
    std::cout << "========== Meals in " << this->dateName << " ==========" << std::endl;
    for (int i = 0; i < this->meals.size(); i++) {
        std::cout << i + 1 << ". " << this->meals.at(i).getMealName() << std::endl;
    }
    std::cout << "=========================================" << std::endl;
}

void Date::createMeal() {
    std::string newMealName;
    Meal newMeal = Meal(this->recipeDatabase);
    
    std::cin.ignore();
    std::cout << "Enter new meal name: " << std::endl;
    getline(std::cin, newMealName, '\n');
    
    newMeal.setMealName(newMealName);
    newMeal.setPeople(1);
    this->meals.push_back(newMeal);
    
    std::cout << "New meal created!" << std::endl;
}

void Date::editMealName() {
    int input;
    std::string newName;
    
    std::cout << "Which number of meal do you want to edit? ";
    std::cin >> input;
    
    if (input > this->meals.size()) {
        std::cout << "Meal index out of range!" << std::endl;
        std::cout << "Total meals: " << this->meals.size() << std::endl;
        return;
    }
    
    std::cin.ignore();
    std::cout << "Enter new name: ";
    getline(std::cin, newName, '\n');
    
    this->meals.at(input - 1).setMealName(newName);
    
    std::cout << "Meal name changed!" << std::endl;
}

void Date::deleteMeal() {
    int input;
    
    std::cout << "Which number of meal do you want to delete? ";
    std::cin >> input;
    
    if (input > this->meals.size()) {
        std::cout << "Meal index out of range!" << std::endl;
        std::cout << "Total meals: " << this->meals.size() << std::endl;
        return;
    }
    
    this->meals.erase(this->meals.begin() + input - 1);
    
    std::cout << "Meal deleted!" << std::endl;
}

void Date::browseMeal() {
    int input;
    
    std::cout << "Which number of meal do you want to browse? ";
    std::cin >> input;
    
    if (input > this->meals.size()) {
        std::cout << "Meal index out of range!" << std::endl;
        std::cout << "Total meals: " << this->meals.size() << std::endl;
        return;
    }
    
    this->meals.at(input - 1).showMealMenu();
}

void Date::printGroceryList() {
    std::cout << "========== Grocery list in " << this->dateName << " ==========" << std::endl;
    for (Meal meal : this->meals) {
        meal.printGroceryList();
    }
    std::cout << "================================================" << std::endl;
}
