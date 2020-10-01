#include "continental/fuzzy/domain/fis/variable/Output.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace variable {

Output::Output()
{

}

QString Output::getName() const
{
    return m_name;
}

void Output::setName(const QString &name)
{
    m_name = name;
}

std::list<float> Output::getRange() const
{
    return range;
}

void Output::setRange(const std::list<float> &value)
{
    range = value;
}

int Output::getNumMfs() const
{
    return m_numMfs;
}

void Output::setNumMfs(int numMfs)
{
    m_numMfs = numMfs;
}

}
}
}
}
}
