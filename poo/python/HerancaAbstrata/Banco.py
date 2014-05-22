#!/usr/bin/env python
#-*- coding: utf-8 -*-

'''
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 13/04/14
'''

from __future__ import unicode_literals
from __future__ import print_function

from ContaCorrente import ContaCorrente
from ContaPoupanca import ContaPoupanca


class Banco(object):

    # Inicializador
    def __init__(self):
        self.__dinheiro = 0.0
        self.__contas = []


    # Registra novas contas
    def Registra(self, conta):
        self.__dinheiro += conta.getSaldo()


    # Imprime o total do banco
    def Imprime(self):
        print('{0} {1}'.format('Saldo do banco:', self.__dinheiro))


if __name__ == '__main__':

    banco = Banco()
    contas = []

    for i in range(10):
        if i % 2:
            contas.append(ContaCorrente(i))
        else:
            contas.append(ContaPoupanca(i))

    banco.contas = contas

    for i in range(10):
        banco.contas[i].credita(12)
        banco.contas[i].debita(3)
        banco.Registra(banco.contas[i])

    banco.Imprime()
