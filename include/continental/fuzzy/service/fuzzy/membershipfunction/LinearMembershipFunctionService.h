/*
* Developed by UNISINOS - Projeto Continentais and Petrobras
* author: Rudi C. C. Modena
* email: rmodena@unisinos.br
* date: October, 2020
*/
#ifndef CONTINENTAL_FUZZY_SERVICE_FUZZY_MEMBERSHIPFUNCTION_LINEARMEMBERSHIPFUNCTIONSERVICE_H
#define CONTINENTAL_FUZZY_SERVICE_FUZZY_MEMBERSHIPFUNCTION_LINEARMEMBERSHIPFUNCTIONSERVICE_H

#include "continental/fuzzy/export.h"
#include <vector>

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace membershipfunction {


class CONTINENTALFUZZY_EXPORT_DECL LinearMembershipFunctionService
{

public:
    /// Construtor.
    LinearMembershipFunctionService();

    /// Destrutor.
    ~LinearMembershipFunctionService();

    static double calculeLinearMembershipFunctionService(std::vector<double> &parameters, std::vector<double> &inputs);
};

}
}
}
}
}

#endif CONTINENTAL_FUZZY_SERVICE_FUZZY_MEMBERSHIPFUNCTION_LINEARMEMBERSHIPFUNCTIONSERVICE_H
