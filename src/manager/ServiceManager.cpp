/*
 * ServiceManager.cpp
 *
 *  Created on: 26 lut 2018
 *      Author: ppize
 */

#include "ServiceManager.h"
#include<algorithm>

ServiceManager::ServiceManager() {
	// TODO Auto-generated constructor stub

}

ServiceManager::~ServiceManager() {
	join_all();

}


void ServiceManager::do_join(std::thread& t)
{
    t.join();
}

void ServiceManager::join_all()
{

	for(unsigned i=0;i<v.size();++i)
	{
	   do_join( v[i]);
	}
   // std::for_each(this->v.begin(),this->v.end(),&this->do_join);
}

