#ifndef RTOS_H_
#define RTOS_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "queue.h"
#include "semphr.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "queue.h"
#include "semphr.h"

enum
{
  RAK_TASK_PRIO_LOWEST  = 0, // Idle task, should not be used
  RAK_TASK_PRIO_LOW     = 1, // Loop
  RAK_TASK_PRIO_NORMAL  = 2, // Timer Task, Callback Task
  RAK_TASK_PRIO_HIGH    = 3, // Bluefruit Task
  RAK_TASK_PRIO_HIGHEST = 4,
};

// Visible only with C++
#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus


#ifdef __cplusplus
}
#endif

#endif /* RTOS_H_ */
