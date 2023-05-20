import socket

HOST = "127.0.0.1"
PORT = 1234

# socket.SOCK_DGRAM not socket.DGRAM
Csock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

print("Sender is ready ")
# sock.connect((HOST.PORT))   no need for this line
message = "Client say hello"
Csock.sendto(message.encode(), (HOST, PORT))  # add (HOS,PORT) along with this

response, addr = Csock.recvfrom(1024)

print(f"Message recieved from address : {addr}")

print(f"Message sent by sender is : {response.decode()}")

printf("Client side closed")
