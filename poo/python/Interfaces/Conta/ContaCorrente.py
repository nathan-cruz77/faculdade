#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 12/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

from Conta import Conta


class ContaCorrente(Conta):


    def __init__(self, numero):
        pai = super(ContaCorrente, self)
        pai.__init__(numero)

    def atualiza(self, taxa):
        pai = super(ContaCorrente, self)
        pai.setSaldo(pai.getSaldo() + 2 *
                            (pai.getSaldo() * taxa))

    def credita(self, quantia):
        pai = super(ContaCorrente, self)
        if quantia > 0:
            pai.setSaldo(pai.getSaldo() + quantia)
            pai.setSaldo(pai.getSaldo() - 0.1)
        else:
            print('Nao se pode depositar uma quantia negativa')

    def calculaTributos(self):
        pai = super(ContaCorrente, self)
        if pai.getSaldo() > 0:
            return pai.getSaldo() / 100.
        print('Valor do saldo invalido')
        return 0
