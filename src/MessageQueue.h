/*
 * MessageQueue.h
 *
 *  Created on: 10 lut 2018
 *      Author: ppize
 */



#ifndef MESSAGEQUEUE_H_
#define MESSAGEQUEUE_H_
#include <queue>
#include <iostream>
#include <pthread.h>
using namespace std;

class MessageQueue {
public:
	MessageQueue(string q_name);
	virtual ~MessageQueue();
	void insert(string msg);
	void display();
	void get();
    friend std::ostream& operator<< (std::ostream &out, const MessageQueue &queue)
        {
            out <<"queue name: "<<queue.name.c_str();
            return out;
        };


private:
	string name;
	std::queue<string> queue;
};

#endif /* MESSAGEQUEUE_H_ */
