#include <operate.h>

// setup
void init() {
    // pin mode
    pinMode(HEATER,       OUTPUT);
    pinMode(ROBOT_ARM,    OUTPUT);
    pinMode(ROBOT_HAND,   OUTPUT);
    pinMode(L_CATEPILLAR, OUTPUT);
    pinMode(R_CATEPILLAR, OUTPUT);
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

