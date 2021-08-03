#include "continental/fuzzy/service/fuzzy/membershipfunction/GaussMembershipFunctionService.h"
#include <cmath>

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace membershipfunction {
double GaussMembershipFunctionService::calculeGaussMf(const double xValue, const double mean, const double sigma)
{
    // Retorna o valor de y de uma curva gaussiana utilizando a média e o desvio padrão informados.
    return std::exp((-(xValue - mean) * (xValue - mean)) / (2.0 * sigma * sigma));
}

}
}
}
}
}
