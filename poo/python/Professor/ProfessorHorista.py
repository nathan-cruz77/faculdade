#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 06/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

from Professor import Professor

class ProfessorHorista(Professor):

    # Construtor #
    def __init__(self, nome, idade, matricula, valor, horas):
        super(ProfessorHorista, self).__init__(nome, idade, matricula)
        self._valor = valor
        self._horas = horas

    # Getter para salario #
    def getSalario(self):
        return self._horas * self._valor

    # Redefinida # 
    # Imprime os atributos #
    def imprime(self):
       super.imprime()
       print('\tHoras Trabalhadas:\t%d' % (self._horas))
       print('\tValor da Hora:\t%.2f' % (self._valor))
       print('\tSalário:\t%.2f' % (self.getSalario()))
