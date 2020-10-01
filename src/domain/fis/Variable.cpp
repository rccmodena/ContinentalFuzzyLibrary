#include "continental/fuzzy/domain/fis/Variable.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {

Variable::Variable()
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

std::list<float> Variable::getRange() const
{
    return range;
}

void Variable::setRange(const std::list<float> &value)
{
    range = value;
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
