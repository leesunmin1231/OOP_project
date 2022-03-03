#ifndef PlanManager_h
#define PlanManager_h

#include <sstream>
#include "Plan.h"
#include "RecipeDatabase.h"

class PlanManager {
private:
    RecipeDatabase* recipeDatabase;
	std::vector<Plan> plans;

public:
    PlanManager(RecipeDatabase* recipeDatabase);

	void setPlans(std::vector<Plan> plans);
	std::vector<Plan> getPlans();
	void save();
	void showPlanList();
	void createPlan();
	void editPlanName();
	void deletePlan();
	void browsePlan();
	
};

#endif /* PlanManager_h */
