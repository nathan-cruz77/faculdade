#!/usr/bin/python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 27/03/14
"""

class Carro:

    # Atributos #
    __acelerou = None
    __freou = None
    
    # Construtor #
    def __init__(self, acelerou=0, freou=0):
        self.__acelerou = acelerou
        self.__freou = freou

    # Getters #
    def getAcelerou(self):
        return self.__acelerou
    def getFreou(self):
        return self.__freou

    # Setters #
    def setAcelerou(self, acelerou):
        self.__acelerou = acelerou
    def setFreou(self, freou):
        self.__freou = freou

    # Acelerar o carro #
    def acelerar(self, a):
       self.__acelerou += 1
       print('\tAcelerando o carro para a velocidade %s' % (a))
    
    # Frear o carro #
    def frear(self):
        self.__freou += 1
        print('\tFreando o carro')

    # Quantidade de freadas #
    def vezesFreou(self):
        print('\tFreou %d vezes' % (self.__freou))

    # Quantidade de aceleradas #
    def vezesAcelerou(self):
        print('\tAcelerou %d vezes' % (self.__acelerou))


if __name__ == '__main__':

    c1 = Carro()
    c2 = Carro()

    print('Objeto c1: ')
    c1.acelerar(10)
    c1.frear()
    c1.vezesFreou()
    c1.vezesAcelerou()
    
    print('Objeto c2: ')
    c2.acelerar(15)
    c2.frear()
    c2.vezesFreou()
    c2.vezesAcelerou()
