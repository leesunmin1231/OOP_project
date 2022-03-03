#include <iostream>

#include "Plan.h"
#include "Date.h"


    std::string Plan::getPlanName() {
        return this->planName;
    }

    std::vector<Date> Plan::getDates() {
        return this->dates;
    }

    void Plan::setPlanName(std::string planName) {
        this->planName = planName;
    }

    void Plan::setDates(std::vector<Date> dates) {
        this->dates = dates;
    }


    void Plan::print() {
        std::cout << "================ Dates in" << this->planName << "================" << std::endl;

        for (Date date : this->dates) {
            std::cout << date.getDateName() << std::endl;
        }

        std::cout << "===========================================" << std::endl;




    }


    void Plan::showDateList() {
        std::cout << "====== Date List in " << this->getPlanName() << " ===== " << std::endl;
        for (int i = 0; i < this->dates.size(); i++) {
            std::cout << (i + 1) << ". " << this->dates.at(i).getDateName() << std::endl;
        }
        std::cout << "======================" << std::endl;

    }

    void Plan::createDate() {//플랜에 데이트 만들기

        std::string userInputDateName;

        std::cout << "Enter the name of the new date in form of YYYY-MM-DD" << std::endl;
        std::cin.ignore();
        getline(std::cin, userInputDateName, '\n');

        Date newDate = Date(this->recipeDatabase);
        newDate.setDateName(userInputDateName);

        this->dates.push_back(newDate);
        std::cout << "Date created!" << std::endl;
    }

    void Plan::editDateName() {//데이트 이름 수정

        int userInputDateIndex;
        std::string userInputDateName;

        std::cout << "Which Date?" << std::endl;
        std::cin >> userInputDateIndex;

        std::cout << "Enter the plan name" << std::endl;
        std::cin.ignore();
        getline(std::cin, userInputDateName, '\n');

        Date& targetDate = this->dates.at(userInputDateIndex - 1);
        targetDate.setDateName(userInputDateName);

        std::cout << "Date name changed!" << std::endl;
    }

    void Plan::deleteDate() {//플랜에서 데이트 삭제
        int userInputDateIndex;

        std::cout << "Which date?" << std::endl;
        std::cin >> userInputDateIndex;

        this->dates.erase(this->dates.begin() + userInputDateIndex - 1);

        std::cout << "Date deleted!" << std::endl;
    }

    void Plan::browseDate() {//특정 데이트 선택, 밀로의 접근

        int userInputDateIndex;

        std::cout << "Which date?" << std::endl;
        std::cin >> userInputDateIndex;

        this->dates.at(userInputDateIndex - 1).showDateMenu();

    }

    void Plan::showPlanMenu() {//1. show Date lise 2. create Date, 3. edit date name 4. delete date 5. browse date 6.back
        int input;

        while (1) {

            std::cout << "1. Show list of dates" << std::endl;
            std::cout << "2. Create Date" << std::endl;
            std::cout << "3. Edit date name" << std::endl;
            std::cout << "4. Delete date" << std::endl;
            std::cout << "5. Browse date" << std::endl;
            std::cout << "6. Back" << std::endl;

            std::cout << "Select menu : " << std::endl;
            std::cin >> input;

            switch (input) {
            case 1:
                this->showDateList();
                break;
            case 2:
                this->createDate();
                break;
            case 3:
                this->editDateName();
                break;
            case 4:
                this->deleteDate();
                break;
            case 5:
                this->browseDate();
                break;
            case 6:
                return;
            default:
                std::cout << "Wrong number!" << std::endl;
                break;

            }

        }
    }
