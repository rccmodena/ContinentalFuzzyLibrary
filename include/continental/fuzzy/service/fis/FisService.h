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
#include "continental/fuzzy/domain/fis/rulevariable/RuleInput.h"
#include "continental/fuzzy/domain/fis/rulevariable/RuleOutput.h"
#include "continental/fuzzy/domain/fis/definition/Blocks.h"
#include "continental/fuzzy/service/fis/InputService.h"
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
    std::shared_ptr<domain::fis::System> importFile(const QString &filename, const bool &useFaciesAssociationConverter);

private:
    /// Membros.
    std::shared_ptr<domain::fis::System> m_system = std::make_shared<domain::fis::System>();

    // Preenche as informações do bloco sistema a partir das informações de um arquivo .fis.
    void createSystemFromList(const std::shared_ptr<std::list<QString>> systemList);

    // Verifica se todos os atributos do sistema foram preechidos.
    void validSystem();

    // Cria os antecedentes com as informações dos blocos de inputs do arquivo .fis.
    void createInputsFromMap(const std::shared_ptr<std::map<int, std::list<QString>>> inputsMap);

    // Cria os consequentes com as informações dos blocos de inputs do arquivo .fis.
    void createOutputsFromMap(const std::shared_ptr<std::map<int, std::list<QString>>> outputsList);

    // Cria os antededentes das regras com as informações do bloco de rules do arquivo .fis.
    std::shared_ptr<domain::fis::rulevariable::RuleInput> createRuleInputsFromList(const std::shared_ptr<std::map<int, std::list<QString>>> ruleInputsList);

    // Cria os consequentes das regras com as informações do bloco de rules do arquivo .fis.
    std::shared_ptr<domain::fis::rulevariable::RuleOutput> createRuleOutputsFromList(const std::shared_ptr<std::map<int, std::list<QString>>> ruleOutputsList);

    // Cria as regras com as informações do bloco de rules do arquivo .fis.
    void createRulesFromList(const std::shared_ptr<std::list<QString>> ruleList);

    //def create_dict_facies_association(self, p_use_dict: bool):
    void createFaciesAssociationConverter(const bool &useFaciesAssociationConverter);

    // Verifica se a importação preencheu todas as informações.
    void validImport();
};

}
}
}
}

#endif // CONTINENTAL_FUZZY_SERVICE_FIS_FISSERVICE_H
