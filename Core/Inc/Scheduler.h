/*
 * Scheduler.h
 *
 *  Created on: Sep 7, 2023
 *      Author: owenallison
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <stdint.h>

#define START_EVENT 0
#define LEVEL_1_EVENT 1
#define LEVEL_2_EVENT 2
#define LEVEL_3_EVENT 3
#define END_EVENT 4

#define accessStartEvent (1 << START_EVENT)
#define accessLevel1Event (1 << LEVEL_1_EVENT)
#define accessLevel2Event (1 << LEVEL_2_EVENT)
#define accessLevel3Event (1 << LEVEL_3_EVENT)
#define accessEndEvent (1 << END_EVENT)

uint32_t getScheduledEvents();

void addSchedulerEvent(uint32_t event);
void removeSchedulerEvent(uint32_t event);

#endif /* SCHEDULER_H_ */
