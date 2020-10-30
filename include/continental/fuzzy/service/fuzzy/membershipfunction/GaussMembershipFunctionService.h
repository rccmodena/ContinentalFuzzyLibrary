/*
* Developed by UNISINOS - Projeto Continentais and Petrobras
* author: Rudi C. C. Modena
* email: rmodena@unisinos.br
* date: October, 2020
*/
#ifndef CONTINENTAL_FUZZY_SERVICE_FUZZY_MEMBERSHIPFUNCTION_GAUSSMEMBERSHIPFUNCTIONSERVICE_H
#define CONTINENTAL_FUZZY_SERVICE_FUZZY_MEMBERSHIPFUNCTION_GAUSSMEMBERSHIPFUNCTIONSERVICE_H

#include "continental/fuzzy/export.h"

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace membershipfunction {


class CONTINENTALFUZZY_EXPORT_DECL GaussMembershipFunctionService
{

public:
    /// Função que calcula a coordena y de uma função de pertinência gaussiana.
    /// @param xValue Valor do eixo x.
    /// @param mean Média para geração da curva de pertinência gaussiana.
    /// @param sigma Desvio Padrão para geração da curva de pertinência gaussiana.
    /// @return Retorna um número do tipo double com a coordenada y da curva de pertinência gaussiana.
    static double calculeGaussMf(const double xValue, const double mean, const double sigma);
};

}
}
}
}
}

#endif CONTINENTAL_FUZZY_SERVICE_FUZZY_MEMBERSHIPFUNCTION_GAUSSMEMBERSHIPFUNCTIONSERVICE_H
