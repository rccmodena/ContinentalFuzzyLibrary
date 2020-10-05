/*
* Developed by UNISINOS - Projeto Continentais and Petrobras
* author: Rudi C. C. Modena
* email: rmodena@unisinos.br
* date: October, 2020
*/
#ifndef CONTINENTAL_FUZZY_SERVICE_FIS_OUTPUTSERVICE_H
#define CONTINENTAL_FUZZY_SERVICE_FIS_OUTPUTSERVICE_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/variable/Output.h"
#include "continental/fuzzy/service/fis/MembershipFunctionService.h"
#include <memory>
#include <iostream>
#include <QString>
#include <list>
#include <QTextStream>

namespace continental {
namespace fuzzy {
namespace service {
namespace fis {

class CONTINENTALFUZZY_EXPORT_DECL OutputService
{

public:
    /// Construtor.
    OutputService();

    /// Destrutor.
    ~OutputService();

    // Cria uma variável a partir das informações de um arquivo .fis.
    void createFromFisBlock(const std::list<QString> &fisOutputList, const int numInputs);

    domain::fis::variable::Output getOutput() const;

    void setOutput(const domain::fis::variable::Output &output);

private:
    /// Membros.
    domain::fis::variable::Output m_output = domain::fis::variable::Output();
};

}
}
}
}

#endif // CONTINENTAL_FUZZY_SERVICE_FIS_OUTPUTSERVICE_H
