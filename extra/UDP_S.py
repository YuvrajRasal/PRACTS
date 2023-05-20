import socket

HOST = "127.0.0.1"
PORT = 1234

Ssock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

Ssock.bind((HOST, PORT))  # its Ssock.bind and not connect
print("Waiting for client...")
# Ssock.listen()   avoid

while True:  # dont forget this VIMP

    # leave space from beginning or it will throw error
    response, addr = Ssock.recvfrom(1024)

print(f'Address of sender : {addr}')

print(f'Message sent by sender is : {response.encode()}')

message = "Message from sender recieved"
Ssock.sendto(message.encode(), addr)  # send addr along as well
print('Server side closed')
