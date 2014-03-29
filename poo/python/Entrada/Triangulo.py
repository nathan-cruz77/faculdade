#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 29/03/14
"""
from __future__ import unicode_literals
from __future__ import print_function

import math

class Triangulo:

    # Atributos #
    __lado1 = None
    __lado2 = None
    __lado3 = None

    # Construtor #
    def __init__(self, lado1, lado2, lado3):
        if (
            lado1 <= (lado2 + lado3) and
            lado2 <= (lado1 + lado3) and
            lado3 <= (lado1 + lado2)
           ):
            self.__lado1 = lado1
            self.__lado2 = lado2
            self.__lado3 = lado3
        else:
            raise ValueError

    # Verifica se eh equilatero #
    def __isEquilatero(self):
        if self.__lado1 == self.__lado2 == self.__lado3:
            return True
        else:
            return False

    # Verifica se eh isoceles #
    def __isIsoceles(self):
        if (
            self.__lado1 == self.__lado2 or
            self.__lado1 == self.__lado3 or
            self.__lado2 == self.__lado3
           ):
               return True
        return False

    # Verifica tipo do triangulo #
    def Tipo(self):
        if self.__isEquilatero():
            print('Triangulo equilatero')
        elif self.__isIsoceles():
            print('Triangulo isoceles')
        else:
            print('Triangulo escaleno')

    # Calcula o perimetro #
    def Perimetro(self):
        return float(self.__lado1 + self.__lado2 + self.__lado3)

    # Calcula a area #
    def Area(self):
        p = self.Perimetro()/2.0;
        a = self.__lado1
        b = self.__lado2
        c = self.__lado3
        return math.sqrt(p*(p-a)*(p-b)*(p-c))
