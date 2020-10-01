#include "continental/fuzzy/domain/fis/variable/Input.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace variable {

Input::Input()
{

}

QString Input::getName() const
{
    return m_name;
}

void Input::setName(const QString &name)
{
    m_name = name;
}

std::list<float> Input::getRange() const
{
    return range;
}

void Input::setRange(const std::list<float> &value)
{
    range = value;
}

int Input::getNumMfs() const
{
    return m_numMfs;
}

void Input::setNumMfs(int numMfs)
{
    m_numMfs = numMfs;
}

}
}
}
}
}
