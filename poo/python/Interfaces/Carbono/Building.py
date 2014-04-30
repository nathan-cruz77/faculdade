#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 12/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

class Building():

    # Atributos #
    __pessoas = None
    __renovavel = None
    __lampadas = None
    __arCondicionado = None

    # Construtor #
    def __init__(self, pessoas=5, renovavel=False,
                 lampadas=15, arCondicionado=False):
        self.__pessoas = pessoas
        self.__renovavel = renovavel
        self.__lampadas = lampadas
        self.__arCondicionado = arCondicionado

    def getCarbonFootprint(self):
        return (self.__pessoas * 0.6 +
                self.__pessoas * self.__arCondicionado * 0.2 +
                self.__lampadas * 0.1 -
                self.__renovavel * 0.5)

    def __str__(self):
        return '''
                Tipo: Building
                Quantidade de pessoas: {0}
                Energia renovavel: {1}
                Quantidade de lampadas: {2}
                Ar condicionado: {3}
                Pegada de carbono: {4}'''.format(self.__pessoas,
                                                 self.__renovavel,
                                                 self.__lampadas,
                                                 self.__arCondicionado,
                                                 self.getCarbonFootprint())

    def __repr__(self):
        return self.__str__()
