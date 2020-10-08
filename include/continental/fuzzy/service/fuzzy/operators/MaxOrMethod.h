/*
* Developed by UNISINOS - Projeto Continentais and Petrobras
* author: Rudi C. C. Modena
* email: rmodena@unisinos.br
* date: October, 2020
*/
#ifndef CONTINENTAL_FUZZY_SERVICE_FUZZY_OPERATORS_MAXORMETHOD_H
#define CONTINENTAL_FUZZY_SERVICE_FUZZY_OPERATORS_MAXORMETHOD_H

#include "continental/fuzzy/export.h"
#include <vector>

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace operators {


class CONTINENTALFUZZY_EXPORT_DECL MaxOrMethod
{

public:
    /// Construtor.
    MaxOrMethod();

    /// Destrutor.
    ~MaxOrMethod();

    static double calculeMaxOrMethod(std::vector<double> valuesVector);
};

}
}
}
}
}

#endif CONTINENTAL_FUZZY_SERVICE_FUZZY_OPERATORS_MAXORMETHOD_H
