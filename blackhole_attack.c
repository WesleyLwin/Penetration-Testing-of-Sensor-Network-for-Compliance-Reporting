#include "contiki.h"
#include "net/rime.h"
#include "lib/random.h"
#include "sys/etimer.h"
#include <stdio.h>
 
PROCESS(blackhole_process, "Blackhole Test Logger");
AUTOSTART_PROCESSES(&blackhole_process);
 
PROCESS_THREAD(blackhole_process, ev, data)
{
  static struct etimer timer;
  PROCESS_BEGIN();
 
  printf("Blackhole %u: Process started\n", rimeaddr_node_addr.u8[0]);
 
  etimer_set(&timer, CLOCK_SECOND * 2);
 
  while(1) {
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
    printf("Blackhole %u: Still alive\n", rimeaddr_node_addr.u8[0]);
    etimer_reset(&timer);
  }
 
  PROCESS_END();
}