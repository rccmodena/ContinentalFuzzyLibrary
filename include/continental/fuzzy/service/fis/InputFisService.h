/*
* Developed by UNISINOS - Projeto Continentais and Petrobras
* author: Rudi C. C. Modena
* email: rmodena@unisinos.br
* date: October, 2020
*/
#ifndef CONTINENTAL_FUZZY_SERVICE_FIS_INPUTFISSERVICE_H
#define CONTINENTAL_FUZZY_SERVICE_FIS_INPUTFISSERVICE_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/variable/Input.h"
#include "continental/fuzzy/service/fis/MembershipFunctionFisService.h"
#include <memory>
#include <iostream>
#include <QString>
#include <list>
#include <QTextStream>

namespace continental {
namespace fuzzy {
namespace service {
namespace fis {

class CONTINENTALFUZZY_EXPORT_DECL InputFisService
{

public:
    /// Construtor.
    InputFisService();

    /// Destrutor.
    ~InputFisService();

    // Cria uma variável a partir das informações de um arquivo .fis.
    void createFromFisBlock(const std::list<QString> &fisInputFisList);

    domain::fis::variable::Input getInput() const;

    void setInput(const domain::fis::variable::Input &inputFis);

private:
    /// Membros.
    domain::fis::variable::Input m_inputFis = domain::fis::variable::Input();
};

}
}
}
}

#endif // CONTINENTAL_FUZZY_SERVICE_FIS_INPUTSERVICE_H
