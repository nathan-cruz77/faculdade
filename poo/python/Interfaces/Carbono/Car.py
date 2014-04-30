#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 12/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

class Car():

    # Atributos #
    __modelo = None
    __combustivel = None
    __cilindrada = None
    __passageiros = None

    # Construtor #
    def __init__(self, modelo='Corsa', combustivel='Alcool',
                 cilindrada=1000, passageiros=4):
        self.__modelo = modelo
        self.__combustivel = combustivel
        self.__cilindrada = cilindrada
        self.__passageiros = passageiros

    def getCarbonFootprint(self):
        return (self.__cilindrada * 0.7 +
                self.__passageiros * 0.1)

    def __str__(self):
        return '''
                Tipo: Car
                Quantidade de passageiros: {0}
                Combustivel: {1}
                Modelo: {2}
                Cilindradas: {3}
                Pegada de carbono: {4}'''.format(self.__passageiros,
                                                 self.__combustivel,
                                                 self.__modelo,
                                                 self.__cilindrada,
                                                 self.getCarbonFootprint())

    def __repr__(self):
        return self.__str__()
