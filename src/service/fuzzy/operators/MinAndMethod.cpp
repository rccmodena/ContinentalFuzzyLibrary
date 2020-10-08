#include "continental/fuzzy/service/fuzzy/operators/MinAndMethod.h"

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace operators {

MinAndMethod::MinAndMethod()
{

}

MinAndMethod::~MinAndMethod()
{

}

double MinAndMethod::calculeMinAndMethod(std::vector<double> &valuesVector)
{
    return *std::min_element(valuesVector.begin(), valuesVector.end());
}

}
}
}
}
}
