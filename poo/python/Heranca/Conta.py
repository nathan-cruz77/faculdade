#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 06/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

class Conta(object):

    # Atributos #
    _saldo = None
    _numero = None

    # Construtor #
    def __init__(self, numero):
        self._saldo = 0
        self._numero = numero

    # Getters #
    def getSaldo(self):
        return self._saldo
    def getNumero(self):
        return self._numero


    # Credita #
    def credita(self, quantia):
        if quantia > 0:
            self._saldo += quantia
        else:
            raise ValueError('Não se pode depositar uma quantia negativa')

    # Debita #
    def debita(self, quantia):
        if quantia > 0:
            self._saldo -= quantia
        else:
            raise ValueError('Não se pode sacar uma quantia negativa')

    def imprime(self):
        print("Conta: %d\nSaldo: %.2f" % (self._numero, self._saldo))
