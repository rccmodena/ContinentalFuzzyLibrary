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
    virtual void createFromFisSystem(domain::fis::System p_system) = 0;

    virtual double calcSingleValue(const std::vector<double> &v_inputs, bool useDictFaciesAssociation) = 0;
};

}
}
}
}

#endif //CONTINENTAFUZZY_SERVICE_FUZZY_ABSTRACTFUZZYCONTROLLERSERVICE_H
