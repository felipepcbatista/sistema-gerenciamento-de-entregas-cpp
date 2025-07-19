#ifndef VALIDADOR_H
#define VALIDADOR_H

class Validador{
public:
    static void limparEntrada();
    static int lerInteiro(const char*, int, int);
    static double lerDouble(const char*);
    static bool stringVazia(const char*);
    static bool nomeLocalRepetido(const char*, Local, int);
    static bool placaRepetida(const char*, Veiculo, int);
    static bool placaInvalida(const char*);
};

#endif
