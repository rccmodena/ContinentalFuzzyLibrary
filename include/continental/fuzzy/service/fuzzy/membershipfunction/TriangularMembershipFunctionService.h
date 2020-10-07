/*
* Developed by UNISINOS - Projeto Continentais and Petrobras
* author: Rudi C. C. Modena
* email: rmodena@unisinos.br
* date: October, 2020
*/
#ifndef CONTINENTAL_FUZZY_SERVICE_FUZZY_MEMBERSHIPFUNCTION_TRIANGULARMEMBERSHIPFUNCTIONSERVICE_H
#define CONTINENTAL_FUZZY_SERVICE_FUZZY_MEMBERSHIPFUNCTION_TRIANGULARMEMBERSHIPFUNCTIONSERVICE_H

#include "continental/fuzzy/export.h"

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace membershipfunction {


class CONTINENTALFUZZY_EXPORT_DECL TriangularMembershipFunctionService
{

public:
    /// Construtor.
    TriangularMembershipFunctionService();

    /// Destrutor.
    ~TriangularMembershipFunctionService();

    static double calculeTriangularMf(double xValue, double pointA, double pointB, double pointC);
};

}
}
}
}
}

#endif CONTINENTAL_FUZZY_SERVICE_FUZZY_MEMBERSHIPFUNCTION_TRIANGULARMEMBERSHIPFUNCTIONSERVICE_H
