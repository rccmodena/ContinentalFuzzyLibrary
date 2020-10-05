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

class CONTINENTALFUZZY_EXPORT_DECL OutputMembershipFunction : public continental::fuzzy::domain::fis::MembershipFunction
{

public:
    /// Construtor.
    OutputMembershipFunction();

    /// Destrutor.
    ~OutputMembershipFunction();

    domain::fis::membershipfunction::LinearMF getLinearmf() const;
    void setLinearmf(const domain::fis::membershipfunction::LinearMF &linearmf);

    domain::fis::membershipfunction::ConstantMF getConstantmf() const;
    void setConstantmf(const domain::fis::membershipfunction::ConstantMF &constantmf);

    domain::fis::definition::OutputFunctions getFunction() const;
    void setFunction(const domain::fis::definition::OutputFunctions &function);

private:
    domain::fis::definition::OutputFunctions m_function = domain::fis::definition::OutputFunctions();
    domain::fis::membershipfunction::LinearMF m_linearmf = domain::fis::membershipfunction::LinearMF();
    domain::fis::membershipfunction::ConstantMF m_constantmf = domain::fis::membershipfunction::ConstantMF();

};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_OUTPUTMEMBERSHIPFUNCTION_H
