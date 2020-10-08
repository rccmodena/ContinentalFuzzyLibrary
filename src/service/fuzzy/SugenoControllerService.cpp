#include "continental/fuzzy/service/fuzzy/SugenoControllerService.h"
#include "continental/fuzzy/domain/fis/Rule.h"
#include "continental/fuzzy/domain/fis/Variable.h"
#include "continental/fuzzy/domain/fis/variable/Input.h"
#include "continental/fuzzy/domain/fis/variable/Output.h"
#include "continental/fuzzy/domain/fis/MembershipFunction.h"
#include "continental/fuzzy/domain/fis/definition/Connections.h"
#include "continental/fuzzy/domain/fis/definition/AndMethods.h"
#include "continental/fuzzy/domain/fis/definition/OrMethods.h"
#include "continental/fuzzy/domain/fis/definition/InputFunctions.h"
#include "continental/fuzzy/domain/fis/definition/OutputFunctions.h"
#include "continental/fuzzy/domain/fuzzy/variable/SugenoInput.h"
#include "continental/fuzzy/domain/fuzzy/variable/SugenoOutput.h"
#include "continental/fuzzy/domain/fuzzy/rulevariable/SugenoRuleInput.h"
#include "continental/fuzzy/domain/fuzzy/rulevariable/SugenoRuleOutput.h"
#include "continental/fuzzy/domain/fuzzy/SugenoRule.h"
#include "continental/fuzzy/domain/fuzzy/SugenoRuleVariable.h"
#include "continental/fuzzy/service/fuzzy/membershipfunction/GaussMembershipFunctionService.h"
#include "continental/fuzzy/service/fuzzy/membershipfunction/GaussTwoMembershipFunctionService.h"
#include "continental/fuzzy/service/fuzzy/membershipfunction/TrapezoidalMembershipFunctionService.h"
#include "continental/fuzzy/service/fuzzy/membershipfunction/TriangularMembershipFunctionService.h"
#include "continental/fuzzy/service/fuzzy/membershipfunction/LinearMembershipFunctionService.h"
#include "continental/fuzzy/service/fuzzy/operators/NotMethod.h"
#include "continental/fuzzy/service/fuzzy/operators/MaxOrMethod.h"
#include "continental/fuzzy/service/fuzzy/operators/MinAndMethod.h"
#include "continental/fuzzy/service/fuzzy/operators/ProborOrMethod.h"
#include "continental/fuzzy/service/fuzzy/operators/ProdAndMethod.h"
#include <vector>

using namespace  continental::fuzzy::domain::fuzzy;
using namespace  continental::fuzzy::domain::fis;
using namespace  continental::fuzzy::domain::fis::variable;
using namespace  continental::fuzzy::domain::fis::definition;
using namespace  continental::fuzzy::domain::fuzzy::variable;
using namespace  continental::fuzzy::domain::fuzzy::rulevariable;
using namespace  continental::fuzzy::service::fuzzy::membershipfunction;
using namespace  continental::fuzzy::service::fuzzy::operators;

