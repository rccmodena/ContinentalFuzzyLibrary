/*
* Developed by UNISINOS - Projeto Continentais and Petrobras
* author: Rudi C. C. Modena
* email: rmodena@unisinos.br
* date: October, 2020
*/
#ifndef CONTINENTAL_FUZZY_SERVICE_FIS_MEMBERSHIPFUNCTIONFISSERVICE_H
#define CONTINENTAL_FUZZY_SERVICE_FIS_MEMBERSHIPFUNCTIONFISSERVICE_H

#include "continental/fuzzy/export.h"
#include "continental/fuzzy/domain/fis/definition/InputFunctions.h"
#include "continental/fuzzy/domain/fis/membershipfunction/InputMembershipFunction.h"
#include "continental/fuzzy/domain/fis/membershipfunction/OutputMembershipFunction.h"
#include "continental/fuzzy/domain/fis/membershipfunction/ConstantMF.h"
#include "continental/fuzzy/domain/fis/membershipfunction/GaussMF.h"
#include "continental/fuzzy/domain/fis/membershipfunction/Gauss2MF.h"
#include "continental/fuzzy/domain/fis/membershipfunction/LinearMF.h"
#include "continental/fuzzy/domain/fis/membershipfunction/TrapMF.h"
#include "continental/fuzzy/domain/fis/membershipfunction/TriMF.h"
#include <memory>
#include <iostream>
#include <QString>
#include <list>
#include <QTextStream>

namespace continental {
namespace fuzzy {
namespace service {
namespace fis {

class CONTINENTALFUZZY_EXPORT_DECL MembershipFunctionFisService
{

public:
    /// Construtor.
    MembershipFunctionFisService();

    /// Destrutor.
    ~MembershipFunctionFisService();

    void createInputMembershipFisFunction(const QString &mfName,
                                  const QString &functionName,
                                  const QString &functionValues);

    void createOutputMembershipFisFunction(const QString &mfName,
                                  const QString &functionName,
                                  const QString &functionValues,
                                  const int numberOfInputs);

    domain::fis::membershipfunction::InputMembershipFunction getInputMembershipFisFunction() const;
    void setInputMembershipFisFunction(const domain::fis::membershipfunction::InputMembershipFunction &inputMembershipFisFunction);

    domain::fis::membershipfunction::OutputMembershipFunction getOutputMembershipFisFunction() const;
    void setOutputMembershipFisFunction(const domain::fis::membershipfunction::OutputMembershipFunction &outputMembershipFisFunction);

private:
    /// Membros.
    domain::fis::membershipfunction::InputMembershipFunction m_inputMembershipFisFunction = domain::fis::membershipfunction::InputMembershipFunction();
    domain::fis::membershipfunction::OutputMembershipFunction m_outputMembershipFisFunction = domain::fis::membershipfunction::OutputMembershipFunction();
};

}
}
}
}

#endif // CONTINENTAL_FUZZY_SERVICE_FIS_MEMBERSHIPFUNCTIONFISSERVICE_H
