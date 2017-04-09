// Example 4
//
#include "stdafx.h"
#include <iostream>
#include "time.h"

using namespace std;

struct Point{
	double x;
	double y;
	double z;
};

struct Sphere{
	Point center;
	double radius;
};

struct Grid{
	Point *ptogrid;
	int sizex;
	int sizey;
	int sizez;
};

Point SetPoint(double a,double b,double c);
void ViewPoint(Point p);

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(0));
	Grid EleNaCl;
	cout<<"Give the NaCl lattice dimensions sizex,sizey,sizez : ";
	cin>>EleNaCl.sizex>>EleNaCl.sizey>>EleNaCl.sizez;
	int npoints=EleNaCl.sizex*EleNaCl.sizey*EleNaCl.sizez;
	EleNaCl.ptogrid=new Point [npoints];
	for(int i=0;i<npoints;i++){
		EleNaCl.ptogrid[i]=SetPoint(rand()%2,rand()%2,rand()%2);
	}
	cout<<"--------- Random Grid (0 or 1) ---------"<<endl;
	for(int i=0;i<npoints;i++){
		cout<<"Shmeio "<<i+1<<" ";ViewPoint(EleNaCl.ptogrid[i]);cout<<endl;
	}
	int m=0;
	for(int i=0;i<EleNaCl.sizex;i++){
		for(int j=0;j<EleNaCl.sizey;j++){
			for(int k=0;k<EleNaCl.sizez;k++){
				EleNaCl.ptogrid[m]=SetPoint(i,j,k);
				m++;				
			}
		}
	}
	cout<<"--------- Indexed Grid ---------"<<endl;
	for(int i=0;i<npoints;i++){
		cout<<"Shmeio "<<i+1<<" ";ViewPoint(EleNaCl.ptogrid[i]);cout<<endl;
	}
	delete [] EleNaCl.ptogrid;
	return 0;
}

Point SetPoint(double x,double y,double z){
	Point temp;
	temp.x=x;
	temp.y=y;
	temp.z=z;
	return temp;	
}

void ViewPoint(Point p){
	cout<<"("<<p.x<<","<<p.y<<","<<p.z<<")";
	return;
}

