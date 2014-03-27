#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 27/03/14
"""
from __future__ import unicode_literals
from __future__ import print_function

class Contador:
    # Atributos #
    __counter = None

    # Construtor #
    def __init__(self):
        self.__counter = 0

    # Getters #
    def getCounter(self):
        return self.__counter

    # Setters #
    def setCounter(self, counter):
        self.__counter = counter

    # Incrementar o contador #
    def Incrementa(self, incremento=1):
        self.__counter += incremento

    # Decrementa o contador #
    def Decrementa(self, decremento=1):
        self.__counter -= decremento

    # Mostra #
    def Mostra(self):
        print('Contador = %d' % (self.__counter))

if __name__ == '__main__':

    c1 = Contador()
    c1.Mostra()
    c1.Incrementa()
    c1.Mostra()
    c1.Incrementa(10)
    c1.Mostra()
    c1.Decrementa(10)
    c1.Mostra()
    c1.Decrementa()
    c1.Mostra()
    contador = c1.getCounter()
    print('Contador = %d' % (contador))
