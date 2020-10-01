#ifndef CONTINENTAFUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_LINEARMF_H
#define CONTINENTAFUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_LINEARMF_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/export.h"
#include <QString>
#include <list>

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

    QString getName() const;
    void setName(const QString &name);

    int getNumInputs() const;
    void setNumInputs(int numInputs);

    std::list<float> getParams() const;
    void setParams(const std::list<float> &params);

private:
    QString m_name;
    int m_numInputs = 1;
    std::list<float>m_params;

};

}
}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_FUZZYSERVICE_H
