#include "continental/fuzzy/domain/fis/variable/Input.h"

using namespace continental::fuzzy::domain::fis::membershipfunction;

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace variable {

Input::Input()
{

}

Input::~Input()
{

}

continental::fuzzy::domain::fis::definition::VariableType Input::getVariableType() const
{
    return m_variableType;
}

std::map<int, membershipfunction::InputMembershipFunction> Input::getInputMfs() const
{
    return m_inputMfs;
}

void Input::setInputMfs(const std::map<int, membershipfunction::InputMembershipFunction> &inputMfs)
{
    m_inputMfs = inputMfs;
}

void Input::addInputMfs(const int mfsNumber, const membershipfunction::InputMembershipFunction &inputMfs)
{
    m_inputMfs.insert(std::pair<int, InputMembershipFunction>(mfsNumber, inputMfs));
}

}
}
}
}
}
