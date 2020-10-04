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
std::shared_ptr<std::pair<float, float>> Variable::getRange() const
{
    return m_range;
}

void Variable::setRange(const std::shared_ptr<std::pair<float, float>> range)
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
