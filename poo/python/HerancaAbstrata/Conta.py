#!/usr/bin/env python
#-*- coding: utf-8 -*-

'''
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 13/04/14
'''

from __future__ import unicode_literals
from __future__ import print_function

# Modulo contendo metaclass e outras coisas uteis para classes
# abstratas
import abc


class Conta(object):

    # Transforma a classe numa classe abstrata
    __metaclass__ = abc.ABCMeta


    # Atributos
    __saldo = 0.0
    __numero = None


    # Faz um deposito na conta
    def credita(self, quantia):
        if quantia > 0:
            self.__saldo += quantia
        else:
            raise ValueError('{0} {1}'.format('Nao se pode sacar',
                                              'zero ou menos'))


    # Faz um saque da conta
    def debita(self, quantia):
        if quantia <= self.__saldo:
            if quantia <= 0:
                raise ValueError('{0} {1}'.format('Nao se pode sacar',
                                                  'zero ou menos'))
            self.__saldo -= quantia
        else:
            raise ValueError('{0} {1}'.format('Nao se pode sacar',
                                              'mais do que se tem'))


    # Getters
    def getSaldo(self):
        return self.__saldo


    def getNumero(self):
        return self.__numero


    # Representacao da classe
    def imprime(self):
        print('Conta\n\tIdentificador: {0}\n\tSaldo: R${1:.2f}'.
              format(self.__numero, self.__saldo))
