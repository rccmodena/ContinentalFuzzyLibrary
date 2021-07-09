#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITIONS_VARIABLETYPE_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITIONS_VARIABLETYPE_H

#include "continental/fuzzy/export.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace definition {

/**
 * Tipo de variável utilizada nas regras de condição SE/ENTÃO do Fuzzy.
 * Exemplo: SE <antecedente> ENTÃO <conseqüente>.
 */
enum class VariableType
{
    //Variável do tipo antecedente, é a variável que possui condições que quando satisfeitas determinam as variévaies consequentes
    antecedent = 1,

    //Variável do tipo consequente, que é gerada pela ação das regras Fuzzy
    consequent = 2
};

}
}
}
}
}

#endif //CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITIONS_VARIABLETYPE_H
