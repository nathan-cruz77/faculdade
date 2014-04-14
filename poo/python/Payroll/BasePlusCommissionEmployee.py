#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 14/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

from CommissionEmployee import CommissionEmployee

class BasePlusCommissionEmployee(CommissionEmployee):

    # Atributos #
    __baseSalary = None

    # Construtor #
    def __init__(self, first, last, ssn, birthDate, departmentCode,
                 sales, rate, salary):
        pai = super(BasePlusCommissionEmployee, self)
        pai.__init__(first, last, ssn, birthDate, departmentCode,
                     sales, rate)
        self.setBaseSalary(salary)

    # Getters #
    def getBaseSalary(self):
        return self.__baseSalary

    # Setters #
    def setBaseSalary(self, salary):
        if salary > 0:
            self.__baseSalary = salary
        else:
            raise ValueError('Cannot set baseSalary to negative value')

    # Calcula os ganhos mensais do funcionario #
    def earnings(self):
        pai = super(BasePlusCommissionEmployee, self)
        return self.getBaseSalary() + pai.earnings()

    # Representacao textual do objeto #
    def __str__(self):
        pai = super(BasePlusCommissionEmployee, self)
        return '''{0} {1}; {2}: {3}'''.format('base-salaried', str(pai),
                                              'base salary',
                                              self.getBaseSalary())
    def __repr__(self):
        return self.__str__()
