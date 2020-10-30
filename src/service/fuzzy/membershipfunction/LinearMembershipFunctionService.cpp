#include "continental/fuzzy/service/fuzzy/membershipfunction/LinearMembershipFunctionService.h"

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace membershipfunction {

double LinearMembershipFunctionService::calculeLinearMembershipFunctionService(const std::vector<double> &parameters, const std::vector<double> &inputs)
{
    double result = 0;
    const size_t sizeInputs = inputs.size();
    for (size_t i = 0; i < sizeInputs; ++i)
    {
        result += parameters[i] * inputs[i];
    }
    result += parameters[sizeInputs];

    return result;
}

}
}
}
}
}
