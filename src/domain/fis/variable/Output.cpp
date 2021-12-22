#include "continental/fuzzy/domain/fis/variable/Output.h"

using namespace continental::fuzzy::domain::fis::membershipfunction;

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace variable {

definition::VariableType Output::getVariableType() const
{
    return m_variableType;
}

const std::vector<OutputMembershipFunction>& Output::getOutputMfs() const
{
    return m_outputMfs;
}

void Output::setOutputMfs(const std::vector<OutputMembershipFunction> &outputMfs)
{
    m_outputMfs = outputMfs;
}

void Output::addOutputMfs(const OutputMembershipFunction &outputMfs)
{
    m_outputMfs.push_back(outputMfs);
}


}
}
}
}
}
