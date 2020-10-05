#ifndef CONTINENTAFUZZY_DOMAIN_FIS_VARIABLE_H
#define CONTINENTAFUZZY_DOMAIN_FIS_VARIABLE_H

#include "continental/fuzzy/export.h"
#include <QString>
#include <memory>
#include <map>

namespace continental {
namespace fuzzy {
namespace domain {
namespace fis {

class CONTINENTALFUZZY_EXPORT_DECL Variable
{

public:
    /// Construtor.
    Variable();

    /// Destrutor.
    ~Variable();

    QString getName() const;
    void setName(const QString &name);

    std::pair<double, double>& getRange();
    void setRange(const std::pair<double, double> &range);

    int getNumMfs() const;
    void setNumMfs(int numMfs);

private:
    QString m_name = "";
    std::pair<double, double> m_range = std::pair<double, double>(0.0, 0.0);
    int m_numMfs = 0;
};

}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_FUZZYSERVICE_H
