// Example 2
//
#include "stdafx.h"
#include <iostream>
#include "math.h"

using namespace std;

class myComplex{
		double re,im;
	public:
		myComplex(double a=0,double b=0) {re=a;im=b;}
		myComplex operator+(myComplex);
		myComplex operator-(myComplex);
		myComplex operator*(myComplex);
		myComplex operator/(myComplex);
		myComplex operator++(void);
		myComplex operator++(int);
		myComplex operator--(void);
		myComplex operator--(int);
		void operator =(myComplex&);
		void operator =(double a);
		bool operator==(myComplex);
		double norm();
		void set_complex(double a,double b) {re=a;im=b;}
		double get_re() {return re;}
		double get_im() {return im;}
		friend ostream& operator<<(ostream& mystream, myComplex& com);
		friend istream& operator>>(istream& mystream, myComplex& com);
};

myComplex myComplex::operator +(myComplex com){
	myComplex temp;
	temp.re=re+com.re;
	temp.im=im+com.im;
	return temp;	
}

myComplex myComplex::operator -(myComplex com){
	myComplex temp;
	temp.re=re-com.re;
	temp.im=im-com.im;
	return temp;
}

myComplex myComplex::operator *(myComplex com){
	myComplex temp;
	temp.re=re*com.re-im*com.im;
	temp.im=re*com.im+im*com.re;
	return temp;
}

myComplex myComplex::operator /(myComplex com){
	myComplex temp;
	double n=com.norm();
	temp.re=(re*com.re+im*com.im)/(n*n);
	temp.im=(im*com.re-re*com.im)/(n*n);
	return temp;
}

double myComplex::norm(){
	return sqrt(re*re+im*im);
}

myComplex myComplex::operator ++(void){
	myComplex temp;
	temp.re=++re;
	temp.im=++im;
	return temp;	
}

myComplex myComplex::operator ++(int dummy){
	myComplex temp(re,im);
	re++;
	im++;
	return temp;
}

myComplex myComplex::operator --(void){
	myComplex temp;
	temp.re=--re;
	temp.im=--im;
	return temp;	
}

myComplex myComplex::operator --(int dummy){
	myComplex temp(re,im);
	re--;
	im--;
	return temp;
}


void myComplex::operator =(myComplex& com){
		re=com.get_re();
		im=com.get_im();
}

void myComplex::operator =(double a){
		re=a;
		im=0.0;
}

ostream& operator<<(ostream& mystream, myComplex& com){
	char sign=com.get_im()>=0?'+':'-';
	mystream<<com.get_re()<<sign<<fabs(com.get_im())<<"j";
	return mystream;
}

istream& operator>>(istream& mystream, myComplex& com){
	cout<<"Enter real part : ";
	mystream>>com.re;
	cout<<"Enter imaginary part : ";
	mystream>>com.im;
	return mystream;
}

bool myComplex::operator==(myComplex com){
	return (re==com.re && im==com.im);
}

int _tmain(int argc, _TCHAR* argv[])
{	
	myComplex a(1,2),b(2,3),c,d;
	cout<<"myComplex Class Demonstration"<<endl;
	cout<<"a="<<a<<" b="<<b<<endl;
	cout<<"Overloading +,-,*,/"<<endl;
	c=a+b;
	cout<<"a+b="<<c<<endl;
	c=a-b;
	cout<<"a-b="<<c<<endl;
	c=a*b;
	cout<<"a*b="<<c<<endl;
	c=a/b;
	cout<<"a/b="<<c<<endl;
	cout<<"Overloading ++,-- pre and post prefix style"<<endl;
	cout<<"++a="<<++a<<" a="<<a<<endl;
	cout<<"--a="<<--a<<" a="<<a<<endl;
	cout<<"a++="<<a++<<" a="<<a<<endl;
	cout<<"a--="<<a--<<" a="<<a<<endl;
	cout<<"Overloading logical operator =="<<endl;
	if(a==b) cout<<"a=b TRUE"<<endl;
	else cout<<"a=b FALSE"<<endl;
	a=b;
	if(a==b) cout<<"a=b TRUE"<<endl;
	else cout<<"a=b FALSE"<<endl;
	cout<<"Overloading >> operator "<<endl;
	cin>>d;
	cout<<"d="<<d;
	cout<<endl;
	cout<<"a=1.0 : "<<a<<endl;
	c=(myComplex)10.0*d;
	cout<<"10*d="<<c<<endl;
	return 0;
}

