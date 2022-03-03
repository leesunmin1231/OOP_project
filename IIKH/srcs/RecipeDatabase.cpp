#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "RecipeDatabase.h"

RecipeDatabase::RecipeDatabase() {
    // TODO: 생성자에서는 "./recipes.txt" 파일을 읽어와서 파일 내용을 파싱해서 this->recipes 를 채워주세요.
    // 파일 형식은 다음과 같이 저장하도록 했습니다.
    // 레시피이름1;재료1|재료2|재료3;과정1|과정2|과정3;걸리는시간
    // 레시피이름2;재료1|재료2;     과정1|과정2|과정3;걸리는시간
    // ...
    std::string line;

    std::ifstream fin("./recipes.txt");

    if (fin.is_open()) {
        while (getline(fin, line)) {
            std::string recipeName;
            std::vector<std::string> ingredients;
            std::vector<std::string> preparationSteps;
            int preparationTime;

            std::vector<std::string> parsedLine;
            std::stringstream lineStream(line);

            while (lineStream.good()) {
                std::string substr;
                getline(lineStream, substr, ';');
                parsedLine.push_back(substr);
            }

            recipeName = parsedLine.at(0);

            std::stringstream ingredientsStream(parsedLine.at(1));
            while (ingredientsStream.good()) {
                std::string substr;
                getline(ingredientsStream, substr, '|');
                ingredients.push_back(substr);
            }

            std::stringstream preparationStepsStream(parsedLine.at(2));
            while (preparationStepsStream.good()) {
                std::string substr;
                getline(preparationStepsStream, substr, '|');
                preparationSteps.push_back(substr);
            }

            preparationTime = std::stoi(parsedLine.at(3));

            Recipe recipe(recipeName, ingredients, preparationSteps, preparationTime);
            this->recipes.push_back(recipe);
        }
        fin.close();
    }
    else {
        std::cout << "Failed to open recipes file.";
        return;
    }
};

void RecipeDatabase::browseRecipes() {
    int input;

    while (1) {
        std::cout << "===== Recipe Browser =====" << std::endl;
        std::cout << "1. Show all recipes" << std::endl;
        std::cout << "2. Show single recipe" << std::endl;
        std::cout << "3. Search recipe" << std::endl;
        std::cout << "0. Back" << std::endl;
        std::cout << "==========================" << std::endl;

        std::cin >> input;

        switch (input) {
        case 1:
            this->showAllRecipes();
            break;
        case 2:
            this->showSingleRecipe();
            break;
        case 3:
            this->searchRecipe();
            break;
        case 0:
            return;
        default:
            std::cout << "Wrong number!" << std::endl;
            break;
        }
    }
};

void RecipeDatabase::showAllRecipes() {
    std::cout << "===== Recipe List =====" << std::endl;
    for (int i = 0; i < this->recipes.size(); i++) {
        std::cout << i + 1 << ". " << this->recipes.at(i).getRecipeName() << std::endl;
    }
    std::cout << "=======================" << std::endl;
}

void RecipeDatabase::showSingleRecipe() {
    int input;

    std::cout << "Enter the number of recipe you want to see: ";
    std::cin >> input;

    if (input > this->recipes.size()) {
        std::cout << "Recipe index out of range!" << std::endl;
        std::cout << "Total number of recipes: " << this->recipes.size() << std::endl;
        return;
    }

    this->recipes.at(input - 1).print();
}

void RecipeDatabase::searchRecipe() {
    std::string input;
    std::vector<int> resultIndex;

    std::cin.ignore();
std:cout << "Enter keyword to search: ";
    getline(std::cin, input, '\n');

    for (int i = 0; i < this->recipes.size(); i++) {
        if (this->recipes.at(i).getRecipeName().find(input) != std::string::npos) {
            resultIndex.push_back(i);
        }
    }

    if (resultIndex.size() != 0) {
        std::cout << "===== Search Result =====" << std::endl;
        for (int i : resultIndex) {
            std::cout << i + 1 << ". " << this->recipes.at(i).getRecipeName() << std::endl;
        }
        std::cout << "=========================" << std::endl;
    }
    else {
        std::cout << "===== No Matching result! =====" << std::endl;
    }
}

