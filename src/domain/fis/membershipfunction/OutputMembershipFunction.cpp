#include "continental/fuzzy/domain/fis/membershipfunction/OutputMembershipFunction.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

OutputMembershipFunction::OutputMembershipFunction()
{
}

OutputMembershipFunction::~OutputMembershipFunction()
{

}

domain::fis::membershipfunction::LinearMF OutputMembershipFunction::getLinearmf() const
{
    return m_linearmf;
}

void OutputMembershipFunction::setLinearmf(const domain::fis::membershipfunction::LinearMF &linearmf)
{
    m_linearmf = linearmf;
}

domain::fis::membershipfunction::ConstantMF OutputMembershipFunction::getConstantmf() const
{
    return m_constantmf;
}

void OutputMembershipFunction::setConstantmf(const domain::fis::membershipfunction::ConstantMF &constantmf)
{
    m_constantmf = constantmf;
}

domain::fis::definition::OutputFunctions OutputMembershipFunction::getFunction() const
{
    return m_function;
}

void OutputMembershipFunction::setFunction(const domain::fis::definition::OutputFunctions &function)
{
    m_function = function;
}

}
}
}
}
}
