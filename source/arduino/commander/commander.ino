typedef int(*pFunc)(String);
typedef struct{
  String cmdName; 
  pFunc cmdFunc;
} stRecvCmd;

// Prototype declaration
int ledLight(String &param); // Test function

// Available command list definition
const int RECV_CMD_NUM = 1;
const stRecvCmd recvCmdList[RECV_CMD_NUM]
{
    {"LEDLIGHT", ledLight}
};

// Each command function definition
int ledLight(String &param)
{
  Serial.println("ledLight() param: " + param);
  return 0;
}