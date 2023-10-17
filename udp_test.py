import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

host = '127.0.0.1'
port = 8889
data = b'wdnmd'
sock.sendto(data, (host, port))
sock.close()
