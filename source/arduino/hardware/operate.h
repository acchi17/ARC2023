// define pin
#define HEATER           0
#define ROBOT_ARM        0
#define ROBOT_ARM_REV    0
#define ROBOT_HAND       0
#define ROBOT_HAND_REV   0
#define L_CATEPILLAR     0
#define L_CATEPILLAR_REV 0
#define R_CATEPILLAR     0
#define R_CATEPILLAR_REV 0

// define PWM

// default
#define PWM_HEATER_DEFAULT     255
#define PWM_ARM_DEFAULT        255
#define PWM_ARM_REV_DEFAULT    255
#define PWM_HAND_DEFAULT       255
#define PWM_HAND_REV_DEFAULT   255
#define PWM_L_CATE_DEFAULT     255
#define PWM_L_CATE_REV_DEFAULT 255
#define PWM_R_CATE_DEFAULT     255
#define PWM_R_CATE_REV_DEFAULT 255

// define enum

// operate hand

typedef enum {
    REST,
    OPEN,
    CLOSE,
} ophand;

// operate arm

typedef enum {
    REST,
    UP,
    DOWN,
} oparm;

// operate catepillar

// plan 1
typedef enum {
    REST,
    FORWARD,
    BACKWARD,
    RIGHT,
    LEFT,
} direction;

// plan 2

// typedef enum {
//     REST,       // Rest
//     LFWD,       // Left  Forward
//     RFWD,       // Right Forward
//     LBWD,       // Left  Backward
//     RBWD,       // Right Backward
//     LTRN,       // Left  Turn
//     RTRN,       // Right Turn
// } derection;

// plan 3

//typedef struct {
//    int left,
//    int right,
//} direction;


// function

// setup Pin mode
void init(void);

// operate arduino
bool contrl_catepillar(direction);
bool contrl_robot_arm(oparm);
bool contrl_robot_hand(ophand);
bool contrl_heater(bool);

