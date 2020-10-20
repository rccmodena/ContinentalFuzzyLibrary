#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_CONTROLLERTYPE_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_CONTROLLERTYPE_H

#include "continental/fuzzy/export.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace definition {

enum class ControllerType
{
    sugeno = 1,
    mamdani = 2,
    none = 3
};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_CONTROLLERTYPE_H
