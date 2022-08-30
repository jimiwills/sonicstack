#include <stdio.h>

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
	mm1.SetNext(mm2);
	mm1.Invoke();
	return 0;
};

