#include <iostream>
#include <string>

class Carro{

    /* Atributos */
    private:
        int acelerou;
        int freou;
        int id;

    /* Construtor */
    public:

        Carro(int a){
            acelerou = 0;
            freou = 0;
            id = a;
        }

        ~Carro(){
            std::cout << "Chamando o destrutor" << "\n";
        }

        /* Getters */
        int getAcelerou(){
            return acelerou;
        }

        int getFreou(){
            return freou;
        }

        /* Setters */
        void setAcelerou(int acelerou){
            acelerou = acelerou;
        }

        void setFreou(int freou){
            freou = freou;
        }

        void acelerar(int a){
            setAcelerou(getAcelerou()+1);
            std::cout << "\tAcelerando o carro para: " << a << "\n";
        }

        void frear(){
            setFreou(getFreou()+1);
            std::cout << "\tFreando o carro" << "\n";
        }

        void vezesFreou(){
            std::cout << "\tFreou " << getFreou() << " vezes" << "\n";
        }

        void vezesAcelerou(){
            std::cout << "\tAcelerou " << getAcelerou() << " vezes" << "\n";
        }

};

int main(){

    Carro c1 (1);
    Carro c2 (2);

    std::cout << "Objeto c1: " << "\n";
    c1.vezesFreou();
    c1.vezesAcelerou();

    std::cout << "Objeto c2: " << "\n";
    c2.acelerar(15);
    c2.frear();
    c2.vezesFreou();
    c2.vezesAcelerou();

    return 0;
}