void RecipeDatabase::editRecipe() {
    int input;

    std::cout << "Enter the number of recipe you want to edit: ";
    std::cin >> input;

    if (input > this->recipes.size()) {
        std::cout << "Recipe index out of range!" << std::endl;
        std::cout << "Total number of recipes: " << this->recipes.size() << std::endl;
        return;
    }

    Recipe& targetRecipe = this->recipes.at(input - 1);

    while (1) {
        std::cout << "===== Edit Recipe: " << targetRecipe.getRecipeName() << " =====" << std::endl;
        std::cout << "1. Change recipe name" << std::endl;
        std::cout << "2. Change ingredient" << std::endl;
        std::cout << "3. Change preparation steps" << std::endl;
        std::cout << "4. Change preparation time" << std::endl;
        std::cout << "5. Back" << std::endl;
        std::cout << "=====================================" << std::endl;

        std::cin >> input;

        switch (input) {
        case 1:
            this->changeRecipeName(targetRecipe);
            break;
        case 2:
            this->changeIngredients(targetRecipe);
            break;
        case 3:
            this->changePreparationSteps(targetRecipe);
            break;
        case 4:
            this->changePreparationTime(targetRecipe);
            break;
        case 5:
            return;
        default:
            std::cout << "Wrong number!" << std::endl;
            break;
        }
    }
};

void RecipeDatabase::changeRecipeName(Recipe& recipe) {
    // TODO: 파라미터로 받은 Recipe 레퍼런스의 이름을 대화식으로 변경합니다.
    // "Enter new recipe name: "
    // (Carrot Juice)
    // "Recipe name has been changed!"
    string newRecipeName;

    std::cin.ignore();
    std::cout << ("Enter new recipe name: ");
    getline(std::cin, newRecipeName, '\n');
    recipe.setRecipeName(newRecipeName);
    std::cout << ("Recipe name has been changed!") << endl;
}

void RecipeDatabase::changeIngredients(Recipe& recipe) {
    // TODO: 파라미터로 받은 Recipe 레퍼런스의 ingredient 를 대화식으로 변경합니다.
    // "Enter the number of ingredient you want to edit"
    // (2)
    // "2. Water (100g)"
    // "Change to what? (name, amount) "
    // (Milk, 200)
    // "'Water (100g)' has been changed to 'Milk (200g)'!"
    int ingredientNumber;
    std::string ingredientName;
    int ingredientAmount;

    std::cout << "Enter the number of ingredient you want to edit: ";
    std::cin >> ingredientNumber;

    std::vector<std::string> prevIngredients = recipe.getIngredients();
    ingredientName = prevIngredients.at(ingredientNumber * 2 - 2);
    ingredientAmount = std::stoi(prevIngredients.at(ingredientNumber * 2 - 1));

    std::cout << ingredientName << "(" << ingredientAmount << ")" << std::endl;

    std::string newIngredientName;
    std::cin.ignore();
    std::cout << "Change ingredient name to what?" << std::endl;
    getline(std::cin, newIngredientName, '\n');

    std::string newIngredientAmountString;
    std::cout << "Change ingredient amount to what?" << std::endl;
    getline(std::cin, newIngredientAmountString, '\n');

    prevIngredients.at(ingredientNumber * 2 - 2) = newIngredientName;
    prevIngredients.at(ingredientNumber * 2 - 1) = newIngredientAmountString;

    recipe.setIngredients(prevIngredients);
    std::cout << "Changed!" << std::endl;
}

