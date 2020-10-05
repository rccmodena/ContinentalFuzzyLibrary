#include "continental/fuzzy/domain/fis/variable/Output.h"

using namespace continental::fuzzy::domain::fis::membershipfunction;

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace variable {

Output::Output()
{

}

Output::~Output()
{

}

definition::VariableType Output::getVariableType() const
{
    return m_variableType;
}

std::map<int, OutputMembershipFunction> Output::getOutputMfs() const
{
    return m_outputMfs;
}

void Output::setOutputMfs(const std::map<int, OutputMembershipFunction> &outputMfs)
{
    m_outputMfs = outputMfs;
}

void Output::addOutputMfs(const int mfsNumber, const OutputMembershipFunction &outputMfs)
{
    m_outputMfs.insert(std::pair<int, OutputMembershipFunction>(mfsNumber, outputMfs));
}


}
}
}
}
}
