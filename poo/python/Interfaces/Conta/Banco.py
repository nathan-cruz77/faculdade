#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 12/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

from ContaCorrente import ContaCorrente
from ContaPoupanca import ContaPoupanca
from CDB import CDB

class Banco():

    # Atributos #
    __dinheiro = 0
    contas = []
    __tributos = 0

    # Registra uma nova conta #
    def Registra(self, conta):
        if not isinstance(conta, ContaPoupanca):
            self.__tributos += conta.calculaTributos()
        self.__dinheiro += conta.getSaldo()

    # Imprime o total do banco #
    def Imprime(self):
        print('Saldo do banco: {:.2f}\nTributos do banco: {:.2f}'
              .format(self.__dinheiro, self.__tributos))


if __name__ == '__main__':

    banco = Banco()

    for i in range(5):
        banco.contas.append(ContaCorrente(i))
        banco.contas.append(ContaPoupanca(i))
        banco.contas.append(CDB(i))

    for i in range(15):
        banco.contas[i].credita(12)
        banco.contas[i].debita(3)
        banco.Registra(banco.contas[i])

    banco.Imprime()
