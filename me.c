#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>

void threadrx() {
	utun_netif_sync_rx(kern_nexus_provider_t nxprov, kern_nexus_t nexus,
				   kern_channel_ring_t rx_ring, uint32_t flags);
}
void threadrw() {
	utun_netif_tx_doorbell(kern_nexus_provider_t nxprov, kern_nexus_t nexus,
					   kern_channel_ring_t ring, __unused uint32_t flags);
}

int main() {
	NSLog(@"starting race now!!!");

	for (int i = 0; i < 10; i++)	{
		threadrx();
		threadrw();
	}
}
