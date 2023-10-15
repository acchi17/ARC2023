#include <operate.h>

// define

typedef struct {
    int left,
    int left_rev,
    int right,
    int right_rev,
} opr_ctpl;

void get_opr_ctpl(opr_ctpl, direction);

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
    opr_ctpl opr;

    // direction to operation
    get_opr_ctpl(&opr, dir);

    // operate DC Morter
    analogWrite(L_CATEPILLAR    , PWM_L_CATE_DEFAULT     * opr.left);
    analogWrite(L_CATEPILLAR_REV, PWM_L_CATE_REV_DEFAULT * opr.left_rev);
    analogWrite(R_CATEPILLAR    , PWM_R_CATE_DEFAULT     * opr.right);
    analogWrite(R_CATEPILLAR_REV, PWM_R_CATE_REV_DEFAULT * opr.right_rev);
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

// function

bool get_opr_ctpl(opr_ctpl* opr, direction d) {
    // direction --> outout pin
    switch (d) {
    case FORWARD:
        opr->left      = 1;
        opr->left_rev  = 0;
        opr->right     = 1;
        opr->right_rev = 0;
        break;
    case BACKWARD:
        opr->left      = 0;
        opr->left_rev  = 1;
        opr->right     = 0;
        opr->right_rev = 1;
        break;
    case RIGHT:
        opr->left      = 1;
        opr->left_rev  = 0;
        opr->right     = 0;
        opr->right_rev = 1;
        break;
    case LEFT:
        opr->left      = 0;
        opr->left_rev  = 1;
        opr->right     = 0;
        opr->right_rev = 1;
        break;
    case REST:
    default:
        opr->left      = 0;
        opr->left_rev  = 0;
        opr->right     = 0;
        opr->right_rev = 0;
    }
    return 0;
}

