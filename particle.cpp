#include "particle.h"
#include <ctime>
#include <cmath>
#include <fstream>
#include<iostream>
#include <omp.h>
particle::particle(int N,float r,int del)
{ 
	this->N = N;
	this->r = r;
	this->del = del;
	this->V = V;


	Xx = new double[N];
	Yy = new double[del];
	
    p = new koord[N];
    
}

void particle::Nach_polon()
{
    
	Xx = new double[N];
    #pragma omp parallel for
    for (int i = 0; i < N; i++)
    {
		p[i].x = (w * 1.) / 2.;
        p[i].y = (h * 1.) / 2.;
		Xx[i] = p[i].x;
    }
}
void particle::Nach_polon2D()
{
    #pragma omp parallel for
	for (int i = 0; i < N; i++)
	{
		p[i].x = (w * 1.) / 2.;
		p[i].y = (h * 1.) / 2.;
		
	}
}
void particle::Move()
{
	srand(time(NULL));
	
	Xx = new double[N];
	

	for (int i = 0; i < N; i++)
	{
		int r = rand() % 2-0+0;
		if (r == 0)
			p[i].x += V;
		else if (r == 1)
			p[i].x -= V;
        p[i].y = (h * 1.) / 2.;
		Xx[i] = p[i].x;
	}
	bool flag;
	do
	{
		flag = false;
        #pragma omp parallel for
		for (int i = 0; i < N - 1; i++)           
			for (int j = i + 1; j < N; j++)
			{
				if (abs(p[i].x - p[j].x) < r)
				{
					flag = true;
					if (p[i].x > p[j].x)
					{
						p[i].x += r / 2;
						p[j].x -= r / 2;
					}
					else
					{
						p[j].x += r / 2;
						p[i].x -= r / 2;
					}
				}
			}
         #pragma omp parallel for
		for (int i = 0; i < N; i++) //столкновение со стенками 
		{
			if (p[i].x < r) p[i].x +=V;//левый угол горизонта
			if (p[i].x > w - r) p[i].x -=V; // правый угол горизонта
			Xx[i] = p[i].x;
		}
		
	} while (flag == true);

}
void particle::massiveXY()
{
	double W = w;
	double* X = new double[del];
  #pragma omp parallel for
	for (int i = 0;i < del;i++)
	{
		X[i] = W / (del * 1.) * (i + 1);
	}
	int chet2 = 0;
    
	for (int i = 0;i < del;i++)
	{
		int chet1 = 0;
        #pragma omp parallel for reduction(+:chet1)
		for (int j = 0;j < N;j++)
		{
			if (Xx[j] < X[i])
			{
				chet1 += 1;
			}
		}
		
		Yy[i] = chet1-chet2;
		chet2 = chet1;
	}
	
}
void particle::Move2D()
{

	for (int i = 0; i < N; i++)
	{
		int r = rand() % 2;
		if (r == 0)
			p[i].x += V;
		else if (r == 1)
			p[i].x -= V;
		r = rand() % 3;
		if (r == 0)
			p[i].y += V;
		else if (r == 1)
			p[i].y -= V;
	}

	bool flag;
	do
	{
		flag = false;
         #pragma omp parallel for
		for (int i = 0; i < N - 1; i++)
			for (int j = i + 1; j < N; j++)
			{
				if (abs(p[i].x - p[j].x) < r)
				{
					flag = true;
					if (p[i].x > p[j].x)
					{
					       p[i].x += r / 2;
						   p[j].x -= r / 2;
					}
					else
					{
						p[j].x += r / 2;
						p[i].x -= r / 2;
					}
				}
				if (abs(p[i].y - p[j].y) < r)
				{
					flag = true;
					if (p[i].y > p[j].y)
					{
						p[i].y += r / 2;
						p[j].y -= r / 2;
					}
					else
					{
						p[j].y += r / 2;
						p[i].y -= r / 2;
					}
				}
			}
        #pragma omp parallel for
		for (int i = 0; i < N; i++) //столкновение со стенками 
		{
			if (p[i].x < r ) p[i].x += V;//левый угол горизонта
			if (p[i].x > w - r) p[i].x -= V;
			if (p[i].y < r) p[i].y += V;
			if (p[i].y > h - r) p[i].y -= V; //горизонт
		}
	} while (flag == true);

}
double STD(double* x, int N)
{
	double sum = 0;
	double srednee = 0;
	int g;
#pragma omp parallel for reduction(+:srednee)
	for (g = 1;g <= N;g++)
	{
		srednee += x[g];
	}
	srednee = srednee / (N * 1.);
#pragma omp parallel for reduction(+:sum)
	for (g = 1;g <= N;++g)
	{
		sum += (x[g] - srednee) * (x[g] - srednee);
	}
	sum = sum / (N * 1.);
	return sqrt(sum);
}
double MNK(double* x, double* y, int N)
{
	double a11 = N;//10
	double a12 = 0;
	for (int i = 1;i <= N;i++)
	{
		a12 += x[i];
	}
	double a21 = a12;//15....
	double a22 = 0;
	for (int i = 1;i <= N;i++)
	{
		a22 += x[i] * x[i];//27.6....
	}
	double d1 = 0;
	for (int i = 1;i <= N;i++)
	{
		d1 += y[i];//36.39...
	}
	double d2 = 0;
	for (int i = 1;i <= N;i++)
	{
		d2 += y[i] * x[i];//59
	}
	double D = a11 * a22 - a21 * a12;
	//double D1 = d1 * a22 - d2 * a12;
	double D2 = a11 * d2 - a21 * d1;
	return D2 / D;
}
double HCALC(double* Y, int L)
{

	int pmax = 10;

	double* dX = new double[L - pmax];

	double* E_p = new double[pmax];

	double* Eta_p = new double[pmax];
	dX[0] = 0;
	E_p[0] = 0;
	Eta_p[0] = 0;

	for (int p = 1;p <= pmax;p++)
	{
		for (int i = 1;i <= L - pmax;i++)
		{
			dX[i] = Y[i + p] - Y[i];
		}
		double s_p = STD(dX, L - pmax);
		E_p[p] = log(p * 1.);
		Eta_p[p] = log(s_p);

	}

	return MNK(E_p, Eta_p, pmax);


}
