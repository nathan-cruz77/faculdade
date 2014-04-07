#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 06/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

from ProfessorIntegral import ProfessorIntegral
from ProfessorHorista import ProfessorHorista

if __name__ == '__main__':

    nomes = [
             "Alberto", "José", "Nathan", "Mariane", "Fulano",
             "Fulana", "Thais", "Regina", "Luiz", "Silvia"
             ]
    professores = []

    # Popula o vetor de professores #
    for i in range(10):
        if i % 2 == 0:
            professores.append(ProfessorHorista(nomes[i], i+20,
                                                (i+1)*(i+10),
                                                (i+1)*(20.36+i),
                                                (i+1)*(5)))
        else:
            professores.append(ProfessorIntegral(nomes[i], i+20,
                                                 i*(10+i), (i+1)*1000))

    # Exibe o estado de todos os objetos #
    for i in range(10):
        aux = i+1
        print('Objeto: %d' % (aux))
        professores[i].imprime()

    # Aumenta algumas horas para todos os professores #
    for i in range(10):
        aux = professores[i]
        if i % 2 == 0:
            aux.setHoras(aux.getHoras()+i)

    print('\n### HORAS TRABALHADAS ADICIONADAS ###\n')

    # Exibe o estado de todos os objetos #
    for i in range(10):
        aux = i+1
        print('Objeto: %d' % (aux))
        professores[i].imprime()
