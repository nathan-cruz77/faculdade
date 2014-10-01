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
    Quadrado* obj = new Quadrado[10];
    float soma=0;

    srand(time(NULL));

    for(int i=1; i<11; i++){
        ::new(&obj[i]) Quadrado((float) (rand()%10));
        soma += obj[i].area();
    }

    std::cout << "A soma eh: " << soma << "\n";

    delete[] obj;
    return 0;
}
