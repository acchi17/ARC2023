#include <stdio.h>
#include <stdbool.h>
#include "../hardware/operate.h"

int main() {
    printf("PWM_DEFAULT     = %x\n", PWM_DEFAULT);
    printf("PWM_ARM_DEFAULT = %x\n", PWM_DEFAULT);

    printf("HAND_REST    = %x\n", HAND_REST);
    printf("HAND_NORMAL  = %x\n", HAND_OPEN);
    printf("HAND_REVERSE = %x\n", HAND_CLOSE);

    printf("CTPL_REST    = %x\n", CTPL_REST);
    printf("CTPL_FWRD    = %x\n", CTPL_FWRD);
    printf("CTPL_LFWD    = %x\n", CTPL_LFWD);
    printf("CTPL_RFWD    = %x\n", CTPL_RFWD);
    printf("CTPL_LBWD    = %x\n", CTPL_LBWD);
    printf("CTPL_RBWD    = %x\n", CTPL_RBWD);
    printf("CTPL_LTRN    = %x\n", CTPL_LTRN);
    printf("CTPL_RTRN    = %x\n", CTPL_RTRN);

    
    return 0;
}

