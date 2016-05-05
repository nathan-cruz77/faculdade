#include <algorithm>

#include <time.h>
#include <sys/socket.h>
#include <math.h>


using namespace std;


unsigned long long int ipow(unsigned long long int base,
                            unsigned long long int expo){

    unsigned long long int result = 1ULL;

    while(expo){
        if(expo & 1){
            result *= base;
        }
        expo >>= 1;
        base *= base;
    }

    return result;
}


void generate_primes(unsigned long long int& q, unsigned long long int& a){

    /* Gambiarra */
    q = 353;
    a = 3;

}


void generate_keys(unsigned long long int q,
                   unsigned long long int a,
                   unsigned long long int& public_key,
                   unsigned long long int& private_key){

    srand(time(NULL));
    private_key = (rand() % (q - 1) ) + 1;
    public_key = ipow(a, private_key) % q;

}


void generate_shared_key(unsigned long long int& shared_key,
                         unsigned long long int private_key,
                         unsigned long long int public_key,
                         unsigned long long int q){

    shared_key = ipow(public_key, private_key) % q;

}


string server_exchange_key(int sock){

    unsigned long long int q;
    unsigned long long int a;

    unsigned long long int public_key;
    unsigned long long int private_key;

    unsigned long long int public_key_client;

    unsigned long long int shared_key;

    generate_primes(q, a);

    send(sock, (void*) &q, sizeof(q), 0);
    send(sock, (void*) &a, sizeof(a), 0);

    generate_keys(q, a, public_key, private_key);

    recv(sock, (void*) &public_key_client, sizeof(public_key_client), 0);
    send(sock, (void*) &public_key, sizeof(public_key), 0);

    generate_shared_key(shared_key, private_key, public_key_client, q);

    return to_string(shared_key);

}


string client_exchange_key(int sock){

    unsigned long long int q;
    unsigned long long int a;

    unsigned long long int aux_q;
    unsigned long long int aux_a;

    unsigned long long int public_key;
    unsigned long long int private_key;

    unsigned long long int public_key_server;

    unsigned long long int shared_key;

    recv(sock, (void*) &aux_q, sizeof(aux_q), 0);
    recv(sock, (void*) &aux_a, sizeof(aux_a), 0);

    q = max(aux_q, aux_a);
    a = min(aux_q, aux_a);

    generate_keys(q, a, public_key, private_key);

    send(sock, (void*) &public_key, sizeof(public_key), 0);
    recv(sock, (void*) &public_key_server, sizeof(public_key_server), 0);

    generate_shared_key(shared_key, private_key, public_key_server, q);

    return to_string(shared_key);

}
