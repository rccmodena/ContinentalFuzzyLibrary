#include "continental/fuzzy/domain/fis/Variable.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {

Variable::Variable()
{
}

Variable::~Variable()
{

}

QString Variable::getName() const
{
    return m_name;
}

void Variable::setName(const QString &name)
{
    m_name = name;
}

std::pair<double, double>& Variable::getRange()
{
    return m_range;
}

void Variable::setRange(const std::pair<double, double> &range)
{
    m_range = range;
}

int Variable::getNumMfs() const
{
    return m_numMfs;
}

void Variable::setNumMfs(int numMfs)
{
    m_numMfs = numMfs;
}


}
}
}
}
