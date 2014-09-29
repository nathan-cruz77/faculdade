#include <iostream>
#include <ctime>
#include <cstdlib>

class Quadrado{
    private:
        float lado;

    public:

        /* Construtores */
        Quadrado(){
            this->lado = 10;
        }

        Quadrado(float lado){
            this->lado = lado;
        }

        /* Setter */
        void setLado(float lado){
            this->lado = lado;
        }

        /* Getter */
        float getLado(){
            return this->lado;
        }

        /* Calcula a area */
        float area(){
            return (this->lado) * (this->lado);
        }

        /* Aumenta o tamanho do quadrado */
        void aumenta(float val){
            this->setLado(this->getLado() + val);
        }
};

int main(){
    Quadrado* obj = (Quadrado*) malloc(sizeof(Quadrado)*10);
    float soma=0;

    for(int i; i<10; i++){
        obj[i] = new Quadrado (i);
        std::cout << obj[i].getLado();
        soma += obj[i].area();
    }

    std::cout << soma << "\n";

    return 0;
}
