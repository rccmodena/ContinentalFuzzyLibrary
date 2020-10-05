#ifndef CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_TRIMF_H
#define CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_TRIMF_H

#include "continental/fuzzy/export.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

class CONTINENTALFUZZY_EXPORT_DECL TriMF
{

public:
    /// Construtor.
    TriMF();

    /// Destrutor.
    ~TriMF();

    double getA() const;
    void setA(double a);

    double getB() const;
    void setB(double b);

    double getC() const;
    void setC(double c);

private:
    double m_a = 0.0;
    double m_b = 0.0;
    double m_c = 0.0;

};

}
}
}
}
}

#endif // CONTINENTAL_FUZZY_DOMAIN_FIS_MEMBERSHIPFUNCTION_TRIMF_H
