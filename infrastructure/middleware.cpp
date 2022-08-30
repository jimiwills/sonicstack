#include <stdio.h>
#include <string>

/*class Request {
public:
	string Message;
}*/

class Middleware {
public:
	Middleware()
	{
		hasNext = false;
	};
	void SetNext(Middleware &next){
		this->next = &next;
		hasNext = true;
	}
	void Next(){
		if(hasNext){
			printf("Running next...\n");
			next->Invoke();
		}
		else {
			printf("No more nexts.\n");
		}
	}
	virtual void Invoke() = 0;
private:
	Middleware *next;
	bool hasNext;
};

class ControllerFirstMiddleware : public Middleware {
	public:
	ControllerFirstMiddleware(){}
	void Invoke(){
		printf("Hi from controller\n");
		Next();
		printf("Bye from controller\n");
	}
};

class Controller {
public:
	Controller(Middleware &t){
		this->target = &t;
		ControllerFirstMiddleware cfm;
		this->SetFirst(cfm);
		this->SetLast(cfm);
		this->last->SetNext(t);
	}
	void SetFirst(Middleware &m){
		this->first = &m;
	}
	void SetLast(Middleware &m){
		this->first = &m;
	}
	void Add(Middleware &middleware){
		this->last->SetNext(middleware);
		this->SetLast(middleware);
		middleware.SetNext(*(this->target));
	}
	void Invoke(){
		this->first->Invoke();
	}
private:
	Middleware *first;
	Middleware *last;
	Middleware *target;
};

class MyMiddleWare1 : public Middleware {
public:
	MyMiddleWare1(){}
	void Invoke(){
		printf("Hi from 1\n");
		Next();
		printf("Bye from 1\n");
	};
};

class MyMiddleWare2 : public Middleware {
public:
	MyMiddleWare2(){}
	void Invoke(){
		printf("Hi from 2\n");
		Next();
		printf("Bye from 2\n");
	};
};

int main(int argc, char *argv[]){
	MyMiddleWare1 mm1;
	MyMiddleWare2 mm2;
	Controller controller(mm2); // the target
	controller.Add(mm1); // insert the others
	controller.Invoke(); // invoke the controller's first middleware
	return 0;
};

