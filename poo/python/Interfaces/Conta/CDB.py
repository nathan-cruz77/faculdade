#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 12/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

from Conta import Conta

class CDB(Conta):

    # Construtor #
    def __init__(self, numero):
        super(CDB, self).__init__(numero)


    def atualiza(self, taxa):
        pai = super(CDB, self)
        pai.setSaldo(pai.getSaldo() + 2.5 * pai.getSaldo() * taxa)


    def calculaTributos(self):
        return 42
