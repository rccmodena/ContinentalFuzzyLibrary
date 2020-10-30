#include "continental/fuzzy/service/fuzzy/operators/ProdAndMethod.h"

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace operators {

double ProdAndMethod::calculeProdAndMethod(const std::vector<double> &valuesVector)
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
            result = result * value;
        }
    }
    return result;
}

}
}
}
}
}
