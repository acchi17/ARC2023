#include <stdbool.h>

// define pin

#define HEATER            5   // degial pin 05
#define ROBOT_ARM_UP     23   // degial pin 10
#define ROBOT_ARM_DOWN   24   // degial pin 11
#define ROBOT_HAND_OPEN  25   // degial pin 12
#define ROBOT_HAND_CLOSE 26   // degial pin 13
#define L_CATEPILLAR     17   // degial pin 08
#define L_CATEPILLAR_REV 18   // degial pin 09
#define R_CATEPILLAR     15   // degial pin 06
#define R_CATEPILLAR_REV 16   // degial pin 07

// define PWM

// default
#define PWM_DEFAULT 255

#define PWM_ARM_DEFAULT        PWM_DEFAULT
#define PWM_ARM_REV_DEFAULT    PWM_DEFAULT
#define PWM_HAND_DEFAULT       PWM_DEFAULT
#define PWM_HAND_REV_DEFAULT   PWM_DEFAULT
#define PWM_L_CATE_DEFAULT     PWM_DEFAULT
#define PWM_L_CATE_REV_DEFAULT PWM_DEFAULT
#define PWM_R_CATE_DEFAULT     PWM_DEFAULT
#define PWM_R_CATE_REV_DEFAULT PWM_DEFAULT

// define type

typedef char opr;

// COMMAND

// for CATEPILLAR

#define OPR_L_NORMAL  (1 << 3)
#define OPR_L_REVERSE (1 << 2)
#define OPR_R_NORMAL  (1 << 1)
#define OPR_R_REVERSE (1 << 0)

// OTHER (ROBOT ARM, ROBOT HAND)

#define OPR_REST      0
#define OPR_NORMAL    OPR_R_NORMAL
#define OPR_REVERSE   OPR_R_REVERSE

// for ROBOT HAND

#define HAND_REST     OPR_REST
#define HAND_OPEN     OPR_NORMAL
#define HAND_CLOSE    OPR_REVERSE

// operate ARM

#define ARM_REST      OPR_REST
#define ARM_UP        OPR_NORMAL
#define ARM_DOWN      OPR_REVERSE

// operate CATEPILLAR

#define CTPL_REST     OPR_REST                      // Rest
#define CTPL_FWRD     OPR_L_NORMAL  | OPR_R_NORMAL  // Forward
#define CTPL_BKWD     OPR_L_REVERSE | OPR_R_REVERSE // Backward
#define CTPL_LFWD                     OPR_R_NORMAL  // Left Forward
#define CTPL_RFWD     OPR_L_NORMAL                  // Right Forward
#define CTPL_LBWD                     OPR_R_REVERSE // Left  Backward
#define CTPL_RBWD     OPR_L_REVERSE                 // Right Backward
#define CTPL_LTRN     OPR_L_REVERSE | OPR_R_NORMAL  // Left  Turn
#define CTPL_RTRN     OPR_L_NORMAL  | OPR_R_REVERSE // Right Turn



// setup Pin mode
void init_pinMode(void);

// operate arduino
bool contrl_catepillar(opr);
bool contrl_robot_arm(opr);
bool contrl_robot_hand(opr);
bool contrl_heater(bool);

// emergency stop
void emergency_stop();
