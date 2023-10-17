import socket


def send_tcp_message(host, port, message):
    # 创建一个套接字对象
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        # 连接到指定的主机和端口
        sock.connect((host, port))
        # 发送消息
        sock.sendall(message.encode())
        # 接收响应
        response = sock.recv(1024).decode()
        print("Received:", response)

    finally:
        # 关闭套接字连接
        sock.close()


# 设置主机和端口
host = 'localhost'
port = 8888

# 设置要发送的消息
message = 'Hello, TCP Server!'

# 调用发送函数
send_tcp_message(host, port, message)
