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

class HourlyEmployee(Employee):

    # Atributos #
    __wage = None
    __hours = None

    # Construtor #
    def __init__(self, first, last, ssn, birthDate, departmentCode,
                 hourlyWage, hoursWorked):
        super(HourlyEmployee, self).__init__(first, last, ssn, birthDate,
                                             departmentCode)
        self.setWage(hourlyWage)
        self.setHours(hoursWorked)

    # Getters #
    def getWage(self):
        return self.__wage
    def getHours(self):
        return self.__hours

    # Setters #
    def setWage(self, wage):
        if wage < 0:
            raise ValueError('Cannot set wage to negative value')
        self.__wage = wage

    def setHours(self, hours):
        if hours < 0:
            raise ValueError('Cannor set hours to negative value')
        self.__hours = hours

    def earnings(self):
        hj = date.today()
        pai = super(HourlyEmployee, self)
        bonus = 0
        if hj.month == pai.getPrivateBirthDate().month:
            bonus = 150
        if self.getHours() <= 40:
            return self.getWage() * self.getHours + bonus
        else:
            return (40* self.getWage() + 
                    (self.getHours - 40) * self.getWage() * 1.5) + bonus

    def __repr__(self):
        return self.__str__()

    def __str__(self):
        pai = super(HourlyEmployee, self)
        return '''hourly employee: {0}
                  {1}: ${2}; {3}: {4}'''.format(str(pai), 'hourly wage',
                                                self.getWage(), 'hours worked'
                                                , self.getHours())
