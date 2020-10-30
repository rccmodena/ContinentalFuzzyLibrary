#include "continental/fuzzy/service/fuzzy/operators/MinAndMethod.h"

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace operators {

double MinAndMethod::calculeMinAndMethod(const std::vector<double> &valuesVector)
{
    double min = valuesVector[0];
    const size_t limit = valuesVector.size();
    for (size_t i = 1; i < limit; ++i)
    {
        if (min > valuesVector[1])
        {
            min = valuesVector[1];
        }
    }

    return min;
}

}
}
}
}
}
