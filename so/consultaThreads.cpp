#include <iostream>
#include <unistd.h>

using namespace std;

int main(){
    cout << "Threads suportadas: " << sysconf(_SC_NPROCESSORS_ONLN) << "\n";
    return 0;
}
