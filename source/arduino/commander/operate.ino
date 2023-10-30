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
void init_pinMode(void) {
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

    if (op & CTPL_STOP) {
        analogWrite(L_CATEPILLAR    , 255);
        analogWrite(L_CATEPILLAR_REV, 255);
        analogWrite(R_CATEPILLAR    , 255);
        analogWrite(R_CATEPILLAR_REV, 255);
        return true;
    }

    get_cmd(op, &sig);

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

    if (op & ARM_STOP) {
        analogWrite(ROBOT_ARM_UP  , 255);
        analogWrite(ROBOT_ARM_DOWN, 255);
        return true;
    }

    get_cmd(op, &sig);

    // TODO: analogwrite
    analogWrite(ROBOT_ARM_UP  , PWM_ARM_DEFAULT     * sig.rn);
    analogWrite(ROBOT_ARM_DOWN, PWM_ARM_REV_DEFAULT * sig.rr);
    return true;
}

bool contrl_robot_hand(opr op) {
    // control robot hand
    signal sig;

    if (op & HAND_STOP) {
        analogWrite(ROBOT_HAND_OPEN,  255);
        analogWrite(ROBOT_HAND_CLOSE, 255);
        return true;
    }

    get_cmd(op, &sig);

    analogWrite(ROBOT_HAND_OPEN,  PWM_HAND_DEFAULT     * sig.rn);
    analogWrite(ROBOT_HAND_CLOSE, PWM_HAND_REV_DEFAULT * sig.rr);
    return true;
}

bool contrl_heater(bool is_on) {
    // control heater
    if (is_on) {
        digitalWrite(HEATER, HIGH);
    } else {
        digitalWrite(HEATER, LOW);
    }

    return true;
}

// emergency stop
void emergency_stop() {
    contrl_heater(false);
    contrl_robot_hand(HAND_REST);
    contrl_robot_arm(ARM_REST);
    contrl_catepillar(CTPL_REST);
    return true;
}

// function

void get_cmd(opr op, signal* sig) {
    char ln, lr, rn, rr;

    ln = (op & OPR_L_NORMAL)  == OPR_L_NORMAL;
    lr = (op & OPR_L_REVERSE) == OPR_L_REVERSE;
    rn = (op & OPR_R_NORMAL)  == OPR_R_NORMAL;
    rr = (op & OPR_R_REVERSE) == OPR_R_REVERSE;

    sig->ln = (int)ln;
    sig->lr = (int)lr;
    sig->rn = (int)rn;
    sig->rr = (int)rr;
    return;
}

