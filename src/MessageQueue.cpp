/*
 * MessageQueue.cpp
 *
 *  Created on: 10 lut 2018
 *      Author: ppize
 */

#include "MessageQueue.h"
using namespace std;

MessageQueue::MessageQueue(string q_name):name(q_name) {
	// TODO Auto-generated constructor stub

}

MessageQueue::~MessageQueue() {
	// TODO Auto-generated destructor stub
}



void MessageQueue:: display(){
	cout<<name<<endl;
}
void MessageQueue::insert(string msg){
	queue.push(msg);
}
void MessageQueue::get(){
	//pthread_mutex_lock(&tunnel_mutex);
	if(!queue.empty()){
		cout<<queue.front()<<endl;
		queue.pop();
	}
	//pthread_mutex_unlock(&tunnel_mutex);
}

