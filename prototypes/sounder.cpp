#include <iostream>
#include <sstream>
#include <cmath>

#define PI 3.14159265

class Generator {
	public:
	int rate;
	int generate(float length, int freq, unsigned char* buffer){
		int W = rate/(float)freq;
		int L = length * (float) rate;
		for(int i=0; i<L; i++){
			buffer[i] = (unsigned char) sin(2*PI*freq* i/rate)*255.0;
		}
		return L;
	}
};

int addSemitone(int note){
	return (int) pow(2, 1/12) * float(note);
}
int addWholetone(int note){
	return (int) pow(2, 1/6) * float(note);
}

int main(int argc, char *argv[])
{
	int A = 440;
	int B = addWholetone(A);
	int C = addSemitone(B);
	int D = addWholetone(C);
	int E = addWholetone(D);
	int F = addWholetone(E);
	int G = addWholetone(F);
	int a = addWholetone(G);
	
	int rate;
	std::stringstream(argv[1]) >> rate;
	
	Generator gen;
	gen.rate = rate;
	
	unsigned char buffer[78000];
	
	int l = gen.generate(0.4, A, buffer);
	fwrite(buffer, 1, l, stdout);
	/*std::cout << gen.generate(0.4, B);
	std::cout << gen.generate(0.4, C);
	std::cout << gen.generate(0.4, D);
	std::cout << gen.generate(0.4, E);
	std::cout << gen.generate(0.4, F);
	std::cout << gen.generate(0.4, G);
	std::cout << gen.generate(1, a);
	*/
	return 0;
}
