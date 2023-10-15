from pyPS4Controller.controller import Controller

class MyController(Controller):
    def __init__(self, com, **kwargs):
        Controller.__init__(self, **kwargs)
        self.button_status = [False] * 12
        # 0:up, 1:down, 2:left, 3:right, 
        # 4:triangle, 5:cross, 6:square, 7:circle, 
        # 8:L1, 9:L2, 10:R1, 11:R2
        self.com = com
        self.com.start()
            
    def on_up_arrow_press(self):
        self.button_status[0] = True
        self.com.sendcmd('V_MOVE_FORWARD', []) 

    def on_down_arrow_press(self):
        self.button_status[1] = True
        self.com.sendcmd('V_MOVE_BACKWARD', []) 

    def on_up_down_arrow_release(self):
        self.button_status[0] = False
        self.button_status[1] = False
        self.com.sendcmd('V_STOP', []) 

    def on_left_arrow_press(self):
        self.button_status[2] = True
        self.com.sendcmd('V_ROT_LEFT', []) 

    def on_right_arrow_press(self):
        self.button_status[3] = True
        self.com.sendcmd('V_ROT_ROGHT', []) 

    def on_left_right_arrow_release(self):
        self.button_status[2] = False
        self.button_status[3] = False
        self.com.sendcmd('V_STOP', [])

    def on_triangle_press(self):
        self.button_status[4] = True
        print("on_triangle_press")

    def on_triangle_release(self):
        self.button_status[4] = False
        print("on_triangle_release") 

    def on_x_press(self):
        self.button_status[5] = True
        print("on_x_press")

    def on_x_release(self):
        self.button_status[5] = False
        print("on_x_release")

    def on_square_press(self):
        self.button_status[6] = True
        print("on_square_press")

    def on_square_release(self):
        self.button_status[6] = False
        print("on_square_release")

    def on_circle_press(self):
        self.button_status[7] = True
        self.com.sendcmd('HEATER_ONOFF', ['ON']) 

    def on_circle_release(self):
        self.button_status[7] = False
        self.com.sendcmd('HEATER_ONOFF', ['OFF'])

    def on_L1_press(self):
        self.button_status[8] = True
        print("on_L1_press")

    def on_L1_release(self):
        self.button_status[8] = False
        print("on_L1_release")

    def on_L2_press(self, value):
        self.button_status[9] = True
        print("on_L2_press: {}".format(value))

    def on_L2_release(self):
        self.button_status[9] = False
        print("on_L2_release")

    def on_R1_press(self):
        self.button_status[10] = True
        print("on_R1_press")

    def on_R1_release(self):
        self.button_status[10] = False
        print("on_R1_release")

    def on_R2_press(self, value):
        self.button_status[11] = True
        print("on_R2_press: {}".format(value))

    def on_R2_release(self):
        self.button_status[11] = False
        print("on_R2_release") 
