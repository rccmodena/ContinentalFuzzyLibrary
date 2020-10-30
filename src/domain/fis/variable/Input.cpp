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

const std::map<int, InputMembershipFunction>& Input::getInputMfs() const
{
    return m_inputMfs;
}

void Input::setInputMfs(const std::map<int, InputMembershipFunction> &inputMfs)
{
    m_inputMfs = inputMfs;
}

void Input::addInputMfs(const int mfsNumber, const InputMembershipFunction &inputMfs)
{
    m_inputMfs.insert(std::pair<int, InputMembershipFunction>(mfsNumber, inputMfs));
}

}
}
}
}
}
