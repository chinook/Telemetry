import socket
import time

SERVER_IP = "174.142.90.39"
UDP_PORT = 5005


car_sock = socket.socket(socket.AF_INET, # Internet
                      socket.SOCK_DGRAM) # UDP
# car_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
#car_sock.bind((SERVER_IP, UDP_PORT))

#app_sock = socket.socket(socket.AF_INET,
#                         socket.SOCK_STREAM)

#s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
#s.bind((SERVER_IP, TCP_PORT))
#s.listen(1)
#conn, addr = s.accept()
print(f"Sending 0xDEED to {SERVER_IP} port {UDP_PORT}")
count = 0;
while True:
    data = bytes.fromhex('AA55010203040506')
    car_sock.sendto(data, (SERVER_IP, UDP_PORT))
    #car_sock.sendto(0xDEED, (SERVER_IP, UDP_PORT))
    count = count + 1
    #car_sock.send(bytes(0xDEED))
    print(count)
    time.sleep(1)
