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
    /// Média ponderada de todos os outputs das regras. Método padrão utilizado quando o ControllerType é Sugeno
    /// Weighted average of all rule outputs
    wtaver = 1,

    /// Soma ponderada de todos os outputs das regras
    /// Weighted sum of all rule outputs
    wtsum = 2,

    /// Regra de maior valor de todos os outputs das regras
    winner = 3,

    /// Indefinido
    none = 4
};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_DEFUZZMETHODS_H
