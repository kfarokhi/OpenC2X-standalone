#ifndef SENDTOHARDWAREVIAMAC_H_
#define SENDTOHARDWAREVIAMAC_H_

#include <utility/LoggingUtility.h>
#include <utility/Constants.h>
#include <string.h>

#include <unistd.h> // Std. Fct.  getuid() and read()
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/ether.h>

#include <linux/if_packet.h>

#include <sys/ioctl.h>
#include <net/if.h>


class SendToHardwareViaMAC {
public:
	SendToHardwareViaMAC(string ethernetDevice);
	virtual ~SendToHardwareViaMAC();
	void send(string* msg, int priority);
private:
	LoggingUtility* mLogger;

	int mSocket;
	//ethernet header
	struct ether_header mEth_hdr;
	//information of network interface
	struct ifreq mIfr;
	//socket address data structure for PACKET sockets
	struct sockaddr_ll mTo_sock_addr;

};

#endif /* SENDTOHARDWAREVIAMAC_H_ */