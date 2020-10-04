#ifndef CONTINENTAFUZZY_DOMAIN_FIS_VARIABLE_H
#define CONTINENTAFUZZY_DOMAIN_FIS_VARIABLE_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/MembershipFunction.h"
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

    std::shared_ptr<std::pair<float, float>> getRange() const;
    void setRange(const std::shared_ptr<std::pair<float, float>> range);

    int getNumMfs() const;
    void setNumMfs(int numMfs);

private:
    QString m_name = "";
    std::shared_ptr<std::pair<float, float>> m_range = std::make_shared<std::pair<float, float>>(0, 0);
    int m_numMfs = 0;
    std::shared_ptr<std::map<int, MembershipFunction>> m_mfs;
};

}
}
}
}

#endif // CONTINENTAFUZZY_SERVICE_FUZZY_FUZZYSERVICE_H
