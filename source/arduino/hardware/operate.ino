#include "operate.h"

// parser
typedef struct {
    short ln;
    short lr;
    short rn;
    short rr;
} signal;

void get_cmd(opr op, signal* sig);

// setup
void init(void) {
    // pin mode
    pinMode(HEATER,           OUTPUT);
    pinMode(ROBOT_ARM_UP,     OUTPUT);
    pinMode(ROBOT_ARM_DOWN,   OUTPUT);
    pinMode(ROBOT_HAND_OPEN,  OUTPUT);
    pinMode(ROBOT_HAND_CLOSE, OUTPUT);
    pinMode(L_CATEPILLAR,     OUTPUT);
    pinMode(L_CATEPILLAR_REV, OUTPUT);
    pinMode(R_CATEPILLAR,     OUTPUT);
    pinMode(R_CATEPILLAR_REV, OUTPUT);
}

// operate

bool contrl_catepillar(opr op) {
    // control catepillar!
    signal sig;

    get_cmd(opr, &sig);

    // operate DC Morter
    analogWrite(L_CATEPILLAR    , PWM_L_CATE_DEFAULT     * sig.ln);
    analogWrite(L_CATEPILLAR_REV, PWM_L_CATE_REV_DEFAULT * sig.lr);
    analogWrite(R_CATEPILLAR    , PWM_R_CATE_DEFAULT     * sig.rn);
    analogWrite(R_CATEPILLAR_REV, PWM_R_CATE_REV_DEFAULT * sig.rr);
    return true;
}

bool contrl_robot_arm(opr op) {
    // control robot arm!
    signal sig;

    get_cmd(opr, &sig);

    // TODO: analogwrite
    analogWrite(ROBOT_ARM_UP  , PWM_ARM_DEFAULT     * sig.rn);
    analogWrite(ROBOT_ARM_DOWN, PWM_ARM_REV_DEFAULT * sig.rr);
    return true;
}

bool contrl_robot_hand(opr op) {
    // control robot hand
    signal sig;

    get_cmd(opr, &sig);

    analogWrite(ROBOT_HAND_OPEN,  PWM_HAND_DEFAULT     * sig.rn);
    analogWrite(ROBOT_HAND_CLOSE, PWM_HAND_REV_DEFAULT * sig.rr);
    return true;
}

bool contrl_heater(bool is_on) {
    // control heater
    if (is_on) {
        analogWrite(HEATER, PWM_HEATER_DEFAULT);
    } else {
        analogWrite(HEATER, 0);
    }

    return true;
}

// function

bool get_cmd(opr op, signal* sig) {
    char ln, lr, rn, rr;

    ln = (op & L_NORMAL)  == OPR_L_NORMAL;
    lr = (op & L_REVERSE) == OPR_L_REVERSE;
    rn = (op & R_NORMAL)  == OPR_R_NORMAL;
    rr = (op & R_REVERSE) == OPR_R_REVERSE;

    sig->ln = (int)ln;
    sig->lr = (int)lr;
    sig->rn = (int)rn;
    sig->rr = (int)rr;
    return;
}

