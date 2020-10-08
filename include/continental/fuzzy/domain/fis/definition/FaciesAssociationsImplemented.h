#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_FACIESASSOCIATIONSIMPLEMENTED_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_FACIESASSOCIATIONSIMPLEMENTED_H

#include "continental/fuzzy/export.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace definition {

enum class FaciesAssociationsImplemented
{
    Cape = 0,
    ShallowPlain = 1,
    LowEnergyUnderwaterPlain = 2,
    InterpatchesPlain = 3,
    ClayeyEmbayment = 4,
    StromatoliteEmbayment = 5,
    LaminiteRamp = 6,
    ModerateEnergyIntraclastic = 7,
    HighEnergyIntraclastic = 8,
    SubCoastal = 9,
    Reef = 10,
    ClayeyClasticDeposit = 11,
    Undefined = 12
};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_FACIESASSOCIATIONSIMPLEMENTED_H
