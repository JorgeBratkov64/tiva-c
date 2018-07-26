#include "tm4c123gh6pm.h"

uint32_t coreClock_1 = 0;                       /* Variables to store core clock values */
uint32_t coreClock_2 = 0;

int main (void)  {
  coreClock_1 = SystemCoreClock;                /* Store value of predefined SystemCoreClock */
  SystemCoreClockUpdate();                      /* Update SystemCoreClock according to register settings */
  coreClock_2 = SystemCoreClock;                /* Store value of calculated SystemCoreClock */
  if (coreClock_2 != coreClock_1)  {            /* Without changing the clock setting both core clock values should be the same */ 
    // Error Handling
  }
  while(1);
}
