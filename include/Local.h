#ifndef LOCAL_H
#define LOCAL_H

class Local {
private:
    char endereco[300];
    double coordenadaX;
    double coordenadaY;

public:
    Local();
    Local(const char* endereco, double coordenadaX, double coordenadaY);

    void setEndereco(const char* endereco);
    void setCoordenadaX(double coordenadaX);
    void setCoordenadaY(double coordenadaY);

    const char* getEndereco() const;
    double getCoordenadaX() const;
    double getCoordenadaY() const;
};

#endif
