#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_AGGMETHODS_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_AGGMETHODS_H

#include "continental/fuzzy/export.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace definition {

/**
 * Tipo de agregação para as regras Fuzzy. Processo que representa as saidas das regras Fuzzy em um único conjunto.
 */
enum class AggMethods
{
    //Soma dos conjuntos de saída das regras. Utilizado quando o ControllerType é Sugeno
    sum = 1,

    //Indefinido
    none = 2
};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_AGGMETHODS_H
