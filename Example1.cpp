// Example 1
//
#include "stdafx.h"
#include <iostream>
#include "math.h"
#include <iomanip>

using namespace std;

double funf(double x,int fun);
double funderiv1f(double x,int fun);
double funderiv3f(double x,int fun);
double funderiv5f(double x,int fun);

int _tmain(int argc, _TCHAR* argv[])
{
	double sum=0,limita,limitb,I,ACC=1.0E-6,sol;
	int fun;
	//limita=1;limitb=2;sol=1.176769529767787;fun=1;
	//limita=0;limitb=1;sol=-0.199482985778898;fun=2; 
	limita=1;limitb=1.4;sol=0.462623521948113;fun=3;
	int steps=0;
	bool ContinueFlag=true;
	while(ContinueFlag){
		steps+=1;
		sum=0;
		double h=fabs((limitb-limita)/steps);
		sum+=funf(limita,fun);
		sum+=funf(limitb,fun);
		for(int i=1;i<steps;i++){
			sum+=2*funf(limita+i*h,fun);
		}
		I=(h*sum/2);
		I-=(pow(h,2)*(funderiv1f(limitb,fun)-funderiv1f(limita,fun))/12);
		I+=(pow(h,4)*(funderiv3f(limitb,fun)-funderiv3f(limita,fun))/720);
		I-=(pow(h,6)*(funderiv5f(limitb,fun)-funderiv5f(limita,fun))/3240);
		cout<<"Steps "<<steps<<" I="<<setprecision(15)<<I<<" relerror="<<fabs((I-sol)/sol)<<endl;
		if(fabs((I-sol)/sol)<ACC) ContinueFlag=false;
	}
	cout<<"Value I after "<<steps<<" steps is I="<<setprecision(15)<<I<<endl;
	return 0;
}

double funf(double x,int fun){
	double f;
	switch (fun) {		
		case 1:  
			return f=sqrt(x-0.1);
		case 2:
			return f=log10(x+0.2);
		case 3:
			return f=1/(x-0.32);
		default:
			cout<<"Not valid choice of funtion!!!"<<endl;
			return 0;
	}
}

double funderiv1f(double x,int fun){
	double df1;
	switch (fun) {		
		case 1:  
			return df1=1.0/(2.0*sqrt(-0.1+x));
		case 2:
			return df1=1.0/((0.2+x)*log(10.0));
		case 3:
			return df1=-(1.0/pow((-0.32+x),2));
		default:
			cout<<"Not valid choice of funtion!!!"<<endl;
			return 0;
	}
}

double funderiv3f(double x,int fun){
	double df3;
	switch (fun) {		
		case 1:  
			return df3=3.0/pow(8*(-0.1+x),2.5);
		case 2:
			return df3=2.0/(pow((0.2+x),3)*log(10.0));
		case 3:
			return df3=-(6.0/pow((-0.32+x),4));
		default:
			cout<<"Not valid choice of funtion!!!"<<endl;
			return 0;
	}
}

double funderiv5f(double x,int fun){
	double df5;
	switch (fun) {		
		case 1:  
			return df5=105.0/(32.0*pow((-0.1+x),4.5));
		case 2:
			return df5=24.0/(pow((0.2+x),5)*log(10.0));
		case 3:
			return df5=-(120.0/pow((-0.32+x),6));
		default:
			cout<<"Not valid choice of funtion!!!"<<endl;
			return 0;
	}
}
