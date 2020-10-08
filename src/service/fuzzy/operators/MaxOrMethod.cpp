#include "continental/fuzzy/service/fuzzy/operators/MaxOrMethod.h"

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace operators {

MaxOrMethod::MaxOrMethod()
{

}

MaxOrMethod::~MaxOrMethod()
{

}

double MaxOrMethod::calculeMaxOrMethod(std::vector<double> valuesVector)
{
    return *std::max_element(valuesVector.begin(), valuesVector.end());
}

}
}
}
}
}
