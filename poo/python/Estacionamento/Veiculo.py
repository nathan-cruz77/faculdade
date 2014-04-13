#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 12/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

class Veiculo(object):

    # Atributos #
    __placa = None
    __cor = None
    __modelo = None

    # Getters #
    def getPlaca(self):
        return self.__placa
    def getCor(self):
        return self.__cor
    def getModelo(self):
        return self.__modelo

    # Setters #
    def setPlaca(self, placa):
        self.__placa = placa
    def setCor(self, cor):
        self.__cor = cor
    def setModelo(self, modelo):
        self.__modelo = modelo

    # Classe a ser implementada nas filhas #
    def PrecoPagar(self):
        pass
