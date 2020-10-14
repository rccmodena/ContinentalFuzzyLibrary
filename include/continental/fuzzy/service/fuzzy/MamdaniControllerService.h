#ifndef CONTINENTAFUZZY_SERVICE_FUZZY_MANDANICONTROLLERSERVICE_H
#define CONTINENTAFUZZY_SERVICE_FUZZY_MANDANICONTROLLERSERVICE_H

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

class CONTINENTALFUZZY_EXPORT_DECL MamdaniControllerService : public AbstractFuzzyControllerService
{
public:
    /// Construtor.
    MamdaniControllerService();

    void createFromFisSystem(continental::fuzzy::domain::fis::System p_system);

    double calcSingleValue(std::vector<double> v_inputs, bool useDictFaciesAssociation);
};

}
}
}
}

#endif //CONTINENTAFUZZY_SERVICE_FUZZY_MANDANICONTROLLERSERVICE_H
