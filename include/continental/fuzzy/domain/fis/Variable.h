#ifndef CONTINENTAFUZZY_DOMAIN_FIS_VARIABLE_H
#define CONTINENTAFUZZY_DOMAIN_FIS_VARIABLE_H

#include "continental/fuzzy/export.h"
#include <QString>
#include <list>
namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {

class CONTINENTALFUZZY_EXPORT_DECL Variable
{

public:
    /// Construtor.
    Variable();

    QString getName() const;
    void setName(const QString &name);

    std::list<float> getRange() const;
    void setRange(const std::list<float> &value);

    int getNumMfs() const;
    void setNumMfs(int numMfs);

private:
    QString m_name;
    std::list<float> range;
    int m_numMfs;
    //std::map<int, MembershipFunction> m_mfs;
};

}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_FUZZYSERVICE_H
