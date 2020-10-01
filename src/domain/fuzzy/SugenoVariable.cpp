#include "continental/fuzzy/domain/fuzzy/SugenoVariable.h"
#include "continental/fuzzy/domain/fis/MembershipFunction.h"
namespace continental {
namespace fuzzy {
namespace domain {
namespace fuzzy {

SugenoVariable::SugenoVariable()
{

}

std::list<float> SugenoVariable::getRange() const
{
    return m_range;
}

void SugenoVariable::setRange(const std::list<float> &range)
{
    m_range = range;
}

int SugenoVariable::getNumMfs() const
{
    return m_numMfs;
}

void SugenoVariable::setNumMfs(int numMfs)
{
    m_numMfs = numMfs;
}

std::map<std::string, fis::MembershipFunction> SugenoVariable::getMfs() const
{
    return m_mfs;
}

void SugenoVariable::setMfs(const std::map<std::string, fis::MembershipFunction> &mfs)
{
    m_mfs = mfs;
}

std::string SugenoVariable::getType() const
{
    return m_type;
}

void SugenoVariable::setType(const std::string &type)
{
    m_type = type;
}

}
}
}
}
