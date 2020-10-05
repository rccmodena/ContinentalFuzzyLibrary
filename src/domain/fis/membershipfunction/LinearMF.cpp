#include "continental/fuzzy/domain/fis/membershipfunction/LinearMF.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

LinearMF::LinearMF()
{
}

LinearMF::~LinearMF()
{

}

std::map<int, double> LinearMF::getParams() const
{
    return m_params;
}

void LinearMF::setParams(const std::map<int, double> &params)
{
    m_params = params;
}

void LinearMF::addParams(const int numParam, const double valorParam)
{
    m_params.insert(std::pair<int, double>(numParam, valorParam));
}

}
}
}
}
}
