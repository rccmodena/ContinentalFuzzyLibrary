#ifndef CONTINENTAFUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_GAUSS2MF_H
#define CONTINENTAFUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_GAUSS2MF_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/export.h"
#include <QString>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

class CONTINENTALFUZZY_EXPORT_DECL Gauss2MF
{

public:
    /// Construtor.
    Gauss2MF();

    QString getName() const;
    void setName(const QString &name);

    float getSigma1() const;
    void setSigma1(float sigma1);

    float getMean1() const;
    void setMean1(float mean1);

    float getSigma2() const;
    void setSigma2(float sigma2);

    float getMean2() const;
    void setMean2(float mean2);

private:
    QString m_name;
    float m_sigma1;
    float m_mean1;
    float m_sigma2;
    float m_mean2;

};

}
}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_FUZZYSERVICE_H
