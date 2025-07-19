#ifndef VALIDADOR_H
#define VALIDADOR_H

class Local;
class Veiculo;

class Validador{
public:
    static void limparEntrada();
    static int lerInteiro(const char* mensagem, int min, int max);
    static double lerDouble(const char* mensagem);
    static bool stringVazia(const char* texto);
    static bool nomeLocalRepetido(const char* nome, Local locais[], int totalLocais);
    static bool placaRepetida(const char* placa, Veiculo veiculos[], int totalVeiculos);
    static bool placaInvalida(const char* placa);
};

#endif
