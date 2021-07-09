#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_OUTPUTFUNCTIONS_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_OUTPUTFUNCTIONS_H

#include "continental/fuzzy/export.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace definition {

/**
 * Tipo da função de saída do Fuzzy.
 */
enum class OutputFunctions
{
    //Função do tipo linear para as saídas do ControllerType Sugeno
    linear = 1,

    //Função do tipo constante para as saídas do ControllerType Sugeno
    constant = 2
};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_OUTPUTFUNCTIONS_H
