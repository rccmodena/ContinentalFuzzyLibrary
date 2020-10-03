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

    //def import_file(self, filename: str, use_dict_facies_association = False):
    std::shared_ptr<domain::fis::System> importFile(const QString &filename, const bool &useFaciesAssociationConverter);

private:
    /// Membros.
    std::shared_ptr<domain::fis::System> m_system = std::make_shared<domain::fis::System>();

    //def create_system_from_list(self, s_list: List[str])
    void createSystemFromList(const std::list<QString> &systemList);

    //def valid_system(self):
    void validSystem();

    //def create_inputs_from_list(self, i_list: List[List[str]])
    void createInputsFromMap(const std::map<int, std::list<QString>> &inputsMap);

    //def create_outputs_from_list(self, o_list: List[List[str]])
    void createOutputsFromMap(const std::map<int, std::list<QString>> &outputsList);

    //def create_inputs_rule(self, i_r_list: List[str]) -> List[RuleInput]:
    std::shared_ptr<domain::fis::rulevariable::RuleInput> createRuleInputsFromList(const std::map<int, std::list<QString>> &ruleInputsList);

    //def create_outputs_rule(self, o_r_list: List[str]) -> List[RuleOutput]:
    std::shared_ptr<domain::fis::rulevariable::RuleOutput> createRuleOutputsFromList(const std::map<int, std::list<QString>> &ruleOutputsList);

    //def create_rules_from_list(self, r_list: List[str]):
    void createRulesFromList(const std::list<QString> &ruleList);

    //def create_dict_facies_association(self, p_use_dict: bool):
    void createFaciesAssociationConverter(const bool &useFaciesAssociationConverter);

    //def valid_import(self):
    void validImport();
};

}
}
}
}

#endif // CONTINENTAL_FUZZY_SERVICE_FIS_FISSERVICE_H
