#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_DEFUZZMETHODS_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_DEFUZZMETHODS_H

#include "continental/fuzzy/export.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace definition {

/**
 * Tipo de defuzzificação, utilizado para calcular um único valor de saída como resultado das regras Fuzzy.
 */
enum class DefuzzMethods
{
    //Média ponderada de todos os outputs das regras. Método padrão utilizado quando o ControllerType é Sugeno
    wtaver = 1,

    //Soma ponderada de todos os outputs das regras
    wtsum = 2,

    //Indefinido
    none = 3
};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_DEFUZZMETHODS_H
