#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 06/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

class Professor(object):

    # Atributos #
    _nome = None
    _idade = None
    _matricula = None
    _horas = None
    _valor = None

    # Construtor #
    def __init__(self, nome, idade, matricula):
        self._nome = nome
        self._idade = idade
        self._matricula = matricula

    # Getters #
    def getNome(self):
        return self._nome

    def getIdade(self):
        return self._idade

    def getMatricula(self):
        return self._matricula

    def getHoras(self):
        return self._horas

    def getValor(self):
        return self._valor

    # Setters #
    def setNome(self, nome):
        self._nome = nome

    def setIdade(self, idade):
        self._idade = idade

    def setMatricula(self, matricula):
        self._matricula = matricula

    def setHoras(self, horas):
        self._horas = horas

    def setValor(self, valor):
        self._valor = valor

    # Imprime os atributos #
    def imprime(self):
        print('\tNome:\t%s' % (self._nome))
        print('\tIdade:\t%d' % (self._idade))
        print('\tMatricula:\t%d' % (self._matricula))
