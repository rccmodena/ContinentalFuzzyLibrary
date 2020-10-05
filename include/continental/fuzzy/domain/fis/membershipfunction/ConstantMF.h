#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_CONSTANT_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_CONSTANT_H

#include "continental/fuzzy/export.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

class CONTINENTALFUZZY_EXPORT_DECL ConstantMF
{

public:
    /// Construtor.
    ConstantMF();

    /// Destrutor.
    ~ConstantMF();

    double getValue() const;
    void setValue(const double value);

private:
    double m_value;
};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_CONSTANT_H
