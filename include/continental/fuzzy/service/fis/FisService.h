/*
* Developed by UNISINOS - Projeto Continentais and Petrobras
* author: Rudi C. C. Modena
* email: rmodena@unisinos.br
* date: October, 2020
*/
#ifndef CONTINENTAL_FUZZY_SERVICE_FIS_FISSERVICE_H
#define CONTINENTAL_FUZZY_SERVICE_FIS_FISSERVICE_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/System.h"
#include "continental/fuzzy/domain/fis/RuleVariable.h"
#include "continental/fuzzy/domain/fis/definition/Blocks.h"
#include "continental/fuzzy/domain/fis/definition/FaciesAssociationsImplemented.h"
#include "continental/fuzzy/service/fis/InputFisService.h"
#include "continental/fuzzy/service/fis/OutputFisService.h"
#include <memory>
#include <list>
#include <QString>
#include <iostream>
#include <QFile>
#include <QTextStream>

namespace continental {
namespace fuzzy {
namespace service {
namespace fis {

class CONTINENTALFUZZY_EXPORT_DECL FisService
{

public:
    /// Construtor.
    FisService();

    /// Destrutor.
    ~FisService();

    // Importa um arquivo .fis e cria todos os componentes de um sistema fuzzy.
    domain::fis::System& importFile(const QString &filename);

private:
    /// Membros.
    domain::fis::System m_system = domain::fis::System();

    // Preenche as informações do bloco sistema a partir das informações de um arquivo .fis.
    void createSystemFromList(const std::list<QString> &systemList);

    // Verifica se todos os atributos do sistema foram preechidos.
    void validSystem();

    // Cria os antecedentes com as informações dos blocos de inputs do arquivo .fis.
    void createInputsFromMap(const std::map<int, std::list<QString>> &inputsMap);

    // Cria os consequentes com as informações dos blocos de inputs do arquivo .fis.
    void createOutputsFromMap(const std::map<int, std::list<QString>> &outputsList);

    // Cria as regras com as informações do bloco de rules do arquivo .fis.
    void createRulesFromList(const std::list<QString> &ruleList);

    //def create_dict_facies_association(self, p_use_dict: bool):
    void createFaciesAssociationConverter();

    // Verifica se a importação preencheu todas as informações.
    void validImport();
};

}
}
}
}

#endif // CONTINENTAL_FUZZY_SERVICE_FIS_FISSERVICE_H
