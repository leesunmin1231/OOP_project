#include "PlanManager.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "RecipeDatabase.h"

PlanManager::PlanManager(RecipeDatabase* recipeDatabase) {
    this->recipeDatabase = recipeDatabase;

    std::string line;
    std::ifstream fin("./plans.txt");

    if (fin.is_open()) {
       
        std::string prevPlanName = "";

        while (getline(fin, line)) {
            int count_line = 0;

            std::string planName;
            std::string dateName;
            std::string annotation;
            std::string mealName;
            std::string people_;
            int people;
            std::vector<std::string> recipeNames;

            std::vector<std::string> parsedLine;
            std::stringstream lineStream(line);

            int count = 0;
            while (lineStream.good()) {

                std::string substr;
                getline(lineStream, substr, ';');

                if (count < 5) {
                    parsedLine.push_back(substr);
                }
                else {//recipe 처리

                    std::stringstream recipeStream(substr);

                    while (recipeStream.good()) {
                        std::string recipeString;
                        getline(recipeStream, recipeString, '|');
                        recipeNames.push_back(recipeString);

                    }

                }

                count++;
            }

            planName = parsedLine.at(0);
            dateName = parsedLine.at(1);
            annotation = parsedLine.at(2);
            mealName = parsedLine.at(3);
            people = std::stoi(parsedLine.at(4));
    
            

            if (this->plans.size() == 0) {
                //플랜, 데이트, 밀, 다 생성
                Meal meal = Meal(this->recipeDatabase);
                meal.setMealName(mealName);
                meal.setPeople(people);

                std::vector<Recipe> recipes;
                for (int i = 0; i < this->recipeDatabase->getRecipes().size(); i++) {
                    for (int j = 0; j < recipeNames.size(); j++) {
                        if (recipeNames.at(j) == this->recipeDatabase->getRecipes().at(i).getRecipeName()) {
                            recipes.push_back(this->recipeDatabase->getRecipes().at(i));
                        }
                    }
                }
                meal.setRecipes(recipes);

                std::vector<Meal> meals;
                meals.push_back(meal);

                Date date = Date(this->recipeDatabase);
                date.setAnnotation(annotation);
                date.setDateName(dateName);
                date.setMeals(meals);

                std::vector<Date> dates;
                dates.push_back(date);

                Plan plan = Plan(this->recipeDatabase);
                plan.setPlanName(planName);
                plan.setDates(dates);

                std::vector<Plan> plans = getPlans();
                plans.push_back(plan);

                this->setPlans(plans);
                


            }
            else {
               
                for (int i = 0; i < this->plans.size(); i++) {
                    if (planName == this->plans.at(i).getPlanName()) {
                        
                        if (this->plans.at(i).getDates().size() == 0) {
                           
                            Meal meal = Meal(this->recipeDatabase);
                            meal.setMealName(mealName);
                            meal.setPeople(people);

                            std::vector<Recipe> recipes;
                            for (int i = 0; i < this->recipeDatabase->getRecipes().size(); i++) {
                                for (int j = 0; j < recipeNames.size(); j++) {
                                    if (recipeNames.at(j) == this->recipeDatabase->getRecipes().at(i).getRecipeName()) {
                                        recipes.push_back(this->recipeDatabase->getRecipes().at(i));
                                    }
                                }
                            }
                            meal.setRecipes(recipes);

                            std::vector<Meal> meals;
                            meals.push_back(meal);

                            Date date = Date(this->recipeDatabase);
                            date.setAnnotation(annotation);
                            date.setDateName(dateName);
                            date.setMeals(meals);

                            std::vector<Date> dates;
                            dates = plans.at(i).getDates();
                            dates.push_back(date);
                            this->plans.at(i).setDates(dates);

                        }
                        else {
                           
                            for (int j = 0; j < this->plans.at(i).getDates().size(); j++) {
                                if (dateName == this->plans.at(i).getDates().at(j).getDateName()) {
                                  
                                    if (this->plans.at(i).getDates().at(j).getMeals().size() == 0) {
                                        
                                        Meal meal = Meal(this->recipeDatabase);
                                        meal.setMealName(mealName);
                                        meal.setPeople(people);

                                        std::vector<Recipe> recipes;
                                        for (int i = 0; i < this->recipeDatabase->getRecipes().size(); i++) {
                                            for (int j = 0; j < recipeNames.size(); j++) {
                                                if (recipeNames.at(j) == this->recipeDatabase->getRecipes().at(i).getRecipeName()) {
                                                    recipes.push_back(this->recipeDatabase->getRecipes().at(i));
                                                }
                                            }
                                        }
                                        meal.setRecipes(recipes);

                                        std::vector<Meal> meals;
                                        meals.push_back(meal);
                                        this->plans.at(i).getDates().at(j).setMeals(meals);
                                    }
                                    else {
                                       
                                        Meal meal = Meal(this->recipeDatabase);
                                        meal.setMealName(mealName);
                                        meal.setPeople(people);

                                        std::vector<Recipe> recipes;
                                        for (int i = 0; i < this->recipeDatabase->getRecipes().size(); i++) {
                                            for (int j = 0; j < recipeNames.size(); j++) {
                                                if (recipeNames.at(j) == this->recipeDatabase->getRecipes().at(i).getRecipeName()) {
                                                    recipes.push_back(this->recipeDatabase->getRecipes().at(i));
                                                }
                                            }
                                        }
                                        meal.setRecipes(recipes);

                                        std::vector<Meal> meals;
                                        meals.push_back(meal);
                                        this->plans.at(i).getDates().at(j).setMeals(meals);

                                    }

                                }
                                else {
                                    
                                    Meal meal = Meal(this->recipeDatabase);
                                    meal.setMealName(mealName);
                                    meal.setPeople(people);

                                    std::vector<Recipe> recipes;
                                    for (int i = 0; i < this->recipeDatabase->getRecipes().size(); i++) {
                                        for (int j = 0; j < recipeNames.size(); j++) {
                                            if (recipeNames.at(j) == this->recipeDatabase->getRecipes().at(i).getRecipeName()) {
                                                recipes.push_back(this->recipeDatabase->getRecipes().at(i));
                                            }
                                        }
                                    }
                                    meal.setRecipes(recipes);

                                    std::vector<Meal> meals;
                                    meals.push_back(meal);

                                    Date date = Date(this->recipeDatabase);
                                    date.setAnnotation(annotation);
                                    date.setDateName(dateName);
                                    date.setMeals(meals);

                                    std::vector<Date> dates;
                                    dates = this->plans.at(i).getDates();
                                    dates.push_back(date);
                                    this->plans.at(i).setDates(dates);
                                }
                            }

                        }
                    }
                    else {
                       
                        Meal meal = Meal(this->recipeDatabase);
                        meal.setMealName(mealName);
                        meal.setPeople(people);

                        std::vector<Recipe> recipes;
                        for (int i = 0; i < this->recipeDatabase->getRecipes().size(); i++) {
                            for (int j = 0; j < recipeNames.size(); j++) {
                                if (recipeNames.at(j) == this->recipeDatabase->getRecipes().at(i).getRecipeName()) {
                                    recipes.push_back(this->recipeDatabase->getRecipes().at(i));
                                }
                            }
                        }
                        meal.setRecipes(recipes);

                        std::vector<Meal> meals;
                        meals.push_back(meal);

                        Date date = Date(this->recipeDatabase);
                        date.setAnnotation(annotation);
                        date.setDateName(dateName);
                        date.setMeals(meals);

                        std::vector<Date> dates;
                        dates.push_back(date);

                        Plan plan = Plan(this->recipeDatabase);
                        plan.setPlanName(planName);
                        plan.setDates(dates);

                        std::vector<Plan> plans = getPlans();
                        plans.push_back(plan);
                        
                        this->setPlans(plans);
                        

                    }
                }
            }



        }
    }


}


