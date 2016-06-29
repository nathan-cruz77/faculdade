import sys
import random


def print_vet(vet):
    print('{}'.format(len(vet)), end=' ')
    for num in vet:
        print('{}'.format(num), end=' ')
    print()


def generate_test():
    x = set(range(1, 100))
    print_vet(x)

    aux2 = []
    aux = set()
    while aux != x:
        delta = set(random.sample(x, random.randint(1, 60)))
        aux2.append(set(delta))
        aux |= set(delta)

    print(len(aux2))
    for ele in aux2:
        print_vet(ele)


if __name__ == '__main__':
    generate_test()
