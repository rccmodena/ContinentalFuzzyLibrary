#include "continental/fuzzy/domain/fuzzy/SugenoVariable.h"
#include "continental/fuzzy/domain/fis/MembershipFunction.h"
namespace continental {
namespace fuzzy {
namespace domain {
namespace fuzzy {

int SugenoVariable::getNumMfs() const
{
    return m_numMfs;
}

void SugenoVariable::setNumMfs(int numMfs)
{
    m_numMfs = numMfs;
}


std::string SugenoVariable::getType() const
{
    return m_type;
}

void SugenoVariable::setType(const std::string &type)
{
    m_type = type;
}

std::pair<double, double> SugenoVariable::getRange() const
{
    return m_range;
}

void SugenoVariable::setRange(const std::pair<double, double> &range)
{
    m_range = range;
}

std::map<std::string, fis::MembershipFunction> SugenoVariable::getMfs() const
{
    return m_mfs;
}

void SugenoVariable::setMfs(const std::map<std::string, fis::MembershipFunction> &mfs)
{
    m_mfs = mfs;
}

void SugenoVariable::addMfs(std::string name, fis::MembershipFunction &mfs)
{
    m_mfs.insert(std::pair<std::string, fis::MembershipFunction>(name, mfs));

}

}
}
}
}
