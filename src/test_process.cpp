//============================================================================
// Name        : test_process.cpp
// Author      : ppi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <memory>
#include <thread>
#include <mutex>
#include <string>
#include <queue>

#include "MessageQueue.h"
#include "service/Service.h"


#define PARENT "Parent process is working"
#define CHILD "Child process is working"
#define FAILED "Fork failed"
using namespace std;

std::mutex global_mu;

void child();










int main() {
	pid_t child_pid;
	child_pid=fork();
	if(child_pid==0){
		cout<<CHILD<<endl;
		child();
	}else if(child_pid>0){
		cout<<PARENT<<endl;
	}else{
		cout<<FAILED<<endl;
	}

	return 0;
}



void child(){
	string name="queue";
	unique_ptr<MessageQueue> queue(new MessageQueue("unique queue"));
	shared_ptr<MessageQueue> queue2(new MessageQueue("shared queue"));


	auto master_lambda = [](auto a,unique_ptr<MessageQueue>& queue) {
		int i=1;
		//std::lock_guard<std::mutex> lock(mu);//unlock when guard is out of scope and destoryed
		while(true){
			std::lock_guard<std::mutex> lock(global_mu);//unlock when guard is out of scope and destoryed
			std::this_thread::sleep_for(1s);
			cout<<&global_mu<<endl;
			queue->insert(std::to_string(i));
			std::this_thread::sleep_for(1s);
			cout<<"----------------------------------------------------------------"<<endl;
			i++;
		}

	};
//	auto thread_lambda = [](auto a,unique_ptr<MessageQueue>& queue) {
//		int i=1;
//		while(true){
//			std::lock_guard<std::mutex> lock(global_mu);//unlock when guard is destoryed
//			cout<<"****************************************************************"<<endl;
//			cout<<&global_mu<<endl;
//			cout<<a<<": "<<endl;
//			queue->get();
//			//queue->display();
//			cout<<a<<endl;
//
//			std::this_thread::sleep_for(1s);
//			cout<<"****************************************************************"<<endl;
//			i++;
//		}
//	};

//	auto thread_lambda_value = [](auto a,shared_ptr<MessageQueue> queue) {
//		queue->display();
//		while(true){
//			std::lock_guard<std::mutex> lock(global_mu);//unlock when guard is destoryed
//			cout<<queue.use_count()<<endl;
//			cout<<a<<endl;
//			//sleep(1);
//		}
//	};
	string smaster="master";
//	string stext1="thread1";
//	string stext2="thread2";
//	string stext3="thread3";
//	string stext4="thread4";

	std::thread master (master_lambda,smaster,std::ref(queue));


	Service service1("service1","/service1",queue2);
	Service service2("service2","/service2",queue2);

	std::thread th1 (&Service::callback,service1,"Hi i am service 2");
	std::thread th2 (&Service::callback,service2,"Hi i am service 2");
	//std::thread th2 (thread_lambda,stext2,std::ref(queue));
//	std::thread ths1 (thread_lambda_value,stext3,queue2);
//	std::thread ths2 (thread_lambda_value,stext4,queue2);
	master.join();
	th1.join();
	th2.join();
//	ths1.join();
//	ths2.join();
	cout<<queue2.use_count()<<endl;
	cout<<"end child"<<endl;

}
