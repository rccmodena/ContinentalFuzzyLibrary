#include "continental/fuzzy/domain/fis/membershipfunction/InputMembershipFunction.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

InputMembershipFunction::InputMembershipFunction()
{
}

InputMembershipFunction::~InputMembershipFunction()
{

}

domain::fis::definition::InputFunctions InputMembershipFunction::getFunction() const
{
    return m_function;
}

void InputMembershipFunction::setFunction(const domain::fis::definition::InputFunctions &function)
{
    m_function = function;
}

domain::fis::membershipfunction::GaussMF InputMembershipFunction::getGaussmf() const
{
    return m_gaussmf;
}

void InputMembershipFunction::setGaussmf(const domain::fis::membershipfunction::GaussMF &gaussmf)
{
    m_gaussmf = gaussmf;
}

domain::fis::membershipfunction::Gauss2MF InputMembershipFunction::getGauss2mf() const
{
    return m_gauss2mf;
}

void InputMembershipFunction::setGauss2mf(const domain::fis::membershipfunction::Gauss2MF &gauss2mf)
{
    m_gauss2mf = gauss2mf;
}

domain::fis::membershipfunction::TriMF InputMembershipFunction::getTrimf() const
{
    return m_trimf;
}

void InputMembershipFunction::setTrimf(const domain::fis::membershipfunction::TriMF &trimf)
{
    m_trimf = trimf;
}

domain::fis::membershipfunction::TrapMF InputMembershipFunction::getTrapmf() const
{
    return m_trapmf;
}

void InputMembershipFunction::setTrapmf(const domain::fis::membershipfunction::TrapMF &trapmf)
{
    m_trapmf = trapmf;
}

}
}
}
}
}
