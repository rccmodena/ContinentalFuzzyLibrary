#include "continental/fuzzy/service/fis/FisService.h"

using namespace continental::fuzzy::domain::fis;
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

void FisService::createSystemFromList(const std::list<QString> &systemList)
{
    for (QString line : systemList)
    {
        // Divide a string das linhas no sinal de "=" em nome e valor
        QStringList splitLine = line.split("=");
        const QString systemField = splitLine[0];
        const QString systemFieldValue = splitLine[1].replace("'","");

        // Preenche os atributos da classe baseado nas entradas do arquivo .fis
        if (systemField == "Name")
        {
            m_system.setName(systemFieldValue);
        }
        else if (systemField == "Type")
        {
            if (systemFieldValue == "sugeno")
            {
                m_system.setType(ControllerType::sugeno);
            }
            else
            {
                throw std::exception("Controlador " + systemFieldValue.toLocal8Bit() + " não foi implementado!");
            }
        }
        else if (systemField == "Version")
        {
            m_system.setVersion(systemFieldValue);
        }
        else if (systemField == "NumInputs")
        {
            m_system.setNumInputs(systemFieldValue.toInt());
        }
        else if (systemField == "NumOutputs")
        {
            m_system.setNumOutputs(systemFieldValue.toInt());
        }
        else if (systemField == "NumRules")
        {
            m_system.setNumRules(systemFieldValue.toInt());
        }
        else if (systemField == "AndMethod")
        {
            if (systemFieldValue == "min")
            {
                m_system.setAndMethod(AndMethods::min);
            }
            else if (systemFieldValue == "prod")
            {
                m_system.setAndMethod(AndMethods::prod);
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
                m_system.setOrMethod(OrMethods::max);
            }
            else if (systemFieldValue == "probor")
            {
                m_system.setOrMethod(OrMethods::probor);
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
                m_system.setImpMethod(ImpMethods::prod);
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
                m_system.setAggMethod(AggMethods::sum);
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
                m_system.setDefuzzMethod(DefuzzMethods::wtaver);
            }
            else if (systemFieldValue == "wtsum")
            {
                m_system.setDefuzzMethod(DefuzzMethods::wtsum);
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
    if (m_system.getName() == "")
    {
        throw std::exception("O nome não foi informado!");
    }
    else if (m_system.getFilename() == "")
    {
        throw std::exception("O nome do arquivo não foi informado!");
    }
    else if (m_system.getType() == ControllerType::none)
    {
        throw std::exception("O tipo não foi informado!");
    }
    else if (m_system.getVersion() == "")
    {
        throw std::exception("A versão não foi informada!");
    }
    else if (m_system.getNumInputs() == 0)
    {
        throw std::exception("O número de antecedentes não foi informado!");
    }
    else if (m_system.getNumOutputs() == 0)
    {
        throw std::exception("O número de consequentes não foi informado!");
    }
    else if (m_system.getNumOutputs() > 1)
    {
        throw std::exception("Somente é permitido um consequente!");
    }
    else if (m_system.getNumRules() == 0)
    {
        throw std::exception("O número de regras não foi informado!");
    }
    else if (m_system.getAndMethod() == AndMethods::none)
    {
        throw std::exception("O método AND fuzzy não foi informado!");
    }
    else if (m_system.getOrMethod() == OrMethods::none)
    {
        throw std::exception("O método OR fuzzy não foi informado!");
    }
    else if (m_system.getImpMethod() == ImpMethods::none)
    {
        throw std::exception("O método de implicação não foi informado!");
    }
    else if (m_system.getAggMethod() == AggMethods::none)
    {
        throw std::exception("O método de agregação não foi informado!");
    }
    else if (m_system.getDefuzzMethod() == DefuzzMethods::none)
    {
        throw std::exception("O método de defuzzificação não foi informado!");
    }
}

void FisService::createInputsFromMap(const std::map<int, std::list<QString>> &inputsMap)
{
    // Verifica se a quantidade de antecedentes está correta
    int sizeInputMap = static_cast<int>(inputsMap.size());
    if (sizeInputMap == m_system.getNumInputs())
    {
        // Percorre cada um dos antecedentes
        for (auto const& inputList : inputsMap)
        {
            InputFisService fisInputService;
            fisInputService.createFromFisBlock(inputList.second);
            m_system.addInput(inputList.first, fisInputService.getInput());
        }
    }
    else
    {
        throw std::exception("Quantidade de antecedentes é diferente do número de antecedentes informado no bloco System!");
    }
}

void FisService::createOutputsFromMap(const std::map<int, std::list<QString>> &outputsMap)
{
    // Verifica se a quantidade de consequentes está correta
    int sizeOutputMap = static_cast<int>(outputsMap.size());
    if (sizeOutputMap == m_system.getNumOutputs())
    {
        // Percorre cada um dos antecedentes
        for (auto const& outputList : outputsMap)
        {
            OutputFisService fisOutputService;
            fisOutputService.createFromFisBlock(outputList.second, m_system.getNumInputs());
            m_system.addOutput(outputList.first, fisOutputService.getOutput());
        }
    }
    else
    {
        throw std::exception("Quantidade de consequentes é diferente do número de consequentes informado no bloco System!");
    }
}

void FisService::createRulesFromList(const std::list<QString> &ruleList)
{

    // Verifica se a quantidade de regras está correta
    int sizeRuleList = static_cast<int>(ruleList.size());
    if (sizeRuleList == m_system.getNumRules())
    {
        int ruleNumber = 1;
        // Percorre cada uma das regras
        for (auto const& line : ruleList)
        {
            Rule fisRule;

            // Separa a string em antecedentes e o restante
            QStringList splitRule = line.split(",");
            QStringList splitRuleInputs = splitRule[0].split(" ");

            // Armazena as entradas das regras
            if (splitRuleInputs.size() == m_system.getNumInputs())
            {
                std::map<int, RuleVariable> inputsRuleMap;
                int numInputRule = 1;
                for (QString const& ruleInputString : splitRuleInputs)
                {
                    RuleVariable ruleInput;
                    int ruleInputValue = ruleInputString.toInt();

                    // Se o valor do antecedente for zero pula para o próximo
                    if (ruleInputValue == 0)
                    {
                        continue;
                    }
                    // Verificar o operador NOT
                    else if (ruleInputValue < 0)
                    {
                        ruleInput.setInputVarNot(true);
                    }
                    else
                    {
                        ruleInput.setInputVarNot(false);
                    }
                    ruleInput.setIndex(std::abs(ruleInputValue));
                    inputsRuleMap.insert(std::pair<int, RuleVariable>(numInputRule, ruleInput));
                    ++numInputRule;
                }
                fisRule.setInputs(inputsRuleMap);
            }
            else
            {
                throw std::exception("Quantidade de antecedentes da regra é diferente do número de antecedentes informado no bloco System!");
            }

            // Separa o consequentes do tipo de conector
            QStringList splitOutputConnector = splitRule[1].split(":");

            // Separa o consequentes do peso
            QStringList splitOutputWeight = splitOutputConnector[0].simplified().split(" ");

            // Separa os consequentes
            QStringList splitRuleOutputs = splitOutputWeight[0].split(" ");

            // Armazena a saída das regras
            if (splitRuleOutputs.size() == m_system.getNumOutputs())
            {
                std::map<int, RuleVariable> outputsRuleMap;
                int numInputRule = 1;
                for (QString const& ruleOuputString : splitRuleOutputs)
                {
                    RuleVariable ruleOutput;
                    int ruleOutputValue = ruleOuputString.toInt();

                    // Se o valor do antecedente for zero pula para o próximo
                    if (ruleOutputValue == 0)
                    {
                        continue;
                    }
                    // Verificar o operador NOT
                    else if (ruleOutputValue < 0)
                    {
                        throw std::exception("O consequente da regra não pode ser negado!");
                    }
                    else
                    {
                        ruleOutput.setInputVarNot(false);
                    }
                    ruleOutput.setIndex(ruleOutputValue);
                    outputsRuleMap.insert(std::pair<int, RuleVariable>(numInputRule, ruleOutput));
                    ++numInputRule;
                }
                fisRule.setOutputs(outputsRuleMap);
            }
            else
            {
                throw std::exception("Quantidade de consequentes da regra é diferente do número de consequentes informado no bloco System!");
            }

            // Salva o peso do consequente
            int outputWeightSize = splitOutputWeight[1].size();
            fisRule.setWeight(splitOutputWeight[1].mid(1, (outputWeightSize - 2)).toDouble());

            // Salva os conectores dos antecedentes
            fisRule.setConnection(static_cast<Connections>(splitOutputConnector[1].toInt()));

            m_system.addRule(ruleNumber, fisRule);
            ++ruleNumber;
        }
    }
    else
    {
        throw std::exception("Quantidade de regras é diferente do número de regras informado no bloco System!");
    }
}


void FisService::createFaciesAssociationConverter()
{
    const int sizeOutputMfs = static_cast<int>(m_system.getOutputs().at(1).getOutputMfs().size());
    for (int index = 1; index <=sizeOutputMfs; ++index)
    {
        const membershipfunction::OutputMembershipFunction &outputMfs = m_system.getOutputs().at(1).getOutputMfs().at(index);
        if (outputMfs.getFunction() == OutputFunctions::constant)
        {
            if (outputMfs.getName() == "Cape")
            {
                m_system.addFaciesAssociationConversion(outputMfs.getConstantmf().getValue(), static_cast<int>(FaciesAssociationsImplemented::Cape));
            }
            else if (outputMfs.getName() == "ShallowPlain")
            {
                m_system.addFaciesAssociationConversion(outputMfs.getConstantmf().getValue(), static_cast<int>(FaciesAssociationsImplemented::ShallowPlain));
            }
            else if (outputMfs.getName() == "LowEnergyUnderwaterPlain")
            {
                m_system.addFaciesAssociationConversion(outputMfs.getConstantmf().getValue(), static_cast<int>(FaciesAssociationsImplemented::LowEnergyUnderwaterPlain));
            }
            else if (outputMfs.getName() == "InterpatchesPlain")
            {
                m_system.addFaciesAssociationConversion(outputMfs.getConstantmf().getValue(), static_cast<int>(FaciesAssociationsImplemented::InterpatchesPlain));
            }
            else if (outputMfs.getName() == "ClayeyEmbayment")
            {
                m_system.addFaciesAssociationConversion(outputMfs.getConstantmf().getValue(), static_cast<int>(FaciesAssociationsImplemented::ClayeyEmbayment));
            }
            else if (outputMfs.getName() == "StromatoliteEmbayment")
            {
                m_system.addFaciesAssociationConversion(outputMfs.getConstantmf().getValue(), static_cast<int>(FaciesAssociationsImplemented::StromatoliteEmbayment));
            }
            else if (outputMfs.getName() == "LaminiteRamp")
            {
                m_system.addFaciesAssociationConversion(outputMfs.getConstantmf().getValue(), static_cast<int>(FaciesAssociationsImplemented::LaminiteRamp));
            }
            else if (outputMfs.getName() == "ModerateEnergyIntraclastic")
            {
                m_system.addFaciesAssociationConversion(outputMfs.getConstantmf().getValue(), static_cast<int>(FaciesAssociationsImplemented::ModerateEnergyIntraclastic));
            }
            else if (outputMfs.getName() == "HighEnergyIntraclastic")
            {
                m_system.addFaciesAssociationConversion(outputMfs.getConstantmf().getValue(), static_cast<int>(FaciesAssociationsImplemented::HighEnergyIntraclastic));
            }
            else if (outputMfs.getName() == "SubCoastal")
            {
                m_system.addFaciesAssociationConversion(outputMfs.getConstantmf().getValue(), static_cast<int>(FaciesAssociationsImplemented::SubCoastal));
            }
            else if (outputMfs.getName() == "Reef")
            {
                m_system.addFaciesAssociationConversion(outputMfs.getConstantmf().getValue(), static_cast<int>(FaciesAssociationsImplemented::Reef));
            }
            else if (outputMfs.getName() == "ClayeyClasticDeposit")
            {
                m_system.addFaciesAssociationConversion(outputMfs.getConstantmf().getValue(), static_cast<int>(FaciesAssociationsImplemented::ClayeyClasticDeposit));
            }
            else if (outputMfs.getName() == "Undefined")
            {
                m_system.addFaciesAssociationConversion(outputMfs.getConstantmf().getValue(), static_cast<int>(FaciesAssociationsImplemented::Undefined));
            }
            else
            {
                throw std::exception("A Associação de fácies não cadastrada!");
            }
        }
        else
        {
            throw std::exception("A conversão de associação de fácies não é permitida para a função linear!");
        }
    }
}

void FisService::validImport()
{
    if (m_system.getFilename() == "")
    {
        throw std::exception("Não foi importada a quantidade correta de antecedentes!");
    }
    else if (static_cast<int>(m_system.getInputs().size()) != m_system.getNumInputs())
    {
        throw std::exception("Não foi importada a quantidade correta de antecedentes!");
    }
    else if (static_cast<int>(m_system.getOutputs().size()) != m_system.getNumOutputs())
    {
        throw std::exception("Não foi importada a quantidade correta de consequentes!");
    }
    else if (static_cast<int>(m_system.getRules().size()) != m_system.getNumRules())
    {
        throw std::exception("Não foi importada a quantidade correta de regras!");
    }
}

System& FisService::importFile(const QString &filename, bool useDictFaciesAssociation)
{

    // Armazena o caminho do arquivo .fis
    m_system.setFilename(filename);

    // Armazena o bloco que está sendo lido do arquivo .fis
    Blocks fisBlock = Blocks::none;

    // Armazena as informações sobre o sistema
    std::list<QString> systemList;

    // Armazena as informações sobre os antecedentes
    std::map<int, std::list<QString>> inputsMap;

    // Armazena as informações sobre os consequentes
    std::map<int, std::list<QString>> outputsMap;

    // Armazena as informações sobre as regras
    std::list<QString> rulesList;

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

            if (line.length() == 0)
            {
                continue;
            }
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
                    int sizeInputMap = static_cast<int>(inputsMap.size()) + 1;

                    // Verifica se os antecedentes estão ordenados
                    if (linguisticVariableNumber != sizeInputMap)
                    {
                        throw std::exception("Os antecedente não estão ordenados!");
                    }
                    inputsMap.insert(std::pair<int, std::list<QString>>(linguisticVariableNumber, std::list<QString>()));
                }

                // Verifica se está no bloco de consequentes
                else if (line.left(7) == "[Output")
                {
                    fisBlock = Blocks::outputs;

                    // Obtém o número do consequentes
                    linguisticVariableNumber = line.mid(7, 1).toInt();
                    int sizeOutputMap = static_cast<int>(outputsMap.size()) + 1;

                    // Verifica se os consequentes estão ordenados
                    if (linguisticVariableNumber != sizeOutputMap)
                    {
                        throw std::exception("Os consequentes não estão ordenados!");
                    }
                    outputsMap.insert(std::pair<int, std::list<QString>>(linguisticVariableNumber, std::list<QString>()));
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
                            systemList.push_back(line);
                            break;
                        case Blocks::inputs:
                            // Adciona a linha no antecedente com o número correto
                            inputsMap[linguisticVariableNumber].push_back(line);
                            break;
                        case Blocks::outputs:
                            // Adciona a linha no consequente com o número correto
                            outputsMap[linguisticVariableNumber].push_back(line);
                            break;
                        case Blocks::rules:
                            rulesList.push_back(line);
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
    if (useDictFaciesAssociation)
    {
        createFaciesAssociationConverter();
    }

    // Valida a importação
    validImport();

    return m_system;
}

}
}
}
}
