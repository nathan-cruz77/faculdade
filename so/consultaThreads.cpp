#include <iostream>
#include <unistd.h>

int main(){
    std::cout << "Threads suportadas: " << sysconf(_SC_NPROCESSORS_ONLN);
    std::cout << "\n";
    return 0;
}
