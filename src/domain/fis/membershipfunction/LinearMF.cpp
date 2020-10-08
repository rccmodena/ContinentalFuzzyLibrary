#include "continental/fuzzy/domain/fis/membershipfunction/LinearMF.h"
#include <vector>

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

std::vector<double> LinearMF::getParams() const
{
    return m_params;
}

void LinearMF::setParams(const std::vector<double> &params)
{
    m_params = params;
}

void LinearMF::addParams( const double valorParam)
{
    m_params.push_back(valorParam);
}

}
}
}
}
}
