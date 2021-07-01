#include "continental/fuzzy/domain/fis/membershipfunction/OutputMembershipFunction.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

const LinearMF & OutputMembershipFunction::getLinearmf() const
{
    return m_linearmf;
}

void OutputMembershipFunction::setLinearmf(const LinearMF &linearmf)
{
    m_linearmf = linearmf;
}

const ConstantMF & OutputMembershipFunction::getConstantmf() const
{
    return m_constantmf;
}

void OutputMembershipFunction::setConstantmf(const ConstantMF &constantmf)
{
    m_constantmf = constantmf;
}

const definition::OutputFunctions & OutputMembershipFunction::getFunction() const
{
    return m_function;
}

void OutputMembershipFunction::setFunction(const definition::OutputFunctions &function)
{
    m_function = function;
}

}
}
}
}
}
