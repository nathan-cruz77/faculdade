#!/usr/bin/env python3
#-*- coding: utf-8 -*-

import socket

__author__ = 'Nathan Cruz <nathan.cruz@unifesp.br>'
__created__ = '09/09/14'


if __name__ == '__main__':

    server = socket.socket()
    server.bind(('', 8080))
    server.listen(20)

    try:
        while True:
            cliente, addr = server.accept()
            do_cliente = cliente.recv(4096)
            do_cliente = do_cliente.decode()

            cliente.send(do_cliente.upper().encode())
    except KeyboardInterrupt:
        print('\rInterrompido, abortando')
        server.close()
