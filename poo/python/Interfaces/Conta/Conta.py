#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 12/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

class Conta(object):

    # Atributos #
    __saldo = 0
    __numero = None


    # Construtor #
    def __init__(self, numero):
        self.__numero = numero


    def credita(self, quantia):
        if quantia > 0:
            self.__saldo += quantia
        else:
            print('Nao se pode depositar uma quantia negativa')


    def debita(self, quantia):
        if quantia > 0:
            self.__saldo -= quantia
        else:
            print('Nao se pode sacar uma quantia negativa')


    def imprime(self):
        print('Conta {0}: saldo = {1}'.format(self.getNumero(),
                                              self.getSaldo()))

    # Getters #
    def getSaldo(self):
        return self.__saldo
    def getNumero(self):
        return self.__numero

    # Setters #
    def setSaldo(self, saldo):
        self.__saldo = saldo
