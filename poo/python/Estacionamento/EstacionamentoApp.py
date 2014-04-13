#!/usr/bin/env python
#-*- coding: utf-8 -*-

'''
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 13/04/14
'''
from __future__ import unicode_literals
from __future__ import print_function

from Mensalista import Mensalista
from Horista import Horista

if __name__ == '__main__':

    # Dados para instanciar os objetos #
    modelos = ['Fusca', 'Brasilia', 'Passati', 'Uno', 
               'Kombi', 'Corsa', 'Celta']
    cores = ['Azul', 'Amarelo', 'Preto', 'Prateado',
             'Rosa', 'Vermelho', 'Branco']
    placas = ['AAA-1234', 'BBB-1234', 'CCC-1234', 'DDD-1234',
              'EEE-1234', 'FFF-1234', 'GGG-1234']

    vagas = []

    # Popula o vetor de veiculos #
    for i in range(7):
        print('Dados do veiculo: ')
        if i%2==0:
            vagas.append(Horista(placas[i], cores[i], modelos[i], 10., i))
        else:
            vagas.append(Mensalista(placas[i], cores[i], modelos[i], 60.))
        print('\tModelo: %s' % vagas[i].getModelo())
        print('\tCor: %s' % vagas[i].getCor())
        print('\tPlaca: %s' % vagas[i].getPlaca())
        print('\tTotal a pagar: %.1f' % vagas[i].PrecoPagar())

    # Aumenta 10% na mensalidade dos mensalistas #
    for i in range(7):
        if type(vagas[i]) == Mensalista:
            vagas[i].AumentaPreco()

    print('\n### PRECOS INCREMENTADOS ###\n')

    for i in range(7):
        print('Dados do veiculo: ')
        print('\tModelo: %s' % vagas[i].getModelo())
        print('\tCor: %s' % vagas[i].getCor())
        print('\tPlaca: %s' % vagas[i].getPlaca())
        print('\tTotal a pagar: %.1f' % vagas[i].PrecoPagar())
