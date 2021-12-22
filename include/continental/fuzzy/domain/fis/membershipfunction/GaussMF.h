#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_GAUSSMF_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_GAUSSMF_H

#include "continental/fuzzy/export.h"

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

    /// Destrutor.
    ~GaussMF();

    double getSigma() const;
    void setSigma(double sigma);

    double getMean() const;
    void setMean(double mean);

private:
    double m_sigma;
    double m_mean;
};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_GAUSSMF_H
