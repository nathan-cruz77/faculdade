#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 27/03/14
"""
from __future__ import unicode_literals
from __future__ import print_function

class Retangulo:

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
        return self.getBase() * self.getAltura()
    
    # Calcula o perimetro #
    def Perimetro(self):
        return 2*(self.getBase() + self.getAltura())

    # Relacao entre os atributos #
    def Relacao(self):
        return self.__base/self.__altura

    # Verifica se o retangulo é quadrado #
    def isQuadrado(self):
        if self.__base == self.__altura:
            return True
        return False

    # Imprime os atributos do objeto #
    def Mostra(self):
        print('\tBase: %.2f' % (self.getBase()))
        print('\tAltura: %.2f' % (self.getAltura()))
        print('\tArea: %.2f' % (self.Area()))
        print('\tPerimetro: %.2f' % (self.Perimetro()))
        print('\tRelacao: %.2f' % (self.Relacao()))
        if self.isQuadrado():
            print('\tEste retangulo eh um quadrado!')
        else:
            print('\tEste retangulo nao eh um quadrado!')
