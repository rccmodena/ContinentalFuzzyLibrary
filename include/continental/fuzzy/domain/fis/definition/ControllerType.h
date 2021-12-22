#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_CONTROLLERTYPE_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_CONTROLLERTYPE_H

#include "continental/fuzzy/export.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace definition {

/**
 * Tipo de sistema de inferência a ser utilizado no Fuzzy.
 */
enum class ControllerType
{
    // Sistema Fuzzy do tipo Sugeno
    sugeno = 1,

    //Sistema Fuzzy do tipo Mamdani
    mamdani = 2,

    //Indefinido
    none = 3
};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_CONTROLLERTYPE_H
