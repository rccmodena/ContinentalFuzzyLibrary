#ifndef CONTINENTAFUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_GAUSSMF_H
#define CONTINENTAFUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_GAUSSMF_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/export.h"
#include <QString>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

class CONTINENTALFUZZY_EXPORT_DECL GaussMF
{

public:
    /// Construtor.
    GaussMF();

    QString getName() const;
    void setName(const QString &name);

    float getSigma() const;
    void setSigma(float sigma);

    float getMean() const;
    void setMean(float mean);

private:
    QString m_name;
    float m_sigma;
    float m_mean;

};

}
}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_FUZZYSERVICE_H
