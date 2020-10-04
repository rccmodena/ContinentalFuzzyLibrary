#include "continental/fuzzy/service/fis/InputService.h"

using namespace continental::fuzzy::domain::fis::variable;

namespace continental {
namespace fuzzy {
namespace service {
namespace fis {

InputService::InputService()
{

}

InputService::~InputService()
{

}

std::shared_ptr<Input> InputService::createFromFisBlock(const std::shared_ptr<std::list<QString>> fisInputList)
{
    // Armazena as informações sobre as funções de pertinência
    std::shared_ptr<std::list<QString>> membershipFunctionsList = std::make_shared<std::list<QString>>();

    for (QString line : (*fisInputList))
    {
        // Divide a string das linhas no sinal de "=" em nome e valor
        QStringList splitLine = line.split("=");
        const QString systemField = splitLine[0];
        const QString systemFieldValue = splitLine[1].replace("'","");


        // Preenche os atributos da classe baseado nas  entradas do arquivo .fis
        if (systemField == "Name")
        {
            m_input->setName(systemFieldValue);
        }
        else if (systemField == "Range")
        {
            int rangeValuesSize = systemFieldValue.size();

            // Remove os colchetes
            QString rangeValues = systemFieldValue.mid(1, rangeValuesSize - 2);
            // Separa os valores
            QStringList rangeValuesSplitted = rangeValues.split(" ");
            std::shared_ptr<std::pair<float, float>> rangePair = std::make_shared<std::pair<float, float>>();
            rangePair->first = rangeValuesSplitted[0].toFloat();
            rangePair->second = rangeValuesSplitted[1].toFloat();
            m_input->setRange(rangePair);
        }
        else if (systemField == "NumMFs")
        {

        }
        else if (systemField == "MF")
        {

        }
    }
/*
            if l_attr[0] == 'Range':
                range_list = (l_attr[1][1:-1].split())
                self.input.range = [float(range_list[0]),
                                       float(range_list[1])]
            if l_attr[0] == 'NumMFs':
                self.input.num_mfs = int(l_attr[1])
            if l_attr[0][:2] == 'MF':
                mf_number = int(l_attr[0][2:])
                mfs_list.append({'num': mf_number, 'entries': l_attr[1]})

        # Verifica se todos os atributos da variável foram preenchidos
        if self.input.name is None:
            raise Exception(f"O nome da variável não foi informado!")
        if self.input.range == list():
            raise Exception(f"A amplitude do conjunto da variável "
                            "não foi informada!")
        if self.input.num_mfs is None:
            raise Exception(f"O número de funções de pertinência da "
                            "variável não foi informado!")

        # Verifica se a quantidade de funções de pertinência está correta
        if len(mfs_list) == self.input.num_mfs:
            for mf in mfs_list:
                # Remover aspas e extrair nome de identificação
                line_list = mf['entries'].replace("'", '').split(':')
                mf_name = line_list[0]

                # Atribui o nome da função
                func_list = line_list[1].split(',')

                if inference_type == ControllerType.mamdani:
                    try:
                        _ = MamdaniFunctions[func_list[0]]
                    except Exception:
                        raise Exception(
                            f"Função de pertinência {func_list[0]}, "
                            "não implementada para Mamdani!")

                elif inference_type == ControllerType.sugeno:
                    try:
                        _ = SugenoInputFunctions[func_list[0]]
                    except Exception:
                        raise Exception(
                            f"Função de pertinência {func_list[0]}, "
                            "não implementada para Sugeno!")

                mf_function = Functions[func_list[0]]

                # Verifica se os valores da lista são do tipo float
                try:
                    values_list = [float(x) for x in func_list[1][1:-1].split()]
                except Exception:
                    raise Exception("Um dos valores não é do tipo float!")

                mf_service = MembershipFunctionService()
                mf_service.create_membership_function(mf_function,
                                                      mf_name,
                                                      values_list)
                self.input.add_mfs(mf['num'], mf_service.membership_function)

        else:
            raise Exception("Quantidade de funções de pertinência para "
                            f"a variável {self.input.name} é diferente "
                            f"do número de funções de pertinência informado "
                            f"no bloco!")
*/


    std::shared_ptr<Input> input;
    return input;
}

std::shared_ptr<Input> InputService::getInput() const
{
    return m_input;
}

void InputService::setInput(const std::shared_ptr<domain::fis::variable::Input> input)
{
    m_input = input;
}


}
}
}
}
