#include "operate.h"

typedef int(*pFunc)(String);
typedef struct{
  String cmdName; 
  pFunc cmdFunc;
} stRecvCmd;

// Prototype declaration
int ledLight(String &param); // Test function
int v_move_forward(String &param);
int v_move_backward(String &param);
int v_rot_left(String &param);
int v_rot_right(String &param);
int v_stop(String &param);

// Available command list definition
const int RECV_CMD_NUM = 6;
const stRecvCmd recvCmdList[RECV_CMD_NUM]
{
    {"LEDLIGHT", ledLight},
    {"V_MOVE_FORWARD", v_move_forward},
    {"V_MOVE_BACKWARD", v_move_backward},
    {"V_ROT_LEFT", v_rot_left},
    {"V_ROT_RIGHT", v_rot_right},
    {"V_STOP", v_stop}
};

// Each command function definition
int ledLight(String &param)
{
  Serial.println("ledLight() param: " + param);
  return 0;
}

int v_move_backward(String &param)
{
  Serial.println("v_move_backward() param: " + param);
  contrl_catepillar(CTPL_BKWD);
  return 0;
}

int v_move_forward(String &param)
{
  Serial.println("v_move_forward() param: " + param);
  contrl_catepillar(CTPL_FWRD);
  return 0;
}

int v_rot_left(String &param)
{
  Serial.println("v_rot_left() param: " + param);
  contrl_catepillar(CTPL_LTRN);
  return 0;  
}

int v_rot_right(String &param)
{
  Serial.println("v_rot_right() param: " + param);
  contrl_catepillar(CTPL_RTRN);
  return 0;  
}

int v_stop(String &param)
{
  Serial.println("v_stop() param: " + param);
  return 0;
}