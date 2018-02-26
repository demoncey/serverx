/*
 * Service.h
 *
 *  Created on: 26 lut 2018
 *      Author: ppize
 */
#include <string>
#include <memory>

#include "../MessageQueue.h"


#ifndef SERVICE_H_
#define SERVICE_H_

class Service {
public:
	Service(std::string service_name,std::string url,shared_ptr<MessageQueue> queue);
	virtual ~Service();
	void callback(std::string msg);




private:
	std::string service_name;
	std::string url;
	shared_ptr<MessageQueue> queue;

};

#endif /* SERVICE_H_ */
