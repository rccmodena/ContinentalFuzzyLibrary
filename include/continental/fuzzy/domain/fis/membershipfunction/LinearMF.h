#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_LINEARMF_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_LINEARMF_H

#include "continental/fuzzy/export.h"
#include <vector>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

class CONTINENTALFUZZY_EXPORT_DECL LinearMF
{

public:
    std::vector<double>& getParams();
    void setParams(const std::vector<double> &params);
    void addParams(const double valorParam);

private:
   std::vector<double> m_params;
};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_LINEARMF_H
