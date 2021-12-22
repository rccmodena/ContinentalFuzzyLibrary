#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_BLOCKS_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_BLOCKS_H

#include "continental/fuzzy/export.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace definition {

/**
 * Bloco do arquivo FIS (Fuzzy Inference System)
 */
enum class Blocks
{
    //Configurações gerais do Fuzzy
    system = 1,

    //Configuração das variáveis de entrada
    inputs = 2,

    //Configurações de uma varíavel de saída Fuzzy (geralmente é apenas uma saída)
    outputs = 3,

    //Conjunto de regras Fuzzy
    rules = 4,

    //Indefinido
    none = 5
};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_DEFINITION_BLOCKS_H
