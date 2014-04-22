#!/usr/bin/env python
#-*- coding: utf-8 -*-

'''
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 14/04/14
'''
from __future__ import unicode_literals
from __future__ import print_function

from SalariedEmployee import SalariedEmployee
from HourlyEmployee import HourlyEmployee
from CommissionEmployee import CommissionEmployee
from BasePlusCommissionEmployee import BasePlusCommissionEmployee
from datetime import date

if __name__ == '__main__':

    # Instancia os funcionarios #
    assalariado = SalariedEmployee('John', 'Smith', '111-11-1111',
                                   date(1990,12,22), 1, 800.00)
    horista = HourlyEmployee('Karen', 'Price', '222-22-2222',
                             date(1983,12,22), 2, 16.75, 40)
    comissionado = CommissionEmployee('Sue', 'Jones', '333-33-3333',
                                      date(1989,10,12), 3, 10000, 0.06)
    comissionado2 = BasePlusCommissionEmployee('Bob', 'Lewis',
                                               '444-44-4444',date(86,4,6),
                                               4, 5000, 0.04, 300)

    # Calcula o ganho de cada funcionario #
    print('Employees processed individually:\n')

    print(assalariado)
    print('earned: R${0:=2}'.format(assalariado.earnings()))

    print(horista)
    print('earned: R${0:=2}'.format(horista.earnings()))

    print(comissionado)
    print('earned: R${0:=2}'.format(comissionado.earnings()))

    print(comissionado2)
    print('earned: R${0:=2}'.format(comissionado2.earnings()))

    # Cria um vetor de funcionarios #
    funcionarios = [assalariado, horista, comissionado, comissionado2]

    # Processa arbitrariamente o vetor de funcionarios #
    for i in funcionarios:
        print(i)

        # Verifica se i eh BasePlusCommissionEmployee #
        if isinstance(i, BasePlusCommissionEmployee):
            i.setBaseSalary(i.getBaseSalary()*1.10)
            print('new base salary with 10%\
                   increase is: R${0:=2}'.format(i.getBaseSalary()))

        print('earned R${0:=2}'.format(i.earnings()))

    # Imprime o tipo do objeto no vetor funcionarios #
    for x,a in enumerate(funcionarios):
        print('Employee {0} is a {1}'.format(x, type(a).__name__))
