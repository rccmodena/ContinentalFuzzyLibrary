#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_GAUSS2MF_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_GAUSS2MF_H

#include "continental/fuzzy/export.h"

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

    /// Destrutor.
    ~Gauss2MF();

    double getSigma1() const;
    void setSigma1(double sigma1);

    double getMean1() const;
    void setMean1(double mean1);

    double getSigma2() const;
    void setSigma2(double sigma2);

    double getMean2() const;
    void setMean2(double mean2);

private:
    double m_sigma1;
    double m_mean1;
    double m_sigma2;
    double m_mean2;
};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_GAUSS2MF_H
