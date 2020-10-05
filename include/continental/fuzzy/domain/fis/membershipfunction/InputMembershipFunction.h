#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_INPUTMEMBERSHIPFUNCTION_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_INPUTMEMBERSHIPFUNCTION_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/MembershipFunction.h"
#include "continental/fuzzy/domain/fis/definition/InputFunctions.h"
#include "continental/fuzzy/domain/fis/membershipfunction/TriMF.h"
#include "continental/fuzzy/domain/fis/membershipfunction/TrapMF.h"
#include "continental/fuzzy/domain/fis/membershipfunction/GaussMF.h"
#include "continental/fuzzy/domain/fis/membershipfunction/Gauss2MF.h"
#include <QString>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

class CONTINENTALFUZZY_EXPORT_DECL InputMembershipFunction : public continental::fuzzy::domain::fis::MembershipFunction
{

public:
    /// Construtor.
    InputMembershipFunction();

    /// Destrutor.
    ~InputMembershipFunction();

    domain::fis::definition::InputFunctions getFunction() const;
    void setFunction(const domain::fis::definition::InputFunctions &function);

    domain::fis::membershipfunction::GaussMF getGaussmf() const;
    void setGaussmf(const domain::fis::membershipfunction::GaussMF &gaussmf);

    domain::fis::membershipfunction::Gauss2MF getGauss2mf() const;
    void setGauss2mf(const domain::fis::membershipfunction::Gauss2MF &gauss2mf);

    domain::fis::membershipfunction::TriMF getTrimf() const;
    void setTrimf(const domain::fis::membershipfunction::TriMF &trimf);

    domain::fis::membershipfunction::TrapMF getTrapmf() const;
    void setTrapmf(const domain::fis::membershipfunction::TrapMF &trapmf);

private:
    domain::fis::definition::InputFunctions m_function = domain::fis::definition::InputFunctions();
    domain::fis::membershipfunction::TriMF m_trimf = domain::fis::membershipfunction::TriMF();
    domain::fis::membershipfunction::TrapMF m_trapmf = domain::fis::membershipfunction::TrapMF();
    domain::fis::membershipfunction::GaussMF m_gaussmf = domain::fis::membershipfunction::GaussMF();
    domain::fis::membershipfunction::Gauss2MF m_gauss2mf = domain::fis::membershipfunction::Gauss2MF();
};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_INPUTMEMBERSHIPFUNCTION_H
