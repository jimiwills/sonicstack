#include <iostream>
#include <sstream>
#include <cmath>

#define PI 3.14159265

class Generator {
	public:
	int rate;
	float freqpower = 1/2;
	float vibdepth = 1/50;
	float vibfreq = 10;
	float vol = 1;
	
	int generate(float length, int freq, unsigned char* buffer, int start){
		int W = rate/(float)freq;
		int L = length * (float) rate;
		// force a whole number of waves into the time
		int cycles = length * (float)freq;
		float f = (float)cycles/length;
		
		for(int i=0; i<L; i++){
			float p = i/L; // proportion of the way through the note
			p = pow(p, freqpower);
			float t = p * length;
			float z = 1.0; // but could be p * PI for sin envelope
			
			float fm = f * (1.0 + vibdepth*sin(2.0*PI*t*vibfreq));
			
			float c = p * L;
			float x = 2.0*PI*fm*(float)i/rate;
			float y = vol * sin(x) * sin(z);
			buffer[start+i] = (unsigned char) (y+1)/2.0*255.0; 
			// TODO: move the conversion to the renderer 
			// (because post-processing expects -1 < x < 1 )
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