void RecipeDatabase::changePreparationSteps(Recipe& recipe) {
    // TODO: 파라미터로 받은 Recipe 레퍼런스의 step 을 대화식으로 변경합니다.
    // "Enter the number of step you want to edit"
    // (1)
    // "1. Blend apple"
    // "Change to what?"
    // (Blend carrot)
    // "'Blend apple' has been changed to 'Blend carrot'!"
    int index_preparationStep;
    vector<string> preparationSteps = recipe.getPreparationSteps();
    string newPreparationStep;
    string before;

    std::cout << ("Enter the number of step you want to edit: ");
    std::cin >> index_preparationStep;
    before = preparationSteps[index_preparationStep - 1];
    std::cout << index_preparationStep << (". ") << preparationSteps[index_preparationStep - 1] << endl;
    std::cin.ignore();
    std::cout << ("Change to what? ");
    getline(std::cin, newPreparationStep, '\n');
    preparationSteps[index_preparationStep - 1] = newPreparationStep;
    recipe.setPrearationSteps(preparationSteps);
    std::cout << ("'") << before << ("' has been changed to '") << preparationSteps[index_preparationStep - 1]
        << ("'!") << endl;

}

void RecipeDatabase::changePreparationTime(Recipe& recipe) {
    // TODO: 파라미터로 받은 Recipe 레퍼런스의 준비 시간을 대화식으로 변경합니다.
    // "Enter new preparation time: "
    // (5)
    // "Preparation time has been changed!"
    int newpreparationTime;
    std::cout << ("Enter new preparation time: ");
    std::cin >> newpreparationTime;
    recipe.setPreparationTime(newpreparationTime);
    std::cout << ("Preparation time has been changed!");
}

void RecipeDatabase::addRecipe() {
    // TODO: 이 부분 구현이 안되어있네요.
    string recipeName;
    vector<string> ingredients;
    vector<string> preparationSteps;
    int preparationTime;

    std::cout << ("Insert recipe name: ");
    std::cin.ignore();
    getline(std::cin, recipeName, '\n');

    std::string input;
    std::cout << ("insert ingredients: (stop:0)\n");
    while (1) {
        getline(std::cin, input, '\n');

        if (input == "0") {
            break;
        }

        std::stringstream instream(input);
        while (instream.good()) {
            std::string substr;
            getline(instream, substr, ',');
            ingredients.push_back(substr);
        }
    }

    std::cout << ("insert preparation steps: (stop:0)\n");
    while (1) {
        getline(std::cin, input, '\n');

        if (input == "0") {
            break;
        }

        preparationSteps.push_back(input);
    }

    std::cout << ("insert preparation time: ");
    std::cin >> preparationTime;

    Recipe newRecipe = Recipe(recipeName, ingredients, preparationSteps, preparationTime);

    recipes.push_back(newRecipe);
}

void RecipeDatabase::save() {
    ofstream fout("./recipes.txt");
    if (fout.fail()) {
        std::cout << "File not found: recipes.txt" << std::endl;
        std::cout << "Cannot save recipe database!" << std::endl;
        return;
    }

    for (Recipe recipe : this->recipes) {
        std::string line = "";
        std::string recipeName = recipe.getRecipeName();
        std::vector<std::string> ingredients = recipe.getIngredients();
        std::vector<std::string> preparationSteps = recipe.getPreparationSteps();
        int preparationTime = recipe.getPreparationTime();

        line.append(recipeName);
        line.append(";");
        for (int i = 0; i < ingredients.size(); i++) {
            line.append(ingredients.at(i));
            if (i != ingredients.size() - 1) {
                line.append("|");
            }
        }
        line.append(";");
        for (int i = 0; i < preparationSteps.size(); i++) {
            line.append(preparationSteps.at(i));
            if (i != preparationSteps.size() - 1) {
                line.append("|");
            }
        }
        line.append(";");
        line.append(std::to_string(preparationTime));
        line.append("\n");
        fout << line;
    }
    fout.close();
};

void RecipeDatabase::deleteRecipe() {
    int input;

    std::cout << "Enter the number of recipe you want to delete: ";
    std::cin >> input;

    if (input > this->recipes.size()) {
        std::cout << "Recipe index out of range!" << std::endl;
        std::cout << "Total number of recipes: " << this->recipes.size() << std::endl;
        return;
    }

    this->recipes.erase(this->recipes.begin() + input - 1);

    std::cout << "Recipe deleted!" << std::endl;
}

vector<Recipe> RecipeDatabase::getRecipes() {
    return this->recipes;
};

