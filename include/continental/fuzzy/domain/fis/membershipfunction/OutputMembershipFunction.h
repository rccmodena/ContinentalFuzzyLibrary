#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_OUTPUTMEMBERSHIPFUNCTION_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_OUTPUTMEMBERSHIPFUNCTION_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/MembershipFunction.h"
#include "continental/fuzzy/domain/fis/definition/OutputFunctions.h"
#include "continental/fuzzy/domain/fis/membershipfunction/LinearMF.h"
#include "continental/fuzzy/domain/fis/membershipfunction/ConstantMF.h"
#include <QString>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

class CONTINENTALFUZZY_EXPORT_DECL OutputMembershipFunction : public MembershipFunction
{

public:
    const LinearMF & getLinearmf() const;
    void setLinearmf(const LinearMF &linearmf);

    const ConstantMF & getConstantmf() const;
    void setConstantmf(const ConstantMF &constantmf);

    const definition::OutputFunctions & getFunction() const;
    void setFunction(const definition::OutputFunctions &function);

private:
    definition::OutputFunctions m_function;
    membershipfunction::LinearMF m_linearmf;
    membershipfunction::ConstantMF m_constantmf;

};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_OUTPUTMEMBERSHIPFUNCTION_H
