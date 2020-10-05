#include "continental/fuzzy/service/fis/MembershipFunctionFisService.h"

using namespace continental::fuzzy::domain::fis::membershipfunction;
using namespace continental::fuzzy::domain::fis::definition;

namespace continental {
namespace fuzzy {
namespace service {
namespace fis {

MembershipFunctionFisService::MembershipFunctionFisService()
{

}

MembershipFunctionFisService::~MembershipFunctionFisService()
{

}

void MembershipFunctionFisService::createInputMembershipFisFunction(const QString &mfName,
                                                                    const QString &functionName,
                                                                    const QString &functionValues)
{
    if (functionName == "trimf")
    {
        InputMembershipFunction membershipFunction = InputMembershipFunction();
        membershipFunction.setName(mfName);
        membershipFunction.setFunction(InputFunctions::trimf);
        QString trimFunctionValues = functionValues.mid(1, functionValues.size() - 2);
        QStringList splitValues = trimFunctionValues.split(" ");
        if (splitValues.size() == 3)
        {
            TriMF triMF = TriMF();
            triMF.setA(splitValues[0].toDouble());
            triMF.setB(splitValues[1].toDouble());
            triMF.setC(splitValues[2].toDouble());
            membershipFunction.setTrimf(triMF);
            m_inputMembershipFisFunction = membershipFunction;
        }
        else
        {
            throw std::exception("Função de pertinência triangular com número incorreto de parâmetros!");
        }
    }
    else if (functionName == "trapmf")
    {
        InputMembershipFunction membershipFunction = InputMembershipFunction();
        membershipFunction.setName(mfName);
        membershipFunction.setFunction(InputFunctions::trapmf);
        QString trimFunctionValues = functionValues.mid(1, functionValues.size() - 2);
        QStringList splitValues = trimFunctionValues.split(" ");
        if (splitValues.size() == 4)
        {
            TrapMF trapMF = TrapMF();
            trapMF.setA(splitValues[0].toDouble());
            trapMF.setB(splitValues[1].toDouble());
            trapMF.setC(splitValues[2].toDouble());
            trapMF.setD(splitValues[3].toDouble());
            membershipFunction.setTrapmf(trapMF);
            m_inputMembershipFisFunction = membershipFunction;
        }
        else
        {
            throw std::exception("Função de pertinência trapezoidal com número incorreto de parâmetros!");
        }
    }
    else if (functionName == "gaussmf")
    {
        InputMembershipFunction membershipFunction = InputMembershipFunction();
        membershipFunction.setName(mfName);
        membershipFunction.setFunction(InputFunctions::gaussmf);
        QString trimFunctionValues = functionValues.mid(1, functionValues.size() - 2);
        QStringList splitValues = trimFunctionValues.split(" ");
        if (splitValues.size() == 2)
        {
            GaussMF gaussmf = GaussMF();
            gaussmf.setSigma(splitValues[0].toDouble());
            gaussmf.setMean(splitValues[1].toDouble());
            membershipFunction.setGaussmf(gaussmf);
            m_inputMembershipFisFunction = membershipFunction;
        }
        else
        {
            throw std::exception("Função de pertinência gaussiana com número incorreto de parâmetros!");
        }
    }
    else if (functionName == "gauss2mf")
    {
        InputMembershipFunction membershipFunction = InputMembershipFunction();
        membershipFunction.setName(mfName);
        membershipFunction.setFunction(InputFunctions::gauss2mf);
        QString trimFunctionValues = functionValues.mid(1, functionValues.size() - 2);
        QStringList splitValues = trimFunctionValues.split(" ");
        if (splitValues.size() == 4)
        {
            Gauss2MF gauss2mf = Gauss2MF();
            gauss2mf.setSigma1(splitValues[0].toDouble());
            gauss2mf.setMean1(splitValues[1].toDouble());
            gauss2mf.setSigma2(splitValues[2].toDouble());
            gauss2mf.setMean2(splitValues[3].toDouble());
            membershipFunction.setGauss2mf(gauss2mf);
            m_inputMembershipFisFunction = membershipFunction;
        }
        else
        {
            throw std::exception("Função de pertinência combinação de duas curvas gaussianas com número incorreto de parâmetros!");
        }
    }
    else
    {
        throw std::exception("Função de pertinência " + functionName.toLocal8Bit() + " não implementada para os Inputs!");
    }
}

void MembershipFunctionFisService::createOutputMembershipFisFunction(const QString &mfName,
                                                               const QString &functionName,
                                                               const QString &functionValues,
                                                               const int numberOfInputs)
{
    if (functionName == "linear")
    {
        OutputMembershipFunction membershipFunction = OutputMembershipFunction();
        membershipFunction.setName(mfName);
        membershipFunction.setFunction(OutputFunctions::linear);
        QString linearFunctionValues = functionValues.mid(1, functionValues.size() - 2);
        QStringList splitValues = linearFunctionValues.split(" ");
        if (splitValues.size() == (numberOfInputs + 1))
        {
            LinearMF linearMF = LinearMF();
            for (short i = 0; i < (numberOfInputs + 1); ++i)
            {
                linearMF.addParams((i + 1), splitValues[i].toDouble());
            }
            membershipFunction.setLinearmf(linearMF);
            m_outputMembershipFisFunction = membershipFunction;
        }
        else
        {
            throw std::exception("Função de pertinência linear com número incorreto de parâmetros!");
        }
    }
    else if (functionName == "constant")
    {
        OutputMembershipFunction membershipFunction = OutputMembershipFunction();
        membershipFunction.setName(mfName);
        membershipFunction.setFunction(OutputFunctions::constant);
        QString constantFunctionValues = functionValues.mid(1, functionValues.size() - 2);
        QStringList splitValues = constantFunctionValues.split(" ");
        if (splitValues.size() == 1)
        {
            ConstantMF constantMF = ConstantMF();
            constantMF.setValue(splitValues[0].toDouble());
            membershipFunction.setConstantmf(constantMF);
            m_outputMembershipFisFunction = membershipFunction;
        }
        else
        {
            throw std::exception("Função de pertinência constant com número incorreto de parâmetros!");
        }
    }
    else
    {
        throw std::exception("Função de pertinência " + functionName.toLocal8Bit() + " não implementada para os Outputs!");
    }
}

InputMembershipFunction MembershipFunctionFisService::getInputMembershipFisFunction() const
{
    return m_inputMembershipFisFunction;
}

void MembershipFunctionFisService::setInputMembershipFisFunction(const InputMembershipFunction &inputMembershipFunction)
{
    m_inputMembershipFisFunction = inputMembershipFunction;
}

OutputMembershipFunction MembershipFunctionFisService::getOutputMembershipFisFunction() const
{
    return m_outputMembershipFisFunction;
}

void MembershipFunctionFisService::setOutputMembershipFisFunction(const OutputMembershipFunction &outputMembershipFisFunction)
{
    m_outputMembershipFisFunction = outputMembershipFisFunction;
}


}
}
}
}
