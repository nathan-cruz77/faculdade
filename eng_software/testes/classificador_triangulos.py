#!/usr/bin/env python
#-*- coding: utf-8 -*-

__author__ = 'Nathan Cruz <nathan.cruz@unifesp.br>'
__created__ = '29/08/14'

import math
import unittest


class Ponto(object):

    def __init__(self, x, y):
        self.__x = x
        self.__y = y

    # Getters
    def getX(self):
        return self.__x

    def getY(self):
        return self.__y

    # Setters
    def setX(self, x):
        self.__x = x

    def setY(self, y):
        self.__y = y

    # Calcula a distancia
    def distancia(self, pto):

        if abs(pto.__x) == float('inf') or abs(pto.__y) == float('inf'):
            raise ValueError('Infinity detected')
        if abs(self.__x) == float('inf') or abs(self.__y) == float('inf'):
            raise ValueError('Infinity detected')

        return (math.sqrt(abs(self.getX() - pto.getX())**2 +
                         abs(self.getY() - pto.getY())**2))


class Triangulo(object):

    def __init__(self, p1, p2, p3):

        lado1 = round(p1.distancia(p2))
        lado2 = round(p2.distancia(p3))
        lado3 = round(p3.distancia(p1))

        if lado1 <= 0 or lado2 <= 0 or lado3 <= 0:
            raise ValueError('Pontos nao formam um triangulo')

        elif lado1 > lado2 + lado3:
            raise ValueError('Pontos nao formam um triangulo')

        elif lado2 > lado1 + lado3:
            raise ValueError('Pontos nao formam um triangulo')

        elif lado3 > lado1 + lado2:
            raise ValueError('Pontos nao formam um triangulo')

        else:
            self.__lado1 = lado1
            self.__lado2 = lado2
            self.__lado3 = lado3

    # Getters
    def getLado1(self):
        return self.__lado1

    def getLado2(self):
        return self.__lado2

    def getLado3(self):
        return self.__lado3

    # Verifica se eh equilatero
    def __isEquilatero(self):
        l1, l2, l3 = self.__lado1, self.__lado2, self.__lado3

        if l1 == l2 == l3:
            return True
        else:
            return False

    # Verifica se eh isoceles #
    def __isIsoceles(self):
        l1, l2, l3 = self.__lado1, self.__lado2, self.__lado3

        if l1 == l2 or l1 == l3 or l2 == l3:
                return True
        else:
            return False

    # Verifica tipo do triangulo
    def tipo(self):
        if self.__isEquilatero():
            return 'equilatero'
        if self.__isIsoceles():
            return 'isosceles'
        return 'escaleno'


class TestaPonto(unittest.TestCase):

    def setUp(self):
        self.p1 = Ponto(float('-inf'), float('inf'))
        self.p2 = Ponto(0, 0)
        self.p3 = Ponto(1, 1)
        self.p4 = Ponto(float('inf'), 0)

    def test_distancia1(self):
        self.assertEqual(self.p2.distancia(self.p3), (math.sqrt(2)))

    def test_distancia2(self):
        self.assertEqual(self.p3.distancia(self.p2),  (math.sqrt(2)))

    def test_distancia3(self):
        self.assertRaises(ValueError, self.p1.distancia, self.p2)

    def test_distancia4(self):
        self.assertRaises(ValueError, self.p4.distancia, self.p3)


class TestaTriangulo(unittest.TestCase):

    def setUp(self):
        self.p1 = Ponto(float('-inf'), float('inf'))
        self.p2 = Ponto(float('inf'), 0)
        self.p3 = Ponto(0, 0)
        self.p4 = Ponto(1, 1)

    def test_triangulo1(self):
        self.assertRaises(ValueError, Triangulo, p1=self.p1,
                          p2=self.p2, p3=self.p3)

    def test_triangulo2(self):
        self.assertRaises(ValueError, Triangulo, p1=self.p3,
                          p2=self.p3, p3=self.p3)

    def test_tipo1(self):
        aux = Triangulo(Ponto(-3, 1), Ponto(1, 1), Ponto(-1, -3))
        self.assertEqual(aux.tipo(), 'equilatero')

    def test_tipo2(self):
        aux = Triangulo(self.p3, Ponto(0, 3), Ponto(3, 0))
        self.assertEqual(aux.tipo(), 'isosceles')

    def test_tipo3(self):
        aux = Triangulo(self.p3, Ponto(0, 4), Ponto(3, 0))
        self.assertEqual(aux.tipo(), 'escaleno')

if __name__ == '__main__':
    unittest.main()
