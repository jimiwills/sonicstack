#include <iostream>
#include <sstream>


class Generator {
	unsigned char buffer[8000];
	public:
	int rate;
	void generate(){
		for(int i=0; i<8000; i++){
			if((i/10) % 2 == 0){
				buffer[i] = 'A';
			}
			else {
				buffer[i] = 'z';
			}
		}
	}
	void print(){
		cout << buffer;
	}
};

int main(int argc, char *argv[])
{
	cerr << argv[0];
	int rate;
	stringstream(argv[1]) >> rate;
	
	Generator gen;
	gen.rate = rate;
	
	gen.generate();
	gen.print();
	return 0;
}
