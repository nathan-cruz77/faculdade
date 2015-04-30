import random

def master_blaster_gerador(file, tamanho=15):
    l = list(range(tamanho))
    random.shuffle(l)

    with open(file, 'w') as arq:
        print(tamanho, file=arq)
        for x in l:
            print(x, end=' ', file=arq)
        print(file=arq)
        print(random.choice(l), file=arq)


if __name__ == '__main__':
    for i in range(5):
        master_blaster_gerador('avl{}.in'.format(i))
    print('Boa sorte!')
