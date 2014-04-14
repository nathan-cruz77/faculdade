#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 14/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

from datetime import date
from Employee import Employee

class SalariedEmployee(Employee):

    # Atributos #
    __weeklySalary = None

    # Construtor #
    def __init__(self, first, last, ssn, birthDate, departmentCode, salary):
        super(SalariedEmployee, self).__init__(first, last, ssn,
                                               birthDate, departmentCode)
        self.setWeeklySalary(salary)

    # Getters #
    def getWeeklySalary(self):
        return self.__weeklySalary

    # Setters #
    def setWeekSalary(self, weekSalary):
        self.__weekSalary = weekSalary

    # Calcula os ganhos do funcionario #
    def earnings(self):
        hj = date.today()
        pai = super(SalariedEmployee, self)
        if hj.month == pai.getPrivateBirthDate().month:
            return self.getWeeklySalary() + 150
        return self.getWeeklySalary()

    # Representação textual dos objetos #
    def __str__(self):
        pai = super(SalariedEmployee, self)
        return '''salaried employee: {0}
                  weekly salary: {1}'''.format(str(pai), 
                                               self.getWeeklySalary())

    def __repr__(self):
        return self.__str__()
