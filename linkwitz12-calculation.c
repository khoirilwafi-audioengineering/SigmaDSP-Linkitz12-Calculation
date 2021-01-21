/* program untuk menghitung filter Linkwitz 12 dB/oct */

#include "math.h"

extern float A1, B0, B1;

float omega, SN, CS, gainL, A0;
float PI = 3.141592653;

void calculate_LPF(float FC)
{
	gainL = pow(10,(0/20));
	
	omega = 2 * PI * FC / 48000;
	
	SN = sin(omega);
	CS = cos(omega);
	
	A0 = SN + CS + 1;
	
	A1 = -1 * (SN - CS - 1) / A0;
	B0 = gainL * SN / A0;
	B1 = B0;
}

void calculate_HPF(float FC)
{
	gainL = pow(10,(0/20));
	
	omega = 2 * PI * FC / 48000;
	
	SN = sin(omega);
	CS = cos(omega);
	
	A0 = SN + CS + 1;
	
	A1 = -1 * (SN - CS - 1) / A0;
	B0 = gainL * (1 + CS) / A0;
	B1 = -1 * B0;
}
