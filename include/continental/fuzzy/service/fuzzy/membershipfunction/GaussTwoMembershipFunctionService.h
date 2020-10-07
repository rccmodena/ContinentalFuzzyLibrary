/*
* Developed by UNISINOS - Projeto Continentais and Petrobras
* author: Rudi C. C. Modena
* email: rmodena@unisinos.br
* date: October, 2020
*/
#ifndef CONTINENTAL_FUZZY_SERVICE_FUZZY_MEMBERSHIPFUNCTION_GAUSSTWOMEMBERSHIPFUNCTIONSERVICE_H
#define CONTINENTAL_FUZZY_SERVICE_FUZZY_MEMBERSHIPFUNCTION_GAUSSTWOMEMBERSHIPFUNCTIONSERVICE_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/service/fuzzy/membershipfunction/GaussMembershipFunctionService.h"

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace membershipfunction {


class CONTINENTALFUZZY_EXPORT_DECL GaussTwoMembershipFunctionService
{

public:
    /// Construtor.
    GaussTwoMembershipFunctionService();

    /// Destrutor.
    ~GaussTwoMembershipFunctionService();

    /// Função que calcula a coordena y de uma função de pertinência combinação de duas curvas gaussianas.
    /// @param xValue Valor do eixo x.
    /// @param meanOne Primeira média para geração da curva de pertinência combinação de duas curvas gaussianas.
    /// @param sigmaOne Primeiro desvio padrão para geração da curva de pertinência combinação de duas curvas gaussianas.
    /// @param meanTwo Segunda média para geração da curva de pertinência combinação de duas curvas gaussianas.
    /// @param sigmaTwo Segundo desvio padrão para geração da curva de pertinência combinação de duas curvas gaussianas.
    /// @return Retorna um número do tipo double com a coordenada y da curva de pertinência combinação de duas curvas gaussianas.
    static double calculeTwoGaussMf(double xValue,
                                    double meanOne,
                                    double sigmaOne,
                                    double meanTwo,
                                    double sigmaTwo);
};

}
}
}
}
}

#endif CONTINENTAL_FUZZY_SERVICE_FUZZY_MEMBERSHIPFUNCTION_GAUSSTWOMEMBERSHIPFUNCTIONSERVICE_H
