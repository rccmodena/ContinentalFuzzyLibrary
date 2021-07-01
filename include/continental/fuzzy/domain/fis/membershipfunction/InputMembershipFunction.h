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

class CONTINENTALFUZZY_EXPORT_DECL InputMembershipFunction : public MembershipFunction
{

public:
    const definition::InputFunctions & getFunction() const;
    void setFunction(const definition::InputFunctions &function);

    const GaussMF & getGaussmf() const;
    void setGaussmf(const GaussMF &gaussmf);

    const Gauss2MF & getGauss2mf() const;
    void setGauss2mf(const Gauss2MF &gauss2mf);

    const TriMF & getTrimf() const;
    void setTrimf(const TriMF &trimf);

    TrapMF & getTrapmf();
    const TrapMF & getTrapmf() const;
    void setTrapmf(const TrapMF &trapmf);

private:
    definition::InputFunctions m_function;
    TriMF m_trimf;
    TrapMF m_trapmf;
    GaussMF m_gaussmf;
    Gauss2MF m_gauss2mf;
};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_INPUTMEMBERSHIPFUNCTION_H
