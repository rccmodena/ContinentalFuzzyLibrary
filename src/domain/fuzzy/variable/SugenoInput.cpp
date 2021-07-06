#include "continental/fuzzy/domain/fuzzy/variable/SugenoInput.h"
#include "continental/fuzzy/domain/fis/MembershipFunction.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fuzzy {
namespace variable {

SugenoInput::SugenoInput()
{
    setType("antecedent");
}

int SugenoInput::getNumMfs() const
{
    return m_numMfs;
}

void SugenoInput::setNumMfs(int numMfs)
{
    m_numMfs = numMfs;
}

std::pair<double, double> SugenoInput::getRange() const
{
    return m_range;
}

void SugenoInput::setRange(const std::pair<double, double> &range)
{
    m_range = range;
}

}
}
}
}
}
