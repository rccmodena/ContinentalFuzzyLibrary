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

    void createFromFisSystem(const domain::fis::System &p_system) override;

    double calcSingleValue(std::vector<double> v_inputs) override;

    domain::fuzzy::SugenoController& getSugenoController();

    const domain::fuzzy::SugenoController& getSugenoController() const;
private:
    domain::fuzzy::SugenoController m_sugenoController;

    double getResultConnection(const domain::fis::Rule &p_rule, const std::vector<double> &listTempInput);

    double executeCalcInputFunctions(
            const double inputValue,
            const size_t indexInput,
            const size_t indexMemberFunction
        );

    double executeCalcOutputFunctions(
            const std::vector<double> &valueOfPoint,
            size_t indexMemberFunction
    );

    std::vector<double> calcRuleWeights();

    std::vector<double> calcRuleOutputLevel(const std::vector<double> &v_inputs);

    std::vector<double> calcRuleFiring(const std::vector<double> &v_inputs);
};

}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_SUGENOCONTROLLERSERVICE_H
