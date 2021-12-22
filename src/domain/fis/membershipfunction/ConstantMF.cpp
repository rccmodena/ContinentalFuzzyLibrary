#include "continental/fuzzy/domain/fis/membershipfunction/ConstantMF.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

ConstantMF::ConstantMF()
{

}

ConstantMF::~ConstantMF()
{

}

double ConstantMF::getValue() const
{
    return m_value;
}

void ConstantMF::setValue(const double value)
{
    m_value = value;
}


}
}
}
}
}
