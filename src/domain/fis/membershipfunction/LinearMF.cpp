#include "continental/fuzzy/domain/fis/membershipfunction/LinearMF.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

LinearMF::LinearMF()
{
}

QString LinearMF::getName() const
{
    return m_name;
}

void LinearMF::setName(const QString &name)
{
    m_name = name;
}

int LinearMF::getNumInputs() const
{
    return m_numInputs;
}

void LinearMF::setNumInputs(int numInputs)
{
    m_numInputs = numInputs;
}

std::list<float> LinearMF::getParams() const
{
    return m_params;
}

void LinearMF::setParams(const std::list<float> &params)
{
    m_params = params;
}


}
}
}
}
}
