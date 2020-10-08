#include "continental/fuzzy/service/fuzzy/operators/NotMethod.h"

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {
namespace operators {

NotMethod::NotMethod()
{

}

NotMethod::~NotMethod()
{

}

double NotMethod::calculeNotMethod(double value)
{
    return 1 - value;
}

}
}
}
}
}
