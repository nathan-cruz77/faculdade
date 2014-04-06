#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 06/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

from Conta import Conta

class ContaPoupanca(Conta):

    # Construtor #
    def __init__(self, num):
        super(ContaPoupanca, self).__init__(num)

    # Redefinida #
    def atualiza(self, taxa):
        self._saldo += 3*(self._saldo * taxa)
