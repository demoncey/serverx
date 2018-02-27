/*
 * ServiceManager.h
 *
 *  Created on: 26 lut 2018
 *      Author: ppize
 */

#ifndef SERVICEMANAGER_H_
#define SERVICEMANAGER_H_
#include<string>
#include<utility>
#include<vector>
#include <thread>
#include <memory>
#include"../service/Service.h"

class ServiceManager {
	public:
		ServiceManager();
		void registerService(std::unique_ptr<Service> service,const std::string url){
			v.push_back(std::thread (&Service::callback,*service.get(),"created inside manager"));
		};

		void registerService(Service& service,const std::string url){
			v.push_back(std::thread (&Service::callback,service,"created inside manager"));
		};
		virtual ~ServiceManager();
	private:
		std::vector<std::thread> v;
		void join_all();
		void do_join(std::thread& t);
};

#endif /* SERVICEMANAGER_H_ */
