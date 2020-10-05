#include "continental/fuzzy/service/fis/OutputService.h"

using namespace continental::fuzzy::domain::fis::variable;
using namespace continental::fuzzy::service::fis;

namespace continental {
namespace fuzzy {
namespace service {
namespace fis {

OutputService::OutputService()
{

}

OutputService::~OutputService()
{

}

void OutputService::createFromFisBlock(const std::list<QString> &fisOutputList, const int numInputs)
{
    // Armazena as informações sobre as funções de pertinência
    std::map<int, QString> membershipFunctionsMap = std::map<int, QString>();

    for (QString line : fisOutputList)
    {
        // Divide a string das linhas no sinal de "=" em nome e valor
        QStringList splitLine = line.split("=");
        const QString systemField = splitLine[0];
        const QString systemFieldValue = splitLine[1].replace("'","");

        // Preenche os atributos da classe baseado nas  entradas do arquivo .fis
        if (systemField == "Name")
        {
            m_output.setName(systemFieldValue);
        }
        else if (systemField == "Range")
        {
            int rangeValuesSize = systemFieldValue.size();

            // Remove os colchetes
            QString rangeValues = systemFieldValue.mid(1, rangeValuesSize - 2);
            // Separa os valores
            QStringList rangeValuesSplitted = rangeValues.split(" ");
            std::pair<float, float> rangePair = std::pair<float, float>();
            rangePair.first = rangeValuesSplitted[0].toFloat();
            rangePair.second = rangeValuesSplitted[1].toFloat();
            m_output.setRange(rangePair);
        }
        else if (systemField == "NumMFs")
        {
            m_output.setNumMfs(systemFieldValue.toInt());
        }
        else if (systemField.left(2) == "MF")
        {
            int fieldSize = systemField.size();
            int mfsNumber = systemField.right(fieldSize - 2).toInt();
            membershipFunctionsMap.insert(std::pair<int, QString>(mfsNumber, systemFieldValue));
        }
        else
        {
            throw std::exception("Entrada " + systemField.toLocal8Bit() + " não é válida para o bloco de Inputs!");
        }
    }

    // Verifica se todos os atributos da variável foram preenchidos
    if (m_output.getName() == "")
    {
        throw std::exception("O nome da variável não foi informado!");
    }
    else if ((static_cast<int>(m_output.getRange().first * 1000) == 0) && (static_cast<int>(m_output.getRange().second * 1000) == 0))
    {
        throw std::exception("A amplitude do conjunto da variável não foi informada!");
    }
    else if (m_output.getNumMfs() == 0)
    {
        throw std::exception("O número de funções de pertinência da variável não foi informado!");
    }

    // Verifica se a quantidade de funções de pertinência está correta
    int sizeMfsMap = static_cast<int>(membershipFunctionsMap.size());
    if (sizeMfsMap == m_output.getNumMfs())
    {
        for (auto const& item : membershipFunctionsMap)
        {
            // Remover aspas e extrair nome de identificação
            QString rawItem = item.second;
            QStringList itemSplitted = rawItem.replace("'","").split(":");
            QString mfName = itemSplitted[0];

            // Atribui o nome da função
            QStringList functionSplitted = itemSplitted[1].split(",");
            QString functionName = functionSplitted[0];
            QString functionValues = functionSplitted[1];

            MembershipFunctionService mfService = MembershipFunctionService();
            mfService.createOutputMembershipFunction(mfName, functionName, functionValues, numInputs);
            m_output.addOutputMfs(item.first, mfService.getOutputMembershipFunction());
        }
    }
    else
    {
        throw std::exception("Quantidade de funções de pertinência para a variável " + m_output.getName().toLocal8Bit() + " é diferente do número de funções de pertinência informado no bloco!");
    }
}

Output OutputService::getOutput() const
{
    return m_output;
}

void OutputService::setOutput(const Output &output)
{
    m_output = output;
}


}
}
}
}
