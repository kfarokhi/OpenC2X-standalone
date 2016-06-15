#ifndef UTILITY_COMMUNICATIONCLIENT_H_
#define UTILITY_COMMUNICATIONCLIENT_H_

#include <string>
#include <zmq.hpp>
#include <utility/zhelpers.hpp>
#include <utility/LoggingUtility.h>


class CommunicationClient {
public:
	CommunicationClient(std::string ownerModule, std::string portOut, int expNo);
	~CommunicationClient();
	std::string sendRequest(std::string envelope, std::string request, int timeout, int retries);
	void init();

private:
	std::string mOwnerModule;
	std::string mPortOut;

	zmq::context_t* mContext;
	zmq::socket_t* mClient;

	LoggingUtility* mLogger;
};

#endif