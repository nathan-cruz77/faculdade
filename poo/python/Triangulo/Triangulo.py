#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 27/03/14
"""
from __future__ import unicode_literals
from __future__ import print_function

class Triangulo:
    # Atributos #
    __base = None
    __altura = None

    # Construtor #
    def __init__(self, base=10, altura=10):
        self.__base = float(base)
        self.__altura = float(altura)

    # Getters #
    def getBase(self):
        return self.__base
    def getAltura(self):
        return self.__altura

    # Setters #
    def setBase(self, base):
        self.__base = base
    def setAltura(self, altura):
        self.__altura = altura

    # Calcula a area #
    def Area(self):
        return (self.getBase()*self.getAltura())/2.0

    # Imprime dados sobre o objeto #
    def Mostra(self):
        print('\tBase: %.2f' % (self.getBase()))
        print('\tAltura: %.2f' % (self.getAltura()))
        print('\tArea: %.2f' % (self.Area()))


if __name__ == '__main__':

    t1 = Triangulo()
    t2 = Triangulo(3, 6)

    print('Dados do objeto t1:')
    t1.Mostra()
    print('\nDados do objeto t2:')
    t2.Mostra()

    t1.setBase(2)
    t1.setAltura(4)
    t2.setBase(1)
    t2.setAltura(2)

    print('\nDados do objeto t1:')
    t1.Mostra()
    print('\nDados do objeto t2:')
    t2.Mostra()
