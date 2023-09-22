from pyPS4Controller.controller import Controller


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


controller = MyController(interface="/dev/input/js0", connecting_using_ds4drv=False)
controller.listen()