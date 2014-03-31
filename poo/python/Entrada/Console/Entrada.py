#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 29/03/14
"""
from __future__ import unicode_literals
from __future__ import print_function

from Retangulo import Retangulo
from Triangulo import Triangulo

opcao = raw_input('O que deseja criar? [R/T] ')
if opcao.upper() == 'R':
    base = float(raw_input('Entre com a base: '))
    altura = float(raw_input('Entre com a altura: '))
    
    try:
        ret = Retangulo(base, altura)
        print('Area: %.2f' % (ret.Area()))
        print('Perimetro: %.2f' % (ret.Perimetro()))
    except ValueError:
        print('Os valores inseridos não compõe um retângulo')

elif opcao.upper() == 'T':
    lado1 = float(raw_input('Entre com o primeiro lado: '))
    lado2 = float(raw_input('Entre com o segundo lado: '))
    lado3 = float(raw_input('Entre com o terceiro lado: '))

    try:
        tri = Triangulo(lado1, lado2, lado3)
        print('Area: %.2f' % (tri.Area()))
        print('Perimetro: %.2f' % (tri.Perimetro()))
        tri.Tipo()
    except ValueError:
        print('Os valores inseridos não compõe um triângulo')
else:
    print('Valor invalido! Favor entrar com R ou Q')
