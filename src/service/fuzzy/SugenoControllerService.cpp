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
#include <vector>


using namespace  continental::fuzzy::domain::fuzzy;
using namespace  continental::fuzzy::domain::fis;
using namespace  continental::fuzzy::domain::fis::variable;
using namespace  continental::fuzzy::domain::fis::definition;
using namespace  continental::fuzzy::domain::fuzzy::variable;
using namespace  continental::fuzzy::domain::fuzzy::rulevariable;
using namespace  continental::fuzzy::service::fuzzy::membershipfunction;

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

void SugenoControllerService::getConnection(domain::fis::Rule p_rule)
{
    if(p_rule.getConnection() ==  Connections::AND)
    {
        if(m_sugenoController.getSugenoFisSystem().getAndMethod() == AndMethods::min)
        {
            return MinAndMethod.calculate_min_and
        }
        else
        {
            if(m_sugenoController.getSugenoFisSystem().getAndMethod() == AndMethods::prod)
            {
                //return ProdAndMethod.calculate_prod_and
            }
        }
    }
    else
    {
        if(p_rule.getConnection() ==  continental::fuzzy::domain::fis::definition::Connections::OR)
        {
            if(m_sugenoController.getSugenoFisSystem().getOrMethod() == OrMethods::max)
            {
                // return MaxOrMethod.calculate_max_or
            }
            else
            {
                if(m_sugenoController.getSugenoFisSystem().getOrMethod() == OrMethods::probor)
                {
                    //return ProdAndMethod.calculate_prod_and
                }
            }

        }
    }
}

void SugenoControllerService::getMFFunction(domain::fis::MembershipFunction p_membershipFunction)
{

    /*
    //reotrna um dic
    //switch(p_membershipFunction.function)
    int aux = 1;
    switch(aux)
    {
        case (int)InputFunctions::trimf:
            //return {'func': TriangularMembershipFunction.calculate_trimf, 'params': {'abc': p_membershipfunction.abc}}
        break;
        case (int)InputFunctions::trapmf:
            //return {'func': TrapezoidalMembershipFunction.calculate_trapmf, 'params': {'abcd': p_membershipfunction.abcd}}
        break;
        case (int)InputFunctions::gaussmf:
            //return {'func': GaussMembershipFunction.calculate_gaussmf,'params': {'mean': p_membershipfunction.mean,'sigma': p_membershipfunction.sigma}};
        break;
        case (int)InputFunctions::gauss2mf:
            // return {'func': GaussTwoMembershipFunction.calculate_gauss2mf, 'params': {'mean1': p_membershipfunction.mean1, 'sigma1': p_membershipfunction.sigma1, 'mean2': p_membershipfunction.mean2,'sigma2': p_membershipfunction.sigma2}}
        break;
        case 33://(int)OutputFunctions::constant:

           auto dict_params = std::map<QString, float>();
           auto p_inputs = m_sugenoController.getSugenoFisSystem().getInputs();
           for (auto f_input  : p_inputs)
           {
                dict_params[f_input.second.getName()]= 0;
           }
           //dict_params['__constant__'] = p_membershipfunction.value
           //return {'func': LinearMembershipFunction.calculate_linear,'params': dict_params}

        break;
    }
    */

}

