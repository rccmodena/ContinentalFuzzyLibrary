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
            m_system.addInput(fisInputService.getInput());
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
            m_system.addOutput(fisOutputService.getOutput());
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
                std::vector<RuleVariable> inputsRuleMap;

                int indexOfInput = 0;

                for (QString const& ruleInputString : splitRuleInputs)
                {
                    RuleVariable ruleInput;
                    int ruleInputValue = ruleInputString.toInt();

                    // Se o valor do antecedente for zero pula para o próximo
                    if (ruleInputValue == 0)
                    {
                        ++indexOfInput;
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
                    ruleInput.setIndexOfInput(indexOfInput);
                    ruleInput.setIndex(std::abs(ruleInputValue) - 1);
                    inputsRuleMap.push_back(ruleInput);
                    ++indexOfInput;

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
                std::vector<RuleVariable> outputsRuleMap(splitRuleOutputs.length());
                int numInputRule = 0;
                for (QString const& ruleOuputString : splitRuleOutputs)
                {
                    RuleVariable ruleOutput;
                    int ruleOutputValue = ruleOuputString.toInt();

                    // Verificar o operador NOT
                    if (ruleOutputValue < 0)
                    {
                        throw std::exception("O consequente da regra não pode ser negado!");
                    }
                    else
                    {
                        ruleOutput.setInputVarNot(false);
                    }
                    ruleOutput.setIndex(ruleOutputValue - 1);
                    outputsRuleMap[numInputRule] = ruleOutput;
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

            m_system.addRule(fisRule);
        }
    }
    else
    {
        throw std::exception("Quantidade de regras é diferente do número de regras informado no bloco System!");
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


void FisService::exportFile(const QString &filename, const domain::fis::System &system)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        throw std::exception("Não foi possível gravar o arquivo fis");
    }
    QTextStream out(&file);
    out << "[System]\n";
    out << "Name=" << "'" << system.getName() << "'" << "\n";
    out << "Type=" << (system.getType() == definition::ControllerType::mamdani ? "'mandani'" : "'sugeno'") << "\n";
    out << "Version=" <<  system.getVersion() << "\n";
    out << "NumInputs=" << QString::number(system.getNumInputs())<<  "\n";
    out << "NumOutputs=" << QString::number(system.getNumOutputs()) << "\n";
    out << "NumRules=" << QString::number(system.getNumRules()) << "\n";
    out << "AndMethod=" << (system.getAndMethod() == definition::AndMethods::min ? "'min'" : "'prod'") << "\n";
    out << "OrMethod=" << (system.getOrMethod() == definition::OrMethods::max ? "'max'" : "'probor'") << "\n";
    out << "ImpMethod=" << "'prod'"<< "\n";
    out << "AggMethod=" << "'sum'"<< "\n";
    out << "DefuzzMethod=" << (system.getDefuzzMethod() == definition::DefuzzMethods::wtaver ? "'wtaver'" : "'wtsum'") << "\n";

    out << "\n";
    size_t count = 1;
    for (auto input : system.getInputs())
    {
        out << "[Input" << QString::number(count) <<"]"<< "\n";
        out <<"Name="<<"'"<< input.getName() <<"'"<<"\n";
        out <<"Range="<< "[" << input.getRange().first << " " << input.getRange().second << "]" << "\n";
        out <<"NumMFs="<< QString::number(input.getNumMfs()) << "\n";

        size_t countMfs = 1;
        for (auto mfs : input.getInputMfs())
        {
            out << "MF"<<QString::number(countMfs)<<"="<< "'" <<mfs.getName()<< "'" << ":";

            switch(mfs.getFunction())
            {

            case InputFunctions::gauss2mf:
                out << "'gauss2mf',[" << QString::number(mfs.getGauss2mf().getMean1()) << " "
                    << QString::number(mfs.getGauss2mf().getMean2()) << " "
                    << QString::number(mfs.getGauss2mf().getSigma1()) << " "
                    << QString::number(mfs.getGauss2mf().getSigma2()) << "] \n";
                break;

            case InputFunctions::gaussmf:
                out << "'gaussmf',["<< QString::number(mfs.getGaussmf().getMean()) << " "
                    << QString::number(mfs.getGaussmf().getSigma()) << "] \n";

                break;

            case InputFunctions::trapmf:
                out << "'trapmf',["<< QString::number(mfs.getTrapmf().getA()) << " "
                    << QString::number(mfs.getTrapmf().getB()) << " "
                    << QString::number(mfs.getTrapmf().getC()) << " "
                    << QString::number(mfs.getTrapmf().getD()) << "] \n";


                break;

            case InputFunctions::trimf:
                out << "'trimf',[" << QString::number(mfs.getTrimf().getA()) << " "
                    << QString::number(mfs.getTrimf().getB()) << " "
                    << QString::number(mfs.getTrimf().getC()) << "] \n";;
                break;
            }

            countMfs++;
        }

        out << "\n";
        count++;
    }


    count = 1;
    for (auto output : system.getOutputs())
    {
        out << "[Output" << QString::number(count) <<"]"<< "\n";
        out <<"Name="<<"'"<< output.getName() <<"'"<<"\n";
        out <<"Range="<< "[" << output.getRange().first << " " << output.getRange().second << "]" << "\n";
        out <<"NumMFs="<< QString::number(output.getNumMfs()) << "\n";
        size_t countMfs = 1;

        for (auto mfs : output.getOutputMfs())
        {
            out << "MF"<<QString::number(countMfs)<<"="<< "'" <<mfs.getName()<< "'" << ":";

            switch(mfs.getFunction())
            {

            case OutputFunctions::constant:
                out << "'constant',[" << QString::number(mfs.getConstantmf().getValue()) << "] \n";

                break;


            case OutputFunctions::linear:
                // OLHAR LISTA DE PARAMETROS DE OUTPUT LINEAR
                out << "'linear',[" ;
                for (auto linearParams : mfs.getLinearmf().getParams())
                {
                    out << QString::number(linearParams) << " ";

                    std::cout << 1;
                }
                out << "]\n";
            }

            countMfs++;
        }
        out << "\n";
        count++;
    }


    out << "[Rules] \n";
    size_t numOfOtherChars = 2;
    size_t numOfCols = system.getNumInputs() + system.getNumOutputs() + numOfOtherChars;
    size_t numOfLines = system.getNumRules();

    std::vector<std::vector<float>> rulesForPrint;
    rulesForPrint.resize(numOfLines);

    for (size_t line = 0; line < numOfLines; line++)
    {
        rulesForPrint[line].resize(numOfCols);
    }



    size_t line = 0;
    for (auto rule : system.getRules())
    {

        int col = 0;
        for (auto ruleInputs : rule.getInputs())
        {
            rulesForPrint[line][ruleInputs.getIndexOfInput()] = (ruleInputs.getInputVarNot() == true ? -(ruleInputs.getIndex() + 1) : ruleInputs.getIndex() + 1);
            col++;
        }

        col = system.getNumInputs();

        for (auto ruleOutput : rule.getOutputs())
        {

            rulesForPrint[line][col] = (ruleOutput.getInputVarNot() == true ? -(ruleOutput.getIndex() + 1) : ruleOutput.getIndex() + 1);
            ++col;
        }

        col = system.getNumInputs() + system.getNumOutputs();
        rulesForPrint[line][col] = rule.getWeight();
        ++col;
        rulesForPrint[line][col] = (rule.getConnection() == definition::Connections::AND ? 1 : 2);

        ++line;
    }


    for (line = 0; line < numOfLines; ++line)
    {

        for (int input = 0; input <= system.getNumInputs() - 1; input++)
        {
            out << QString::number(rulesForPrint[line][input]);
            if (input != system.getNumInputs() - 1)
            {
                out << " ";
            }
            else
            {
                out << ",";
            }

        }


        out << " ";

        for (int output = 0; output < system.getNumOutputs(); ++output)
        {
            out << QString::number(rulesForPrint[line][system.getNumInputs() + output]);
            if (output != system.getNumOutputs() - 1)
            {
                out << " ";
            }

        }

        out << " (" << QString::number(rulesForPrint[line][system.getNumInputs() + system.getNumInputs() - 1]) << ") : ";

        out << QString::number(rulesForPrint[line][system.getNumInputs() + system.getNumInputs()]);

        out << "\n";

    }




    file.close();

}

System& FisService::importFile(const QString &filename)
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

    // Valida a importação
    validImport();

    return m_system;
}

}
}
}
}
