#pragma once

struct koord
{
	double x, y;
};
class particle
{
public:
	float r;
	int N;
	int del;
	

	koord* p;
	double V;
	int w, h;
	particle(int N,float r,int del);
	
	
	double* Xx;
	double* Yy;

	void Nach_polon();
	void Move();
	void Move2D();
	void Nach_polon2D();
	void massiveXY();
};

double STD(double* x, int N);
double MNK(double* x, double* y, int N);
double HCALC(double* Y, int L);