#include "continental/fuzzy/domain/fis/variable/Input.h"

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

}
}
}
}
}
