#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 12/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

from Veiculo import Veiculo

class Horista(Veiculo):

    # Atributos #
    __valorHora = None
    __horasEstacionado = None

    # Construtor #
    def __init__(self, placa, cor, modelo, valorHora, horasEstacionado):
        super(Horista, self).setPlaca(placa)
        super(Horista, self).setCor(cor)
        super(Horista, self).setModelo(modelo)
        self.setValorHora(valorHora)
        self.setHorasEstacionado(horasEstacionado)

    # Getters #
    def getValorHora(self):
        return self.__valorHora
    def getHorasEstacionado(self):
        return self.__horasEstacionado

    # Setters #
    def setValorHora(self, valorHora):
        self.__valorHora = valorHora
    def setHorasEstacionado(self, horasEstacionado):
        self.__horasEstacionado = horasEstacionado

    # Redefinida #
    def PrecoPagar(self):
        return (self.getValorHora()*self.getHorasEstacionado())
