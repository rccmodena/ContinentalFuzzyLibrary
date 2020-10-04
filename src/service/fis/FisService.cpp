#include "continental/fuzzy/service/fis/FisService.h"

using namespace continental::fuzzy::domain::fis;
using namespace continental::fuzzy::domain::fis::rulevariable;
using namespace continental::fuzzy::domain::fis::definition;
using namespace continental::fuzzy::service::fis;

namespace continental {
namespace fuzzy {
namespace service {
namespace fis {

FisService::FisService()
{

}

FisService::~FisService()
{

}

void FisService::createSystemFromList(const std::shared_ptr<std::list<QString>> systemList)
{
    for (QString line : (*systemList))
    {
        // Divide a string das linhas no sinal de "=" em nome e valor
        QStringList splitLine = line.split("=");
        const QString systemField = splitLine[0];
        const QString systemFieldValue = splitLine[1].replace("'","");

        // Preenche os atributos da classe baseado nas entradas do arquivo .fis
        if (systemField == "Name")
        {
            m_system->setName(systemFieldValue);
        }
        else if (systemField == "Type")
        {
            if (systemFieldValue == "sugeno")
            {
                m_system->setType(ControllerType::sugeno);
            }
            else
            {
                throw std::exception("Controlador " + systemFieldValue.toLocal8Bit() + " não foi implementado!");
            }
        }
        else if (systemField == "Version")
        {
            m_system->setVersion(systemFieldValue);
        }
        else if (systemField == "NumInputs")
        {
            m_system->setNumInputs(systemFieldValue.toInt());
        }
        else if (systemField == "NumOutputs")
        {
            m_system->setNumOutputs(systemFieldValue.toInt());
        }
        else if (systemField == "NumRules")
        {
            m_system->setNumRules(systemFieldValue.toInt());
        }
        else if (systemField == "AndMethod")
        {
            if (systemFieldValue == "min")
            {
                m_system->setAndMethod(AndMethods::min);
            }
            else if (systemFieldValue == "prod")
            {
                m_system->setAndMethod(AndMethods::prod);
            }
            else
            {
                throw std::exception("O método AND " + systemFieldValue.toLocal8Bit() + " não foi implementado para inferência Sugeno!");
            }
        }
        else if (systemField == "OrMethod")
        {
            if (systemFieldValue == "max")
            {
                m_system->setOrMethod(OrMethods::max);
            }
            else if (systemFieldValue == "probor")
            {
                m_system->setOrMethod(OrMethods::probor);
            }
            else
            {
                throw std::exception("O método OR " + systemFieldValue.toLocal8Bit() + " não foi implementado para inferência Sugeno!");
            }
        }
        else if (systemField == "ImpMethod")
        {
            if (systemFieldValue == "prod")
            {
                m_system->setImpMethod(ImpMethods::prod);
            }
            else
            {
                throw std::exception("O método de implicação " + systemFieldValue.toLocal8Bit() + " não foi implementado para inferência Sugeno!");
            }
        }
        else if (systemField == "AggMethod")
        {
            if (systemFieldValue == "sum")
            {
                m_system->setAggMethod(AggMethods::sum);
            }
            else
            {
                throw std::exception("O método de agregação " + systemFieldValue.toLocal8Bit() + " não foi implementado para inferência Sugeno!");
            }
        }
        else if (systemField == "DefuzzMethod")
        {
            if (systemFieldValue == "wtaver")
            {
                m_system->setDefuzzMethod(DefuzzMethods::wtaver);
            }
            else if (systemFieldValue == "wtsum")
            {
                m_system->setDefuzzMethod(DefuzzMethods::wtsum);
            }
            else
            {
                throw std::exception("O método de defuzzificação " + systemFieldValue.toLocal8Bit() + " não foi implementado para inferência Sugeno!");
            }
        }
    }
}

void FisService::validSystem()
{
    if (m_system->getName() == "")
    {
        throw std::exception("O nome não foi informado!");
    }
    else if (m_system->getFilename() == "")
    {
        throw std::exception("O nome do arquivo não foi informado!");
    }
    else if (m_system->getType() == ControllerType::none)
    {
        throw std::exception("O tipo não foi informado!");
    }
    else if (m_system->getVersion() == "")
    {
        throw std::exception("A versão não foi informada!");
    }
    else if (m_system->getNumInputs() == 0)
    {
        throw std::exception("O número de antecedentes não foi informado!");
    }
    else if (m_system->getNumOutputs() == 0)
    {
        throw std::exception("O número de consequentes não foi informado!");
    }
    else if (m_system->getNumRules() == 0)
    {
        throw std::exception("O número de regras não foi informado!");
    }
    else if (m_system->getAndMethod() == AndMethods::none)
    {
        throw std::exception("O método AND fuzzy não foi informado!");
    }
    else if (m_system->getOrMethod() == OrMethods::none)
    {
        throw std::exception("O método OR fuzzy não foi informado!");
    }
    else if (m_system->getImpMethod() == ImpMethods::none)
    {
        throw std::exception("O método de implicação não foi informado!");
    }
    else if (m_system->getAggMethod() == AggMethods::none)
    {
        throw std::exception("O método de agregação não foi informado!");
    }
    else if (m_system->getDefuzzMethod() == DefuzzMethods::none)
    {
        throw std::exception("O método de defuzzificação não foi informado!");
    }
}

void FisService::createInputsFromMap(const std::shared_ptr<std::map<int, std::list<QString>>> inputsMap)
{
    // Verifica se a quantidade de antecedentes está correta
    int sizeInputMap = static_cast<int>(inputsMap->size());
    if (sizeInputMap == m_system->getNumInputs())
    {
        // Percorre cada um dos antecedentes
        for (auto const& inputList : (*inputsMap))
        {
            auto fisInputService = InputService();
            auto inputListPointer = std::make_shared<std::list<QString>>(inputList.second);
            fisInputService.createFromFisBlock(inputListPointer);
            m_system->addInput(inputList.first, fisInputService.getInput());
        }
    }
    else
    {
        throw std::exception("Quantidade de antecedentes é diferente do número de antecedentes informado no bloco System!");
    }
    }

void FisService::createOutputsFromMap(const std::shared_ptr<std::map<int, std::list<QString>>> outputsList)
{

}

std::shared_ptr<RuleInput> FisService::createRuleInputsFromList(const std::shared_ptr<std::map<int, std::list<QString>>> ruleInputsList)
{
    std::shared_ptr<RuleInput> ruleInputs;
    return ruleInputs;
}

std::shared_ptr<RuleOutput> FisService::createRuleOutputsFromList(const std::shared_ptr<std::map<int, std::list<QString>>> ruleOutputsList)
{
    std::shared_ptr<RuleOutput> ruleOutput;
    return ruleOutput;
}

void FisService::createRulesFromList(const std::shared_ptr<std::list<QString>> ruleList)
{

}

void FisService::createFaciesAssociationConverter(const bool &useFaciesAssociationConverter)
{

}

void FisService::validImport()
{

}

std::shared_ptr<System> FisService::importFile(const QString &filename, const bool &useFaciesAssociationConverter)
{

    // Armazena o caminho do arquivo .fis
    m_system->setFilename(filename);

    // Armazena o bloco que está sendo lido do arquivo .fis
    Blocks fisBlock = Blocks::none;

    // Armazena as informações sobre o sistema
    std::shared_ptr<std::list<QString>> systemList = std::make_shared<std::list<QString>>();

    // Armazena as informações sobre os antecedentes
    std::shared_ptr<std::map<int, std::list<QString>>> inputsMap = std::make_shared<std::map<int, std::list<QString>>>();

    // Armazena as informações sobre os consequentes
    std::shared_ptr<std::map<int, std::list<QString>>> outputsMap = std::make_shared<std::map<int, std::list<QString>>>();

    // Armazena as informações sobre as regras
    std::shared_ptr<std::list<QString>> rulesList = std::make_shared<std::list<QString>>();

    // Armazena o número atual do antecedente ou consequente
    int linguisticVariableNumber;

    // Abre o aquivo .fis para a leitura
    QFile fisFile(filename);
    if (fisFile.open(QIODevice::ReadOnly))
    {
        QTextStream fisFileTextStream(&fisFile);

        // Faz a leitura de todas as linhas do arquivo .fis
        while (!fisFileTextStream.atEnd())
        {
            const QString line = fisFileTextStream.readLine();


            if (line[0] == '[')
            {
                // Verifica se está no bloco principal do sistema.
                if (line.left(8) == "[System]")
                {
                    fisBlock = Blocks::system;
                }

                // Verifica se está nos blocos de antecedentes
                else if (line.left(6) == "[Input")
                {
                    fisBlock = Blocks::inputs;

                    // Obtém o número do antecedente
                    linguisticVariableNumber = line.mid(6, 1).toInt();
                    int sizeInputMap = static_cast<int>(inputsMap->size()) + 1;

                    // Verifica se os antecedentes estão ordenados
                    if (linguisticVariableNumber != sizeInputMap)
                    {
                        throw std::exception("Os antecedente não estão ordenados!");
                    }
                    inputsMap->insert(std::pair<int, std::list<QString>>(linguisticVariableNumber, std::list<QString>()));
                }

                // Verifica se está no bloco de consequentes
                else if (line.left(7) == "[Output")
                {
                    fisBlock = Blocks::outputs;

                    // Obtém o número do consequentes
                    linguisticVariableNumber = line.mid(7, 1).toInt();
                    int sizeOutputMap = static_cast<int>(outputsMap->size()) + 1;

                    // Verifica se os consequentes estão ordenados
                    if (linguisticVariableNumber != sizeOutputMap)
                    {
                        throw std::exception("Os consequentes não estão ordenados!");
                    }
                    outputsMap->insert(std::pair<int, std::list<QString>>(linguisticVariableNumber, std::list<QString>()));
                }

                // Verifica se está nos bloco de regras
                else if (line.left(7) == "[Rules]")
                {
                    fisBlock = Blocks::rules;
                }

                // Caso não seja nenhum dos blocos válidos para um arquivo .fis
                else
                {
                    throw std::exception("Bloco " + line.toLocal8Bit() + " não é válido!");
                }
            }
            else
            {
                // Armazena entradas que não sejam vazias
                if (!line.trimmed().isEmpty())
                {
                    switch( fisBlock )
                    {
                        case Blocks::system:
                            systemList->push_back(line);
                            break;
                        case Blocks::inputs:
                            // Adciona a linha no antecedente com o número correto
                            (*inputsMap)[linguisticVariableNumber].push_back(line);
                            break;
                        case Blocks::outputs:
                            // Adciona a linha no consequente com o número correto
                            (*outputsMap)[linguisticVariableNumber].push_back(line);
                            break;
                        case Blocks::rules:
                            rulesList->push_back(line);
                            break;
                        default:
                            throw std::exception("Bloco não identificado!");
                    }
                }
            }
        }
        fisFile.close();
    }

    // Criar os atributos do sistema
    createSystemFromList(systemList);

    // Verificar se todos os atributos do sistema foram preenchidos
    validSystem();

    // Criar os inputs
    createInputsFromMap(inputsMap);

    // Criar os outputs
    createOutputsFromMap(outputsMap);

    // Criar as regras
    createRulesFromList(rulesList);

    // Cria dicionário de fácies
    createFaciesAssociationConverter(useFaciesAssociationConverter);

    // Valida a importação
    validImport();

    return m_system;
}

}
}
}
}
