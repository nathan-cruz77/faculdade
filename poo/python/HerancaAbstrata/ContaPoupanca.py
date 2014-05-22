#!/usr/bin/env python
#-*- coding: utf-8 -*-

'''
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 13/04/14
'''

from __future__ import unicode_literals
from __future__ import print_function

from Conta import Conta


class ContaPoupanca(Conta):

    # Inicializador
    def __init__(self, numero):
        self.__numero = numero
        self.__saldo = super(ContaPoupanca, self).getSaldo()


    # Atualiza o saldo de acordo com a taxa
    def atualiza(self, taxa):
        self.__saldo += 3*(self.__saldo * taxa)
