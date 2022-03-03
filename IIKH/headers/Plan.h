#ifndef Plan_h
#define Plan_h

#include <string>
#include <vector>

#include "Date.h"

class Plan {

private:
	std::string planName;
	std::vector<Date> dates;
	RecipeDatabase* recipeDatabase;

public:
	Plan(RecipeDatabase* recipeDatabase_) : recipeDatabase(recipeDatabase_) {};


	std::vector<Date> getDates();
	std::string getPlanName();
	void setPlanName(std::string planName);
	void setDates(std::vector<Date> dates);
	void print();
	void showDateList();
	void createDate();
	void editDateName();
	void deleteDate();
	void browseDate();
	void showPlanMenu();


};

#endif /* Plan_h */
