#include <iostream>

class Contador{
    private:
        int counter;

    public:

        /* Construtores */
        Contador(){
            this->counter = 0;
        }

        Contador(int counter){
            this->counter = counter;
        }

        /* Getter */
        int getCounter(){
            return this->counter;
        }

        /* Setter */
        void setCounter(int counter){
            this->counter = counter;
        }

        /* Incrementa o contador */
        void incrementa(){
            this->counter += 1;
        }

        void incrementa(int i){
            this->counter += i;
        }

        /* Decrementa o contador */
        void decrementa(){
            this->counter -= 1;
        }

        void decrementa(int i){
            this->counter -= i;
        }

        void mostra(){
            std::cout << "Contador = " << this->getCounter() << "\n";
        }
};

int main(){
    Contador c1;
    Contador c2 (12);

    c1.mostra();
    c1.incrementa();
    c1.mostra();
    c1.incrementa(10);
    c1.mostra();
    c1.decrementa(10);
    c1.mostra();
    c1.decrementa();
    c1.mostra();

    return 0;
}
