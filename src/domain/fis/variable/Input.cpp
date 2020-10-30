#include "continental/fuzzy/domain/fis/variable/Input.h"

using namespace continental::fuzzy::domain::fis::membershipfunction;

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace variable {

definition::VariableType Input::getVariableType() const
{
    return m_variableType;
}

const std::vector<InputMembershipFunction>& Input::getInputMfs() const
{
    return m_inputMfs;
}

void Input::setInputMfs(const std::vector<InputMembershipFunction> &inputMfs)
{
    m_inputMfs = inputMfs;
}

void Input::addInputMfs(const InputMembershipFunction &inputMfs)
{
    m_inputMfs.push_back(inputMfs);
}

}
}
}
}
}
