#include <iostream>

class Triangulo{

    /* Atributos */
    private:
        int base, altura;

    public:

        /* Construtor */
        Triangulo(int b, int a){
            base = b;
            altura = a;
        }

        Triangulo(){
            base = 10;
            altura = 10;
        }

        /* Getters */
        int getBase(){
            return base;
        }

        int getAltura(){
            return altura;
        }

        /* Setters */
        void setBase(int b){
            base = b;
        }

        void setAltura(int a){
            altura = a;
        }

        /* Funcoes auxiliares */
        float Area(){
            return (base*altura)/2;
        }

        void Mostra(){
            std::cout << "\tBase: " << base << "\n";
            std::cout << "\tAltura: " << altura << "\n";
            std::cout << "\tArea: " << this->Area() << "\n";
        }
};

int main(){

    Triangulo t1;
    Triangulo t2 (3, 6);

    std::cout << "Dados do objeto t1:\n";
    t1.Mostra();
    std::cout << "\nDados do objeto t2:\n";
    t2.Mostra();

    t1.setBase(2);
    t1.setAltura(4);
    t2.setBase(1);
    t2.setAltura(2);

    std::cout << "\nDados do objeto t1:\n";
    t1.Mostra();
    std::cout << "\nDados do objeto t2:\n";
    t2.Mostra();


    return 0;
}
