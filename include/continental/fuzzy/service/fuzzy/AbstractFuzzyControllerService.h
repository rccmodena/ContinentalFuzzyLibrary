#ifndef CONTINENTAFUZZY_SERVICE_FUZZY_ABSTRACTFUZZYCONTROLLERSERVICE_H
#define CONTINENTAFUZZY_SERVICE_FUZZY_ABSTRACTFUZZYCONTROLLERSERVICE_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/System.h"
#include <vector>

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {

class CONTINENTALFUZZY_EXPORT_DECL AbstractFuzzyControllerService
{

public:
    /// Construtor.
    AbstractFuzzyControllerService();

    void createFromFisSystem(continental::fuzzy::domain::fis::System p_system);

    double calcSingleValue(std::vector<double> v_inputs, bool useDictFaciesAssociation);
};

}
}
}
}

#endif //CONTINENTAFUZZY_SERVICE_FUZZY_ABSTRACTFUZZYCONTROLLERSERVICE_H
