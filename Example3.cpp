// Example 3
//
#include "stdafx.h"
#include <iostream>
#include "math.h"

using namespace std;

class VEC{
	private:
		double x,y,z;
	public:
		VEC(double a=0,double b=0,double c=0) {x=a;y=b;z=c;}
		void set(double a,double b,double c) {x=a;y=b;z=c;}
		double norm();
		double dotproduct(VEC);
		VEC crossproduct(VEC);
		VEC scale(double a);
		void show();
};

double VEC::norm(){
	return sqrt(x*x+y*y+z*z);
}

double VEC::dotproduct(VEC dot){
	return x*dot.x+y*dot.y+z*dot.z;
}

VEC VEC::crossproduct(VEC cross){
	VEC temp;
	temp.x=y*cross.z-z*cross.y;
	temp.y=z*cross.x-x*cross.z;
	temp.z=x*cross.y-y*cross.x;
	return temp;
}

VEC VEC::scale(double a){
	return VEC(a*x,a*y,a*z);
}

void VEC::show(){
	cout<<"("<<x<<","<<y<<","<<z<<")";
	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
	VEC a(0,0,1),b,c;
	b.set(0,1,0);
	double d;
	d=a.dotproduct(b);
	c=a.crossproduct(b);
	cout<<"first vector : ";a.show();
	cout<<"\nsecond vector : ";b.show();
	cout<<"\ndot product : "<<d;
	cout<<"\ncross product : ";c.show();cout<<endl;
	c=a.scale(3);
	cout<<"first vector scaled : ";c.show();
	cout<<endl;
	return 0;
}

