#include "continental/fuzzy/service/fuzzy/operators/MinAndMethod.h"

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace operators {

double MinAndMethod::calculeMinAndMethod(const std::vector<double> &valuesVector)
{
    return *std::min_element(valuesVector.begin(), valuesVector.end());
}

}
}
}
}
}
