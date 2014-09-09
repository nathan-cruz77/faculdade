#!/usr/bin/env python3
#-*- coding: utf-8 -*-

import socket

__author__ = 'Nathan Cruz <nathan.cruz@unifesp.br>'
__created__ = '09/09/14'


if __name__ == '__main__':
    cliente = socket.socket()
    cliente.connect(('', 8080))

    para_servidor = input()
    cliente.send(para_servidor.encode())

    do_servidor = cliente.recv(4096).decode()
    print('DO SERVIDOR: {}'.format(do_servidor))
