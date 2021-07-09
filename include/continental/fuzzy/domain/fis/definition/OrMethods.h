#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_ORMETHODS_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_ORMETHODS_H

#include "continental/fuzzy/export.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace definition {

/**
 * Conector OR utilizado nas regras Fuzzy.
 */
enum class OrMethods
{
    //Máximo, utilizado quando o ControllerType é Mandani
    max = 1,

    //Probabilistico, quando o ControllerType é Sugeno
    probor = 2,

    //Indefinido
    none = 3
};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_ORMETHODS_H
