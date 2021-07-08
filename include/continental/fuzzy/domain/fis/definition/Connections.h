#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_CONNECTIONS_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_CONNECTIONS_H

#include "continental/fuzzy/export.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace definition {

/**
 * Tipo de operadores que conectam as regras Fuzzy.
 */
enum class Connections
{
    //Junção de duas regras (Conjunção)
    AND = 1,

    // Disjunção de duas regras
    OR = 2,

    //Indefinido
    none = 3
};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_CONNECTIONS_H
