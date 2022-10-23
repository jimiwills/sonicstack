#include <iostream>
#include <sstream>
#include <cmath>

#define PI 3.14159265

class Generator {
	public:
	int rate;
	int generate(float length, int freq, unsigned char* buffer, int start){
		int W = rate/(float)freq;
		int L = length * (float) rate;
		
		// TODO: force a whole number of waves into the time
		
		// ALSO TODO: copy the maths from buidling-music-logic/* into here
		
		for(int i=0; i<L; i++){
			buffer[start+i] = (unsigned char) ((sin(2*PI*freq* i/rate)+1)/2*255.0);
		}
		return start+L;
	}
};

int addSemitone(int note){
	return (int) (pow(2.0, 1.0/12.0) * float(note));
}
int addWholetone(int note){
	return (int) (pow(2.0, 1.0/6.0) * float(note));
}

int main(int argc, char *argv[])
{
	int A = 440;
	int B = addWholetone(A);
	int C = addSemitone(B);
	int D = addWholetone(C);
	int E = addWholetone(D);
	int F = addSemitone(E);
	int G = addWholetone(F);
	int a = addWholetone(G);
	int b = addWholetone(a);

	int rate;
	std::stringstream(argv[1]) >> rate;
	
	Generator gen;
	gen.rate = rate;
	
	unsigned char buffer[2*1024*1024];
	
	int l = 0;
	l = gen.generate(0.4, A, buffer, l);
	l = gen.generate(0.4, C, buffer, l);
	l = gen.generate(0.4, B, buffer, l);
	l = gen.generate(0.4, D, buffer, l);
	l = gen.generate(0.4, C, buffer, l);
	l = gen.generate(0.4, E, buffer, l);
	l = gen.generate(0.4, D, buffer, l);
	l = gen.generate(0.4, F, buffer, l);
	l = gen.generate(0.4, E, buffer, l);
	l = gen.generate(0.4, G, buffer, l);
	l = gen.generate(0.4, F, buffer, l);
	l = gen.generate(0.4, a, buffer, l);
	l = gen.generate(0.4, G, buffer, l);
	l = gen.generate(0.4, b, buffer, l);
	l = gen.generate(0.8, a, buffer, l);
	fwrite(buffer, 1, l, stdout);
	
	return 0;
}
