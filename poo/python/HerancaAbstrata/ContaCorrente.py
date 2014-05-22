#!/usr/bin/env python
#-*- coding: utf-8 -*-

'''
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 13/04/14
'''

from __future__ import unicode_literals
from __future__ import print_function

from Conta import Conta


class ContaCorrente(Conta):


    # Inicializador
    def __init__(self, numero):
        self.__numero = numero
        self.__saldo = super(ContaCorrente, self).getSaldo()


    # Atualiza o saldo na conta
    def atualiza(self, taxa):
        self.__saldo += 2*(self.__saldo * taxa)


    # Metodo sobreescrito da classe super-classe
    def credita(self, quantia):
        try:
            super(ContaCorrente, self).credita(quantia)
            self.__saldo -= 0.1

        except ValueError as err:
            print('{0} {1}'.format('Erro: ', err.message))
