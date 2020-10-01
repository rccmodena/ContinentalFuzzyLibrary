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

std::list<float> SugenoInput::getRange() const
{
    return m_range;
}

void SugenoInput::setRange(const std::list<float> &range)
{
    m_range = range;
}

int SugenoInput::getNumMfs() const
{
    return m_numMfs;
}

void SugenoInput::setNumMfs(int numMfs)
{
    m_numMfs = numMfs;
}

std::map<std::string, fis::MembershipFunction> SugenoInput::getMfs() const
{
    return m_mfs;
}

void SugenoInput::setMfs(const std::map<std::string, fis::MembershipFunction> &mfs)
{
    m_mfs = mfs;
}

}
}
}
}
}
