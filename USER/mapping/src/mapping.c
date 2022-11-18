#include "mapping.h"
double* mapp(int a, double x, double y, double omiga){
	double t[2];
	t[0] = (acos(x/a)*abs(y)/y)/omiga;
	if(y>=0){
		t[1]=1.414*y+a*(1-sin(omiga*t[0]));
	}
	else{
		t[1]=a-1.414*y-a*sin(omiga*t[0]);
	}
	return t;
};