namespace continental {
namespace fuzzy {
namespace service {
namespace fuzzy {

SugenoControllerService::SugenoControllerService()
{

}

SugenoController SugenoControllerService::getSugenoController() const
{
    return m_sugenoController;
}

double SugenoControllerService::getResultConnection(domain::fis::Rule p_rule, std::vector<double> listTempInput)
{

    double resultCalc = 0;

    switch (p_rule.getConnection())
    {
        case definition::Connections::AND:
        {
            switch (m_sugenoController.getSugenoFisSystem().getAndMethod())
            {
                case definition::AndMethods::min:
                    resultCalc =  MinAndMethod::calculeMinAndMethod(listTempInput);
                break;
                case definition::AndMethods::prod:
                    resultCalc = ProdAndMethod::calculeProdAndMethod(listTempInput);
                break;
                case definition::AndMethods::none:
                    resultCalc = 0;
                break;
            }
        }
        break;
        case definition::Connections::OR:
        {
            switch (m_sugenoController.getSugenoFisSystem().getOrMethod())
            {
                case definition::OrMethods::max:
                    resultCalc =  MaxOrMethod::calculeMaxOrMethod(listTempInput);
                break;
                case definition::OrMethods::probor:
                    resultCalc =  ProborOrMethod::calculeProborOrMethod(listTempInput);
                break;
                case definition::OrMethods::none:
                    resultCalc =  0;
                break;
            }
        }
        break;
    }
    return resultCalc;
}


double SugenoControllerService::executeCalcOutputFunctions(
        std::vector<double> valueOfPoint,
        size_t indexMemberFunction)
{

    double result = 0;

    auto memberFunction = m_sugenoController.getSugenoFisSystem().getOutputs()[0].getOutputMfs()[indexMemberFunction];
    switch(memberFunction.getFunction())
    {
        case OutputFunctions::linear:
        {
            auto auxVectorInputFis = memberFunction.getLinearmf().getParams();
            result = LinearMembershipFunctionService::calculeLinearMembershipFunctionService(auxVectorInputFis, valueOfPoint);
            break;
        }
        case OutputFunctions::constant:
        {
            result = memberFunction.getConstantmf().getValue();
            break;
        }
    }
    return  result;
}

double SugenoControllerService::executeCalcInputFunctions(
        double inputValue,
        size_t indexInput,
        size_t indexMemberFunction)
{
    double result = 0;

    auto inputObject = m_sugenoController.getSugenoFisSystem().getInputs()[indexInput+1];
    auto memberFunction = inputObject.getInputMfs()[indexMemberFunction];

    switch(memberFunction.getFunction())
    {
        case InputFunctions::trimf:
        {
            result = TriangularMembershipFunctionService::calculeTriangularMf
                    (
                        inputValue,
                        memberFunction.getTrimf().getA(),
                        memberFunction.getTrimf().getB(),
                        memberFunction.getTrimf().getC()
                    );
        }
        break;

        case InputFunctions::trapmf:
        {
            result = TrapezoidalMembershipFunctionService::calculeTrapezoidalMf
                    (
                        inputValue,
                        memberFunction.getTrapmf().getA(),
                        memberFunction.getTrapmf().getB(),
                        memberFunction.getTrapmf().getC(),
                        memberFunction.getTrapmf().getD()
                    );
        }
        break;

        case InputFunctions::gaussmf:
        {
            result = GaussMembershipFunctionService::calculeGaussMf
                     (
                        inputValue,
                        memberFunction.getGaussmf().getMean(),
                        memberFunction.getGaussmf().getSigma()
                     );
        }
        break;

        case InputFunctions::gauss2mf:
        {
            result = GaussTwoMembershipFunctionService::calculeTwoGaussMf
                    (
                        inputValue,
                        memberFunction.getGauss2mf().getMean1(),
                        memberFunction.getGauss2mf().getSigma1(),
                        memberFunction.getGauss2mf().getMean2(),
                        memberFunction.getGauss2mf().getSigma2()
                    );
        }
        break;
    }

    return result;
}

void SugenoControllerService::createFromFisSystem(System p_system)
{
    m_sugenoController.setSugenoFisSystem(p_system);
}

std::vector<double> SugenoControllerService::calcRuleWeights()
{
    std::vector<double> resultWeightsList;

    for (int index = 0; index <=  m_sugenoController.getSugenoFisSystem().getRules().size(); ++index)
    {
        resultWeightsList.push_back(m_sugenoController.getSugenoFisSystem().getRules()[index].getWeight());
    }

    return resultWeightsList;
}

std::vector<double> SugenoControllerService::calcRuleOutputLevel(std::vector<double> v_inputs)
{
    std::vector<double> listResults;

    for (auto r_rule : m_sugenoController.getSugenoFisSystem().getRules())
    {
        //indicie do output
        size_t indiceMemebershipFunction = static_cast<size_t>(r_rule.second.getOutputs()[0].getIndex());
        auto result = executeCalcOutputFunctions(v_inputs, indiceMemebershipFunction);

        listResults.push_back(result);
    }

    return listResults;
}


std::vector<double> SugenoControllerService::calcRuleFiring(std::vector<double> inputsStratBR)
{
    std::vector<double> listResults;

    for (auto r_rule : m_sugenoController.getSugenoFisSystem().getRules())
    {
        std::vector<double> listTempInput;

        size_t auxIndiceInputs = 0;
        for (auto i_input : r_rule.second.getInputs())
        {
            //Busca as informações do input da regra
            size_t indiceMemebershipFunction = static_cast<size_t>(i_input.second.getIndex());

            double auxValue = inputsStratBR[auxIndiceInputs];

            double result = executeCalcInputFunctions(
                        auxValue,
                        indiceMemebershipFunction,
                        auxIndiceInputs);

            if(i_input.second.getInputVarNot())
            {
               double resultNot = NotMethod::calculeNotMethod(result);
               listTempInput.push_back(resultNot);
            }
            else
            {
                listTempInput.push_back(result);
            }
            auxIndiceInputs++;
        }

        double resultCalc = getResultConnection(r_rule.second, listTempInput);
        listResults.push_back(resultCalc);
   }

   return listResults;
}

double SugenoControllerService::sugenoCalcSingleValue(std::vector<double> v_inputs, bool useDictFaciesAssociation)
{
    double result = -1;

    if(m_sugenoController.getSugenoInputs().size() != v_inputs.size())
    {
        //Exception
    }

    std::vector<double> w_array = calcRuleFiring(v_inputs);
    std::vector<double> z_array = calcRuleOutputLevel(v_inputs);
    std::vector<double> weights = calcRuleWeights();

    double sumTotalWeightsWZ = 0;
    double sumTotalWeightW = 0;

    for (size_t aux = 0; aux<=w_array.size(); aux++)
    {
        double w_array_weights = w_array[aux] * weights[aux];
        sumTotalWeightsWZ +=  (w_array_weights)*(z_array[aux]);
        sumTotalWeightW += w_array_weights;
    }

    switch(m_sugenoController.getSugenoFisSystem().getDefuzzMethod())
    {
        case definition::DefuzzMethods::wtsum:
        {
            result = sumTotalWeightsWZ;
            break;
        }
        case definition::DefuzzMethods::wtaver:
        {
            result = sumTotalWeightsWZ / sumTotalWeightW;
            break;
        }
        case definition::DefuzzMethods::none:
        {
            result = -1;
            break;
        }
    }

    if (useDictFaciesAssociation)
    {
        int valueRound = static_cast<int>(result);
        int faciesAssociationConversion = m_sugenoController.getSugenoFisSystem().getFaciesAssociationConversion()[valueRound];
        return static_cast<double>(faciesAssociationConversion);

    }
    else
    {
        return result;
    }
}


}
}
}
}
