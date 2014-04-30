#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 12/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

from Conta import Conta

class ContaPoupanca(Conta):

    # Construtor #
    def __init__(self, numero):
        super(ContaPoupanca, self).__init__(numero)

    def atualiza(self, taxa):
        pai = super(ContaPoupanca, self)
        pai.setSaldo(pai.getSaldo() + 3 * pai.getSaldo() * taxa)
