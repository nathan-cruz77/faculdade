#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 06/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

from Professor import Professor

class ProfessorIntegral(Professor):

    # Atributos #
    __salario = None

    # Construtor #
    def __init__(self, nome, idade, matricula, salario):
        super(ProfessorIntegral, self).__init__(nome, idade, matricula)
        self.__salario = salario

    # Getters #
    def getSalario(self):
        return self.__salario

    # Setters #
    def setSalario(self, salario):
        self.__salario = salario

    # Redefinido #
    # imprime os atributos #
    def imprime(self):
        super.imprime()
        print('\tSalário:\t%.2f' % (self.getSalario()))
