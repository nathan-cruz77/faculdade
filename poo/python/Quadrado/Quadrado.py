#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 27/03/14
"""
from __future__ import unicode_literals
from __future__ import print_function
import random

class Quadrado:

    # Atributos #
    __lado = None

    # Construtor #
    def __init__(self, lado=10):
        self.__lado = lado

    # Setters #
    def setLado(self, lado):
        self.__lado = lado

    # Getters #
    def getLado(self):
        return self.__lado

    # Calcula a area #
    def Area(self):
        return self.__lado * self.__lado

    # Aumenta o quadrado #
    def Aumenta(self, val):
        self.setLado(self.getLado()+val)

if __name__ == '__main__':

    lista = []
    soma = 0
    for i in range(10):
        lista.append(Quadrado(random.random()*10))
        soma += lista[i].Area()

    print('A soma eh: %.2f' % (soma))    
