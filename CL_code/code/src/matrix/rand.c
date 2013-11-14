/*
    LFMM, file: rand.c
    Copyright (C) 2012 Eric Frichot

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>  
#include <unistd.h>
#include "rand.h"
#include "matrix.h"
#include "cholesky.h"

// Don t forget to initialize the random (init_random)

unsigned long mix(unsigned long a, unsigned long b, unsigned long c)
{
    	a=a-b;  a=a-c;  a=a^(c >> 13);
    	b=b-c;  b=b-a;  b=b^(a << 8);
	c=c-a;  c=c-b;  c=c^(b >> 13);
    	a=a-b;  a=a-c;  a=a^(c >> 12);
    	b=b-c;  b=b-a;  b=b^(a << 16);
    	c=c-a;  c=c-b;  c=c^(b >> 5);
    	a=a-b;  a=a-c;  a=a^(c >> 3);
    	b=b-c;  b=b-a;  b=b^(a << 10);
    	c=c-a;  c=c-b;  c=c^(b >> 15);

    	return c;
}

// init_random

void init_random(long long *seed)
{
	unsigned long s = (unsigned long)(*seed);
	if (*seed < 0)
		s = (unsigned long) mix(clock(), time(NULL), getpid());

	srand(s);

	*seed = s;
}

// drand

double drand()
{				/* uniform distribution, (0..1] */
	return (rand() + 1.0) / (RAND_MAX + 1.0);
}

// frand

float frand()
{				/* uniform distribution, (0..1] */
	return (float)(rand() + 1.0) / (RAND_MAX + 1.0);
}

// rand_ind

int rand_int(int size)
{
	int i;
	float r = frand();
	float sum = 0;

	for (i = 0; i < size; i++) {
		sum += 1.0;
		if (r <= sum) {
			return i;
		}
	}
	return -1;
}

// rand_float

float rand_float(float min, float max)
{
	return frand() * (max - min) + min;
}

// rand_double

double rand_double(double min, double max)
{
	return drand() * (max - min) + min;
}

// rand_matrix_float

void rand_matrix_float(float *A, int M, int N)
{
	int i;
	for (i = 0; i < N * M; i++) {
		A[i] = drand();
	}
}

// rand_matrix_double

void rand_matrix_double(double *A, int M, int N)
{
	int i;
	for (i = 0; i < N * M; i++) {
		A[i] = drand();
	}
}

// rand_normal

double rand_normal(double mean, double var)
{
	return sqrt(var) * sqrt(-2 * log(drand())) * cos(2 * PI * drand()) +
	    mean;
}

// rand_normal_r

double rand_normal_r()
{
	return sqrt(-2 * log(drand())) * cos(2 * PI * drand());
}

// mvn_rand

void mvn_rand(double *mu, double *L, int D, double *y)
{

	int i, j;
	double *x = (double *)malloc(D * sizeof(double));

	for (i = 0; i < D; i++)
		x[i] = rand_normal_r();

	for (i = 0; i < D; i++) {
		y[i] = mu[i];
		for (j = 0; j < D; j++) {
			y[i] += L[j * D + i] * x[j];
		}
	}

	free(x);
}

// rand_exp

void rand_exp(float alpha, float *r)
{
	*r = -alpha * log(frand());
}

// rand_exp_int

int rand_exp_int(float mean)
{
	float r;
	rand_exp(mean, &r);

	return (int)r + 1;
}

// rand_vector

int rand_vector(float *Pi, int size)
{
	int i;
	float r = frand();
	float sum = 0;

	for (i = 0; i < size; i++) {
		sum += Pi[i];
		if (r <= sum) {
			return i;
		}
	}
	return -1;
}

// rand_gamma

double rand_gamma(int alpha, double beta)
{
	int i = 0;
	double y = 0;

	for (i = 0; i < alpha; i++) {
		y += log(drand());
	}
	y *= -beta;

	return y;
}

// zscore2pvalue

long double zscore2pvalue(long double z)
{
	long double tmp = erfcl((long double)( z * M_SQRT1_2))/(long double)(2.0);
	tmp = (long double)(2.0)*tmp;
	return  tmp;
}
