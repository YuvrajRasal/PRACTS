import socket

HOST = "127.0.0.1"
PORT = 12345

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
    server_socket.bind((HOST, PORT))
    server_socket.listen()
    print("Waiting for client....")
    conn, addr = server_socket.accept()

    while conn:
        print(f"The address od sender is : {addr}")
        data = conn.recv(1024)

        while True:
            if not data:
                break
            print(f"The message sent by client is : {data.decode()}")
            response = "Message recieved"
            conn.sendall(response.decode())

            print("Sever side closed")
