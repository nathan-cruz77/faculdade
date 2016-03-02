import socket
import sys

BUFSIZE = 64 * 1024


def read_all(sock):
    while True:
        data = sock.recv(BUFSIZE)

        if data != b'':
            yield data
        else:
            raise StopIteration()


if __name__ == '__main__':
    if len(sys.argv) != 4:
        print('[usage]: {} <ip> <port> <file>\n'.format(sys.argv[0]))
        print('IP:\tIP of the server serving the file')
        print('PORT:\tPort of the server')
        print('FILE:\tName of the file to be saved')
        sys.exit();

    client = socket.socket()
    client.connect((sys.argv[1], int(sys.argv[2])))
    print('Connected to server')

    with open('{}'.format(sys.argv[3]), 'wb+') as f:
        for chunk in read_all(client):
            f.write(chunk)
