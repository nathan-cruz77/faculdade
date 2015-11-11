def posso_inserir_na_lista(lista, elemento):
    res = False

    for i in lista:
        if  linha in elemento or elemento in linha:
            res = True
        else:
            res = False
            break
    return res

if __name__ == '__main__':
    n = int(input())
    lista = []

    while n != 0:
        lista = []

        for i in range(n):
            linha = input()
            inserir = True
            inserido = False

            for sub_lista in lista:
                if posso_inserir_na_lista(sub_lista, linha):
                    inserido = True
                    sub_lista.append(linha)

            if not inserido:
                lista.append([linha])

        print(lista)
        print(len(max(lista)))
        n = int(input())
