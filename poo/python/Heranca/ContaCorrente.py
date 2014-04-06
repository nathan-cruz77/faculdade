#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 06/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

from Conta import Conta

class ContaCorrente(Conta):

    # Construtor #
    def __init__(self, num=0):
        super(ContaCorrente, self).__init__(num)
    
    # Redefinida #
    def atualiza(self, taxa):
        self._saldo += 2*(self._saldo * taxa)

    # Redefinida #
    def credita(self, quantia):
        if quantia > 0:
            self._saldo += quantia
            self._saldo -= 0.1
        else:
            raise ValueError('Não se pode depositar uma quantia negativa')
