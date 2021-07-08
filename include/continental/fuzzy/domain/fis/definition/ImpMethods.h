#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_IMPMETHODS_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_IMPMETHODS_H

#include "continental/fuzzy/export.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace definition {

/**
 * Tipo de implicação para calcular o conjunto de regras Fuzzy.
 */
enum class ImpMethods
{
    //Dimensiona a função de associação consequente pelo valor do resultado antecedente. É o método padrão quando o ControllerType é Sugeno
    prod = 1,

    //Indefinido
    none = 2
};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_IMPMETHODS_H
