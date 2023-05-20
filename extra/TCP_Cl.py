import socket

HOST = "127.0.0.1"
PORT = 12345

with socket.socket(socket.AF_INET, socket.SOCK_STREAM)as client_socket:

    print("Client is ready to send message")
    message = "Client says Hello"
    client_socket.connect((HOST, PORT))
    # its message.encode() not just message
    client_socket.sendall(message.encode())

    response, addr = client_socket.recv(1024)

    print(f"Message from server : {response.decode()}")
    print("client side closed")
