#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 12/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

class Bicycle(object):

    # Atributos #
    __modelo = None
    __acessorios = None

    # Construtor #
    def __init__(self, modelo='Esportiva',
                 acessorios="Buzina, adesivos, enfeites de roda"):
        self.__modelo = modelo
        self.__acessorios = acessorios

    def getCarbonFootprint(self):
        return 0

    def __str__(self):
        return '''
                Tipo: Bicycle
                Modelo: {0}
                Acessorios: {1}
                Pegada de Carbono: {2}'''.format(self.__modelo,
                                                 self.__acessorios,
                                                 self.getCarbonFootprint())

    def __repr__(self):
        return self.__str__()
