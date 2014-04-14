#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 14/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

from Employee import Employee
from datetime import date

class CommissionEmployee(Employee):

    # Atributos #
    __grossSales = None
    __commissionRate = None

    # Construtor #
    def __init__(self, first, last, ssn, birthDate, departmentCode,
                 sales, rate):
        pai = super(CommissionEmployee, self)
        pai.__init__(first, last, ssn, birthDate, departmentCode)
        self.setGrossSales(sales)
        self.setCommissionRate(rate)

    # Getters #
    def getGrossSales(self):
        return self.__grossSales
    def getCommissionRate(self):
        return self.__commissionRate
    
    # Setters #
    def setGrossSales(self, grossSales):
        if grossSales > 0:
            self.__grossSales = grossSales
        else:
            raise ValueError('Cannot set grossSales to negative value')
    def setCommissionRate(self, commissionRate):
        if 0 < commissionRate < 1:
            self.__commissionRate = commissionRate
        else:
            raise ValueError('CommissionRate must be in range 0.0-1.0')

    # Calcula os ganhos do funcionario #
    def earnings(self):
        hj = date.today()
        pai = super(CommissionEmployee, self)
        if pai.getPrivateBirthDate().month == hj.month:
            return self.getCommissionRate()*self.getGrossSales() + 150
        return self.getCommissionRate() * self.getGrossSales()

    # Representacao textual do objeto #
    def __str__(self):
        pai = super(CommissionEmployee, self)
        return '''{0}: {1}
                  {2}: {3}; {4}: {5}'''.format('commission employee',
                                              pai.__str__(), 'gross sales',
                                              self.getGrossSales(),
                                              'commission rate', 
                                              self.getCommissionRate())
