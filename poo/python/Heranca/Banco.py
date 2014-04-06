#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 06/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

from ContaCorrente import ContaCorrente
from ContaPoupanca import ContaPoupanca

class Banco:

    # Atributos #
    __dinheiro = None
    __contas = None
    
    # Construtor #
    def __init__(self):
        self.__dinheiro = 0
        self.__contas = []

    # Adiciona conta a lista de contas #
    def addConta(self, conta):
        self.__contas.append(conta)

    # Credita #
    def creditaConta(self, pos, valor):
        self.__contas[pos].credita(valor)

    # Debita #
    def debitaConta(self, pos, valor):
        self.__contas[pos].debita(valor)

    # Registra nova conta #
    def registra(self, conta):
        self.__dinheiro += conta.getSaldo()

    # Pega a conta na lista #
    def getConta(self, pos):
        return self.__contas[pos]

    # Imprime o total do banco #
    def imprime(self):
        print('Saldo do banco: %.2f' % (self.__dinheiro))

if __name__ == '__main__':
    
    banco = Banco()
    
    # Popula a lista de contas #
    for i in range(10):
        if i % 2 == 0:
            banco.addConta(ContaCorrente(i))
        else:
            banco.addConta(ContaPoupanca(i))

    for i in range(10):
        banco.creditaConta(i, 12)
        banco.debitaConta(i, 3)
        banco.registra(banco.getConta(i))

    banco.imprime()
