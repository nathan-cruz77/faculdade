#!/usr/bin/env python
#-*- coding: utf-8 -*-

"""
@author Nathan Cruz <nathan.cruz@unifesp.br>
@created 14/04/14
"""
from __future__ import unicode_literals
from __future__ import print_function

class Employee(object):

    # Atributos #
    __firstName = None
    __lastName = None
    __socialSecurityNumber = None
    __privateBirthDate = None
    __departmentCode = None

    # Construtor #
    def __init__(self, firstName, lastName, socialSecurityNumber,
                 privateBirthDate, departmentCode):
        self.setFirstName(firstName)
        self.setLastName(lastName)
        self.setSocialSecurityNumber(socialSecurityNumber)
        self.setPrivateBirthDate(privateBirthDate)
        self.setDepartmentCode(departmentCode)

    # Getters #
    def getFirstName(self):
        return self.__firstName
    def getLastname(self):
        return self.__lastName
    def getSocialSecurityNumber(self):
        return self.__socialSecurityNumber
    def getPrivateBirthDate(self):
        return self.__privateBirthDate
    def getDepartmentCode(self):
        return self.__departMentCode

    # Setters #
    def setFirstName(self, firstName):
        self.__firstName = firstName
    def setLastName(self, lastName):
        self.__lastName = lastName
    def setSocialSecurityNumber(self, ssn):
        self.__socialSecurityNumber = ssn
    def setPrivateBirthDate(self, privateBirthDate):
        self.__privateBirthDate = privateBirthDate
    def setDepartmentCode(self, departmentCode):
        self.__departmentCode = departmentCode

    # Representação textual do objeto #
    def __str__(self):
        return '''{0} {1}
                  Social Security Number: {2}
                  Department Code: {3}'''.format(
                          self.getFirstName(),
                          self.getLastName(),
                          self.getSocialSecurityNumber(),
                          self.getDepartmentCode())

    # Faz repr() se comportar da mesma forma que str() #
    def __repr__(self):
        return self.__str__()
