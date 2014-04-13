#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 12/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

from Veiculo import Veiculo

class Mensalista(Veiculo):

    # Atributos #
    __valorMensal = None

    # Construtor #
    def __init__(self, placa, cor, modelo, valorMensal):
        super(Mensalista, self).setPlaca(placa)
        super(Mensalista, self).setCor(cor)
        super(Mensalista, self).setModelo(modelo)
        self.setValorMensal(valorMensal)

    # Getters #
    def getValorMensal(self):
        return self.__valorMensal
    
    # Setters #
    def setValorMensal(self, valorMensal):
        self.__valorMensal = valorMensal

    # Redefinido da super classe #
    def PrecoPagar(self):
        return self.getValorMensal()

    # Incrementa o total a pagar em 10% #
    def AumentaPreco(self):
        self.setValorMensal(self.getValorMensal() * 1.10)
