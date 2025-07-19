#ifndef LOCAL_H_INCLUDED
#define LOCAL_H_INCLUDED

class Local{
private:
    char endereco[300];
    double coordenadaX;
    double coordenadaY;
public:
    Local();
    Local(const char*, double, double);
    void setEndereco (const char* endereco);
    void setCoordenadaX (double);
    void setCoordenadaY (double);
    const char* getEndereco()const;
    double getCoordenadaX()const;
    double getCoordenadaY()const;
};

#endif
