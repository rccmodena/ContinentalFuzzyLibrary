#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_LINEARMF_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_LINEARMF_H

#include "continental/fuzzy/export.h"
#include <map>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

class CONTINENTALFUZZY_EXPORT_DECL LinearMF
{

public:
    /// Construtor.
    LinearMF();

    /// Destrutor.
    ~LinearMF();

    std::map<int, double> getParams() const;
    void setParams(const std::map<int, double> &params);
    void addParams(const int numParam, const double valorParam);

private:
    std::map<int, double> m_params;
};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_LINEARMF_H
