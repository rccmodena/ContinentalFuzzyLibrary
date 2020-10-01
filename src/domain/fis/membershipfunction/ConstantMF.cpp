#include "continental/fuzzy/domain/fis/membershipfunction/ConstantMF.h"

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {
namespace membershipfunction {

ConstantMF::ConstantMF()
{

}

QString ConstantMF::getName() const
{
    return m_name;
}

void ConstantMF::setName(const QString &name)
{
    m_name = name;
}

QString ConstantMF::getValue() const
{
    return m_value;
}

void ConstantMF::setValue(const QString &value)
{
    m_value = value;
}


}
}
}
}
}
