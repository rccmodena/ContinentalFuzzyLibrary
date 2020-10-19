#ifndef CONTINENTAFUZZY_SERVICE_FUZZY_SUGENOCONTROLLERSERVICE_H
#define CONTINENTAFUZZY_SERVICE_FUZZY_SUGENOCONTROLLERSERVICE_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/service/fuzzy/AbstractFuzzyControllerService.h"
#include "continental/fuzzy/domain/fuzzy/SugenoController.h"
#include "continental/fuzzy/domain/fis/Rule.h"
#include "continental/fuzzy/domain/fis/System.h"
#include "continental/fuzzy/domain/fis/MembershipFunction.h"
#include <vector>

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {

class CONTINENTALFUZZY_EXPORT_DECL SugenoControllerService : public AbstractFuzzyControllerService
{

public:
    /// Construtor.
    SugenoControllerService();

    void createFromFisSystem(continental::fuzzy::domain::fis::System p_system);

    double calcSingleValue(std::vector<double> v_inputs, bool useDictFaciesAssociation);

private:
    continental::fuzzy::domain::fuzzy::SugenoController m_sugenoController;

    double getResultConnection(continental::fuzzy::domain::fis::Rule p_rule, std::vector<double> listTempInput);

    double executeCalcInputFunctions(
            double inputValue,
            size_t indexInput,
            size_t indexMemberFunction
    );

    double executeCalcOutputFunctions(
            std::vector<double> valueOfPoint,
            size_t indexMemberFunction
    );

    continental::fuzzy::domain::fuzzy::SugenoController getSugenoController() const;

    std::vector<double> calcRuleWeights();

    std::vector<double> calcRuleOutputLevel(std::vector<double> v_inputs);

    std::vector<double> calcRuleFiring(std::vector<double> v_inputs);
};

}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_SUGENOCONTROLLERSERVICE_H
