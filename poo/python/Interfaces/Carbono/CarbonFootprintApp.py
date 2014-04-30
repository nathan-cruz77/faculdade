#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 12/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

from Bicycle import Bicycle
from Building import Building
from Car import Car

if __name__ == '__main__':

    objetos = []

    # Objetos Car #
    objetos.append(Car())
    objetos.append(Car('Uno', 'Gasolina', 1200, 5))

    # Objetos Building #
    objetos.append(Building())
    objetos.append(Building(12, True, 36, True))

    # Objetos Bicycle #
    objetos.append(Bicycle())
    objetos.append(Bicycle('Velha', 'Ferrugem, Pneu furado'))

    for i in range(6):
        if i == 2 or i == 4:
            print()
        print(objetos[i])
