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
#include <iostream>

using namespace  continental::fuzzy::domain::fuzzy;
using namespace  continental::fuzzy::domain::fis;
using namespace  continental::fuzzy::domain::fis::membershipfunction;
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

SugenoController &SugenoControllerService::getSugenoController()
{
    return m_sugenoController;
}

const SugenoController& SugenoControllerService::getSugenoController() const
{
    return m_sugenoController;
}

double SugenoControllerService::getResultConnection(const Rule &p_rule, const std::vector<double> &listTempInput)
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
                    resultCalc = MaxOrMethod::calculeMaxOrMethod(listTempInput);
                break;
                case definition::OrMethods::probor:
                    resultCalc = ProborOrMethod::calculeProborOrMethod(listTempInput);
                break;
                case definition::OrMethods::none:
                    resultCalc =  0;
                break;
            }
        }
        break;
        case definition::Connections::none:
        {
            resultCalc = -1;
            break;
        }
    }
    return resultCalc;
}


double SugenoControllerService::executeCalcOutputFunctions(
        const std::vector<double> &valueOfPoint,
        size_t indexMemberFunction
    )
{
    double result = 0;

    const OutputMembershipFunction &memberFunction = m_sugenoController.getSugenoFisSystem().getOutputs().at(0).getOutputMfs().at(static_cast<int>(indexMemberFunction));

    switch(memberFunction.getFunction())
    {
        case OutputFunctions::linear:
        {
            const std::vector<double> &auxVectorInputFis = memberFunction.getLinearmf().getParams();
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
        const double inputValue,
        const size_t indexInput,
        const size_t indexMemberFunction)
{
    double result = 0;

    const auto &inputObject = m_sugenoController.getSugenoFisSystem().getInputs().at(indexInput);
    const auto &memberFunction = inputObject.getInputMfs().at(static_cast<int>(indexMemberFunction));

    switch(memberFunction.getFunction())
    {
        case InputFunctions::trimf:
        {
            result = TriangularMembershipFunctionService::calculeTriangularMf(
                        inputValue,
                        memberFunction.getTrimf().getA(),
                        memberFunction.getTrimf().getB(),
                        memberFunction.getTrimf().getC()
                    );
        }
        break;

        case InputFunctions::trapmf:
        {
            result = TrapezoidalMembershipFunctionService::calculeTrapezoidalMf(
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
            result = GaussMembershipFunctionService::calculeGaussMf(
                        inputValue,
                        memberFunction.getGaussmf().getMean(),
                        memberFunction.getGaussmf().getSigma()
                     );
        }
        break;

        case InputFunctions::gauss2mf:
        {
            result = GaussTwoMembershipFunctionService::calculeTwoGaussMf(
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

void SugenoControllerService::createFromFisSystem(const System &p_system)
{
    m_sugenoController.setSugenoFisSystem(p_system);
}

std::vector<double> SugenoControllerService::calcRuleWeights()
{
    size_t sizeRules = m_sugenoController.getSugenoFisSystem().getRules().size();

    std::vector<double> resultWeightsList(sizeRules);

    for (size_t index = 0; index < sizeRules; ++index)
    {
        resultWeightsList[index] = m_sugenoController.getSugenoFisSystem().getRules().at(index).getWeight();
    }

    return resultWeightsList;
}

std::vector<double> SugenoControllerService::calcRuleOutputLevel(const std::vector<double> &v_inputs)
{
    std::vector<double> listResults;
    listResults.reserve(m_sugenoController.getSugenoFisSystem().getRules().size());

    for (const auto &r_rule : m_sugenoController.getSugenoFisSystem().getRules())
    {
        //indicie do output
        const size_t indiceMemebershipFunction = static_cast<size_t>(r_rule.getOutputs().at(0).getIndex());
        const auto result = executeCalcOutputFunctions(v_inputs, indiceMemebershipFunction);

        listResults.push_back(result);
    }

    return listResults;
}


std::vector<double> SugenoControllerService::calcRuleFiring(const std::vector<double> &inputs)
{
    const size_t numberRules = m_sugenoController.getSugenoFisSystem().getRules().size();

    std::vector<double> listResults(numberRules);

    for (size_t indexRule = 0; indexRule < numberRules; indexRule++)
    {
        const Rule &rule = m_sugenoController.getSugenoFisSystem().getRules().at(indexRule);
        const size_t inputsSize = rule.getInputs().size();
        std::vector<double> listTempInput(inputsSize);

        for (size_t indexInputInRule = 0; indexInputInRule < inputsSize; indexInputInRule++)
        {
            //Busca as informações do input da regra
            const RuleVariable &inputObject = rule.getInputs().at(indexInputInRule);
            const size_t indexMemebershipFunction = static_cast<size_t>(inputObject.getIndex());
            const size_t indexInput = rule.getInputs().at(indexInputInRule).getIndexOfInput();

            const double auxValue = inputs[indexInput];

            const double result = executeCalcInputFunctions(
                        auxValue,
                        indexInput,
                        indexMemebershipFunction);

            if(inputObject.getInputVarNot())
            {
               const double resultNot = NotMethod::calculeNotMethod(result);
               listTempInput[indexInputInRule] = resultNot;
            }
            else
            {
                listTempInput[indexInputInRule] = result;
            }
        }

        const double resultCalc = getResultConnection(rule, listTempInput);
        listResults[indexRule] = resultCalc;
   }

   return listResults;
}

double SugenoControllerService::calcSingleValue(std::vector<double> v_inputs)
{
    double result = -1;

    int i = 0;

    auto m_system = m_sugenoController.getSugenoFisSystem();

    for(auto input : v_inputs)
    {
        if(input > m_system.getInputs().at(i).getRange().second)
        {
            v_inputs.at(i) = m_system.getInputs().at(i).getRange().second;
        }

        if(input < m_system.getInputs().at(i).getRange().first)
        {
            v_inputs.at(i) = m_system.getInputs().at(i).getRange().first;
        }

        ++i;
    }


    definition::DefuzzMethods defuzzMethods = m_sugenoController.getSugenoFisSystem().getDefuzzMethod();

    std::vector<double> w_array = calcRuleFiring(v_inputs);
    std::vector<double> z_array = calcRuleOutputLevel(v_inputs);
    std::vector<double> weights = calcRuleWeights();

    double sumTotalWeightsWZ = 0;
    double sumTotalWeightW = 0;

    if (defuzzMethods == definition::DefuzzMethods::wtsum || defuzzMethods == definition::DefuzzMethods::wtaver)
    {
        const size_t limit = w_array.size();
        for (size_t aux = 0; aux < limit; aux++)
        {
            const double w_array_weights = w_array[aux] * weights[aux];
            sumTotalWeightsWZ += w_array_weights * z_array[aux];
            sumTotalWeightW += w_array_weights;
        }
    }

    switch (defuzzMethods)
    {
        case definition::DefuzzMethods::wtsum:
        {
            result = sumTotalWeightsWZ;
            break;
        }
        case definition::DefuzzMethods::wtaver:
        {
            result = (sumTotalWeightW != 0 ) ? (sumTotalWeightsWZ / sumTotalWeightW):0;
            break;
        }
        case definition::DefuzzMethods::winner:
        {
            const size_t limit = w_array.size();

            double max = 0;
            for (size_t aux = 0; aux < limit; aux++)
            {
                const double w_array_weights = w_array[aux] * weights[aux];

                if (w_array_weights > max)
                {
                    max = w_array_weights;
                    result = z_array[aux];
                }
            }
            break;
        }
        case definition::DefuzzMethods::none:
        {
            result = -1;
            break;
        }
    }

    return result;
}


}
}
}
}
