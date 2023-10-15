#include <operate.h>

// setup
void init() {
    // pin mode
    pinMode(HEATER,           OUTPUT);
    pinMode(ROBOT_ARM,        OUTPUT);
    pinMode(ROBOT_ARM_REV,    OUTPUT);
    pinMode(ROBOT_HAND,       OUTPUT);
    pinMode(ROBOT_HAND_REV,   OUTPUT);
    pinMode(L_CATEPILLAR,     OUTPUT);
    pinMode(L_CATEPILLAR_REV, OUTPUT);
    pinMode(R_CATEPILLAR,     OUTPUT);
    pinMode(R_CATEPILLAR_REV, OUTPUT);
}

// operate

bool contrl_catepillar(direction dir) {
    // control catepillar!
    return true;
}

bool contrl_robot_arm(void) {
    // control robot arm!
    return true;
}

bool contrl_robot_hand(void) {
    // control robot hand
    return true;
}

bool contrl_heater(bool is_on) {
    // control heater
    return true;
}

