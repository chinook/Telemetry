import socket
import time

SERVER_IP = "174.142.90.39"
TCP_PORT = 9202

app_sock = socket.socket(socket.AF_INET,
                         socket.SOCK_STREAM)

app_sock.connect((SERVER_IP , TCP_PORT))
print(f"Connected to server {SERVER_IP} port {TCP_PORT}")
count = 0;
while True:
    #data = app_sock.recv(15)
    data = app_sock.recv(4)
    hex_str = ":".join("{:02x}".format(c) for c in data)
    print(hex_str)
