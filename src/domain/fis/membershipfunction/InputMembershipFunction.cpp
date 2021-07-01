#include "continental/fuzzy/domain/fis/membershipfunction/InputMembershipFunction.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

const definition::InputFunctions & InputMembershipFunction::getFunction() const
{
    return m_function;
}

void InputMembershipFunction::setFunction(const definition::InputFunctions &function)
{
    m_function = function;
}

const GaussMF & InputMembershipFunction::getGaussmf() const
{
    return m_gaussmf;
}

void InputMembershipFunction::setGaussmf(const GaussMF &gaussmf)
{
    m_gaussmf = gaussmf;
}

const Gauss2MF & InputMembershipFunction::getGauss2mf() const
{
    return m_gauss2mf;
}

void InputMembershipFunction::setGauss2mf(const Gauss2MF &gauss2mf)
{
    m_gauss2mf = gauss2mf;
}

const TriMF & InputMembershipFunction::getTrimf() const
{
    return m_trimf;
}

void InputMembershipFunction::setTrimf(const TriMF &trimf)
{
    m_trimf = trimf;
}

TrapMF &InputMembershipFunction::getTrapmf()
{
    return m_trapmf;
}

const TrapMF & InputMembershipFunction::getTrapmf() const
{
    return m_trapmf;
}

void InputMembershipFunction::setTrapmf(const TrapMF &trapmf)
{
    m_trapmf = trapmf;
}

}
}
}
}
}
