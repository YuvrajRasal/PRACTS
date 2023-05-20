import socket

HOST = "127.0.0.1"
PORT = 12345

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
    message = "Hello client here"
    client_socket.connect((HOST, PORT))  # connect and not bind
    client_socket.sendall(message.encode())

    response = client_socket.recv(1024)

    print(f'The message from server is : {response.decode()}')
    print('client side ended')
