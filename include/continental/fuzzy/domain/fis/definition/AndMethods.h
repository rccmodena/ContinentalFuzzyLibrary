#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_ANDMETHODS_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_ANDMETHODS_H

#include "continental/fuzzy/export.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace definition {

/**
 * Conector lógico AND utilizado nas regras Fuzzy.
 */
enum class AndMethods
{
    //Mínimo, utilizado quando o ControllerType é Mandani
    min = 1,

    //Produto, utilizado quando o ControllerType é Sugeno
    prod = 2,

    //Indefinido
    none = 3
};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_ANDMETHODS_H
