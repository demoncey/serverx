/*
 * Service.cpp
 *
 *  Created on: 26 lut 2018
 *      Author: ppize
 */

#include "Service.h"
#include <mutex>

extern std::mutex global_mu;

Service::Service(std::string service_name,std::string url,shared_ptr<MessageQueue> queue):service_name(service_name),url(url),queue(queue) {
}

Service::~Service() {
	// TODO Auto-generated destructor stub
}


void Service::callback(std::string msg){
	while(true){
		std::lock_guard<std::mutex> lock(global_mu);//unlock when guard is destoryed (out of scope)
		cout<<"*************************"<<endl;
		cout<<"  "<<msg.c_str()<<" "<<endl;
		cout<<"  "<<*queue.get()<<" "<<endl;
		cout<<"----------"<<endl;
		this->run();
		cout<<"----------"<<endl;
		cout<<"*************************"<<endl;
		std::this_thread::sleep_for(1s);


	}
}




