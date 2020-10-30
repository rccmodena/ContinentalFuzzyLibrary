#include "continental/fuzzy/service/fuzzy/operators/ProborOrMethod.h"

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace operators {

double ProborOrMethod::calculeProborOrMethod(const std::vector<double> &valuesVector)
{
    double result = 0;
    bool firstValue = true;
    for (double const& value : valuesVector)
    {
        if (firstValue)
        {
            firstValue = false;
            result = value;
        }
        else
        {
            result = (result + value) - (result * value);
        }
    }
    return result;
}

}
}
}
}
}
