import socket, time
from threading import Thread, Event
from pyPS4Controller.controller import Controller

SERVER_IP_ADDR = '192.168.5.10'
SERVER_PORT_NUM = 55555

class MyController(Controller):

    def __init__(self, **kwargs):
        Controller.__init__(self, **kwargs)

    def on_up_arrow_press(self):
        # send command: SET V_MOVE_FORWARD 
        print("on_up_arrow_press() raised.")

    def on_down_arrow_press(self):
        # send command: SET V_MOVE_BACKWARD
        print("on_down_arrow_press() raised")

    def on_left_arrow_press(self):
        # send command: SET V_ROT_LEFT
        print("on_left_arrow_press() raised.")

    def on_right_arrow_press(self):
        # send command: SET V_ROT_RIGHT
        print("on_right_arrow_press() raised.")

# def presend(socket):
#     if socket.connected

def recvcmd_th(socket):
    while True:
        time.sleep(0.2)
        if not th_event.wait(0.1):
            continue
        try:
            recv_msg  = socket.recv(1024)
            if len(recv_msg) > 0:
                print(recv_msg)
        except Exception as error:    
            print(type(error))
            print(error)

def main():
    client_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        client_sock.connect((SERVER_IP_ADDR, SERVER_PORT_NUM))
        print('Connected to server.')
    except:
        print('First Connection failed.')
    
    th_event.clear()
    th1 = Thread(recvcmd_th, client_sock)

    controller = MyController(interface="/dev/input/js0", connecting_using_ds4drv=False)
    controller.listen()

if __name__ == '__main__':
    th_event = Event()
    main()