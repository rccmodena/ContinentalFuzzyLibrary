#ifndef CONTINENTAFUZZY_SERVICE_FUZZY_SUGENOCONTROLLERSERVICE_H
#define CONTINENTAFUZZY_SERVICE_FUZZY_SUGENOCONTROLLERSERVICE_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fuzzy/SugenoController.h"
#include "continental/fuzzy/domain/fis/Rule.h"
#include "continental/fuzzy/domain/fis/System.h"
#include "continental/fuzzy/domain/fis/MembershipFunction.h"
#include <vector>

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {

class CONTINENTALFUZZY_EXPORT_DECL SugenoControllerService
{

public:
    /// Construtor.
    SugenoControllerService();

    continental::fuzzy::domain::fuzzy::SugenoController getSugenoController() const;

private:
    continental::fuzzy::domain::fuzzy::SugenoController m_sugenoController;

    void getConnection(continental::fuzzy::domain::fis::Rule p_rule);

    void getMFFunction(continental::fuzzy::domain::fis::MembershipFunction p_membershipFunction);

    double executeCalcInputFunctions(double inputValue,
                                     size_t indexInput,
                                     size_t indexMemberFunction);

    double executeCalcOutputFunctions(continental::fuzzy::domain::fis::definition::OutputFunctions p_outputFunction, std::vector<double> valueOfPoint);

    void createFromFisSystem(continental::fuzzy::domain::fis::System p_system);

    std::vector<double> calcRuleWeights();

    std::vector<double> calcRuleOutputLevel(std::vector<double> v_inputs);

    std::vector<double> calcRuleFiring(std::vector<double> v_inputs);

    void sugenoCalcSingleValue(std::vector<double> v_inputs);
};

}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_SUGENOCONTROLLERSERVICE_H
