#include "continental/fuzzy/service/fuzzy/membershipfunction/LinearMembershipFunctionService.h"

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace membershipfunction {

LinearMembershipFunctionService::LinearMembershipFunctionService()
{

}

LinearMembershipFunctionService::~LinearMembershipFunctionService()
{

}

double LinearMembershipFunctionService::calculeLinearMembershipFunctionService(std::vector<double> &parameters, std::vector<double> &inputs)
{
    double result = 0;
    int sizeInputs = static_cast<int>(inputs.size());
    for (int i = 0; i < sizeInputs; ++i)
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