double SugenoControllerService::executeCalcOutputFunctions(OutputFunctions p_outputFunction, std::vector<double> valueOfPoint)
{

    double result = 0;

    if(p_outputFunction == OutputFunctions::linear)
    {
       result = 0;//LinearMembershipFunction.calculate_linear(r_output.params, v_inputs))
    }
    else
    {
        result = 10;
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

   /*

    //Import inputs
    for (auto f_input  : p_system.getInputs())
    {
        auto sugenoInput = SugenoInput();
        sugenoInput.setRange(f_input.second.getRange());
        sugenoInput.setNumMfs(f_input.second.getNumMfs());

        for (auto f_mf : f_input.second.getInputMfs())
        {
            sugenoInput.addMfs(f_mf.second.getName().toStdString(), getMFFunction(f_mf.second));
        }
        m_sugenoController.addSugenoInput(f_input.second.getName(), sugenoInput);
    }

    //Import outputs
    for (auto f_output  : p_system.getOutputs())
    {
        auto sugenoOutput = SugenoOutput();
        sugenoOutput.setRange(f_output.second.getRange());
        sugenoOutput.setNumMfs(f_output.second.getNumMfs());

        for (auto f_mf : f_output.second.getOutputMfs())
        {
            sugenoOutput.addMfs(f_mf.second.getName(), getMFFunction(f_mf.second));
        }
        m_sugenoController.addSugenoOutput(f_output.second.getName(), sugenoOutput);
    }

    //Import rules
    for (auto f_rule : p_system.getRules())
    {
        auto sugenoRule = SugenoRule();
        sugenoRule.setWeight(f_rule.second.getWeight());
        sugenoRule.setConnection(getConnection(f_rule));

        for (auto i_rule : f_rule.second.getInputs())
        {
            auto sugenoInputRule = SugenoRuleInput();
            sugenoInputRule.setName(i_rule.second.getName());
            sugenoInputRule.setInputVarNot(i_rule.second.getInputVarNot());
            //sugenoInputRule.rule_func = self.sugeno_controller.inputs[i_rule.name].mfs[i_rule.mf]['func']
            //sugenoInputRule.params = self.sugeno_controller.inputs[i_rule.name].mfs[i_rule.mf]['params']
            //sugenoRule.add_input(sugenoInputRule)
        }

        for (auto o_rule : f_rule.second.getOutputs())
        {
            auto sugenoInputRule = SugenoRuleInput();
            //sugenoInputRule.setName(i_rule.second.getName());
            sugenoInputRule.setInputVarNot(o_rule.second.getInputVarNot());
            //sugenoInputRule.rule_func = self.sugeno_controller.inputs[o_rule.name].mfs[i_rule.mf]['func']
            //sugenoInputRule.params = self.sugeno_controller.inputs[o_rule.name].mfs[i_rule.mf]['params']
            //sugenoRule.add_input(sugenoInputRule)
        }


        m_sugenoController.addSugenoOutput(f_rule.second.getName(), sugenoOutput)
    }*/
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
        auto indiceOutput = (r_rule.second.getOutputs()[0]);

        auto listOutputs = m_sugenoController.getSugenoFisSystem().getOutputs();
        auto listMfs = listOutputs[0].getOutputMfs();
        auto objectMembershipFunction = listMfs[0];

        //vetor com os inputs
        std::vector<double> vectorInput;
        vectorInput.push_back(r_rule.second.getWeight());

        auto result = executeCalcOutputFunctions(objectMembershipFunction.getFunction(), vectorInput);

        //list_results.add(result);
    }

    //return np.array(list_results)

}

/*
[0] => Profundidade = 10
[1] => DispercaoEnergia = 1
**/
std::vector<double> SugenoControllerService::calcRuleFiring(std::vector<double> inputsStratBR)
{
    std::vector<double> listResults;

    for (auto r_rule : m_sugenoController.getSugenoFisSystem().getRules())
    {
        //r_rule.second.getInputs() == FIS [1] = Profundidade, 1 = DispercaoEnergia

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
                   double resultNot =  NotMethod.calculate_not(result);
                   listResults.push_back(resultNot);
                }
                else
                {
                    listResults.push_back(result);
                }
                auxIndiceInputs++;
            }
        //}
        /*else
        {
            //??
            //listResults.push_back(rule.connection_func(rule.inputs,v_inputs));
        }*/
   }

    //return np.array(list_results)
}

void SugenoControllerService::sugenoCalcSingleValue(std::vector<double> v_inputs)
{
    double result = -1;

    if(m_sugenoController.getSugenoInputs().size() != v_inputs.size())
    {
        //Exception
    }


    if(m_sugenoController.getSugenoFisSystem().getDefuzzMethod() == DefuzzMethods::wtaver)
    {
        std::vector<double> w_array = calcRuleFiring(v_inputs);
        std::vector<double> z_array = calcRuleOutputLevel(v_inputs);

        std::vector<double> weights = calcRuleWeights();
        std::vector<double> w_array_weights = (w_array * weights);

        for ()
        {

        }

       // result = np.sum(w_array_weights * z_array) / sum(w_array_weights);
    }
    else
    {
        if(m_sugenoController.getSugenoFisSystem().getDefuzzMethod() == DefuzzMethods::wtsum)
        {
            std::vector<double> w_array = calcRuleFiring(v_inputs);
            std::vector<double> z_array = calcRuleOutputLevel(v_inputs);

            std::vector<double> weights = calcRuleWeights();
            std::vector<double> w_array_weights = w_array * weights;

        //    result = np.sum(w_array_weights * z_array);
        }

        if(m_sugenoController.getSugenoFisSystem().use_dict_facies_association)
        {
            //return m_sugenoController.getSugenoFisSystem().facies_association.get(int(round(result, 0)))
        }
        else
        {
             return result;
        }
    }

    return result;
}


}
}
}
}
