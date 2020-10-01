#ifndef CONTINENTAFUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_TRAPMF_H
#define CONTINENTAFUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_TRAPMF_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/export.h"
#include <QString>
#include <list>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

class CONTINENTALFUZZY_EXPORT_DECL TrapMF
{

public:
    /// Construtor.
    TrapMF();

    QString getName() const;
    void setName(const QString &name);

    std::list<float> getAbcd() const;
    void setAbcd(const std::list<float> &abcd);

private:
    QString m_name;
    std::list<float>m_abcd;

};

}
}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_FUZZYSERVICE_H
