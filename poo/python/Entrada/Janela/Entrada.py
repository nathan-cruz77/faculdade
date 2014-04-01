#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 29/03/14
"""
from __future__ import unicode_literals
from __future__ import print_function

from PySide import QtGui
from Retangulo import Retangulo
from Triangulo import Triangulo
import sys


app = QtGui.QApplication([])
opcao, ok = QtGui.QInputDialog.getText(None, 'Janela1',
                                   'O que deseja criar? [R/T] ')
opcao = str(opcao)
if opcao.upper() == 'R':
    base, ok = QtGui.QInputDialog.getText(None,
                                          'Base',
                                          'Entre com a base: ')
    altura, ok = QtGui.QInputDialog.getText(None,
                                          'Altura',
                                          'Entre com a altura: ')
    altura = float(altura)
    base = float(base)
    try:
        ret = Retangulo(base, altura)
        msg = QtGui.QMessageBox()
        msg.setText('Area: %.2f\nPerimetro: %.2f'
                    % (ret.Area(), ret.Perimetro()))
        msg.exec_()
    except ValueError:
        msg = QtGui.QMessageBox()
        msg.setText('Os valores inseridos não compõe um retângulo')
        msg.exec_()

elif opcao.upper() == 'T':
    lado1, ok = QtGui.QInputDialog.getText(None,
                                          'Lado1',
                                          'Entre com o primeiro lado: ')
    lado2, ok = QtGui.QInputDialog.getText(None,
                                          'Lado2',
                                          'Entre com o segundo lado: ')
    lado3, ok = QtGui.QInputDialog.getText(None,
                                          'Lado3',
                                          'Entre com o terceiro lado: ')
    lado1 = float(lado1)
    lado2 = float(lado2)
    lado3 = float(lado3)

    try:
        tri = Triangulo(lado1, lado2, lado3)
        msg = QtGui.QMessageBox()
        msg.setText('Area: %.2f\nPerimetro: %.2f\nTipo: %s'
                    % (tri.Area(), tri.Perimetro(), tri.Tipo()))
        msg.exec_()
    except ValueError:
        msg = QtGui.QMessageBox()
        msg.setText('Os valores inseridos não compõe um triângulo')
        msg.exec_()
else:
    msg = QtGui.QMessageBox()
    msg.setText('Valor invalido! Favor entrar com R ou T')
    msg.exec_()

sys.exit()