void PlanManager::setPlans(std::vector<Plan> plans) {
    this->plans = plans;
}

std::vector<Plan> PlanManager::getPlans() {
    return this->plans;

}
void PlanManager::save() {
    std::ofstream fout("./plans.txt");

    if (fout.fail()) {
        std::cout << "File not found: plans.txt" << std::endl;
        std::cout << "Cannot save plan database!" << std::endl;
        return;
    }

    for (Plan plan : this->plans) {
        for (Date date : plan.getDates()) {
            for (Meal meal : date.getMeals()) {

                std::string line;
                line.append(plan.getPlanName());
                line.append(";");
                line.append(date.getDateName());
                line.append(";");
                line.append(date.getAnnotation());
                line.append(";");
                line.append(meal.getMealName());
                line.append(";");
                line.append(std::to_string(meal.getPeople()));
                line.append(";");
                for (int i = 0; i < meal.getRecipes().size(); i++) {
                    line.append(meal.getRecipes().at(i).getRecipeName());
                    if (i != meal.getRecipes().size() - 1)
                        line.append("|");
                    line.append("\n");
                    fout << line;
                }
            }
        }


    }

    fout.close();
}

    void PlanManager::showPlanList() {//플랜 리스트 보여주기

        std::cout << "====== Plan List =====" << std::endl;
        for (int i = 0; i < this->plans.size(); i++) {
            std::cout << (i + 1) << ". " << this->plans.at(i).getPlanName() << std::endl;
        }
        std::cout << "======================" << std::endl;

    }

    void PlanManager::createPlan() {//새로운 플랜 생성
        std::string userInputPlanName;

        std::cout << "Enter the name of the new plan" << std::endl;
        std::cin.ignore();
        getline(std::cin, userInputPlanName, '\n');

        Plan newPlan = Plan(this->recipeDatabase);
        newPlan.setPlanName(userInputPlanName);

        this->plans.push_back(newPlan);

        std::cout << "Plan created!" << std::endl;

    }

    void PlanManager::editPlanName() {
        int userInputPlanIndex;
        std::string userInputPlanName;

        std::cout << "Which plan?" << std::endl;
        std::cin >> userInputPlanIndex;

        std::cout << "Enter the plan name" << std::endl;
        std::cin.ignore();
        getline(std::cin, userInputPlanName, '\n');

        Plan& targetPlan = this->plans.at(userInputPlanIndex - 1);
        targetPlan.setPlanName(userInputPlanName);

        std::cout << "Plan name changed!" << std::endl;

    }

    void PlanManager::deletePlan() {//플랜 삭제

        int userInputPlanIndex;

        std::cout << "Which plan?" << std::endl;
        std::cin >> userInputPlanIndex;

        this->plans.erase(this->plans.begin() + userInputPlanIndex - 1);

        std::cout << "Plan deleted!" << std::endl;

    }

    void PlanManager::browsePlan() {//특정 플랜 선택, 데이트로의 접근
        int userInputPlanIndex;

        std::cout << "Which plan?" << std::endl;
        std::cin >> userInputPlanIndex;

        this->plans.at(userInputPlanIndex - 1).showPlanMenu();

    }


