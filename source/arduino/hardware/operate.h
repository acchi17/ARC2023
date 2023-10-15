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
#define PWM_ARM_DEF        255
#define PWM_HAND_DEF       255
#define PWM_HAND_DEF_REV   255
#define PWM_HEATER_DEF     255
#define PWM_HEATER_DEF_REV 255
#define PWM_L_CATE_DEF     255
#define PWM_L_CATE_DEF_REV 255
#define PWM_R_CATE_DEF     255
#define PWM_R_CATE_DEF_REV 255

// define enum

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

