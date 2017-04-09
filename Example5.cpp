// Example 5
//

#include "stdafx.h"
#include "math.h"
#include <iostream>
#include <iomanip>

using namespace std;

struct  Complex{
	double re;
	double im;
};

Complex getComplex();
void printComplex(Complex com);
Complex addComplex(Complex x,Complex y);
Complex multComplex(Complex x,Complex y);
double normComplex(Complex x);
Complex findInverseComplex(Complex x);
Complex CreateComplex(double a,double b);
void CropComplex(Complex &x);

int main(int argc, char *argv[])
{
	Complex a,b,c,d,inva,invb,test,div;
	cout<<"------ Complex a -------"<<endl;
	a=getComplex();
	cout<<"------ Complex b -------"<<endl;
	b=getComplex();
	cout<<"a=";printComplex(a);cout<<"  |a|="<<normComplex(a)<<endl;
	cout<<"b=";printComplex(b);cout<<"  |b|="<<normComplex(b)<<endl;
	c=addComplex(a,b);
	cout<<"To athroisma twn a kai b einai : ";printComplex(c);cout<<endl;
	d=multComplex(a,b);
	cout<<"To ginomeno twn a kai b einai : ";printComplex(d);cout<<endl;
	inva=findInverseComplex(a);
	invb=findInverseComplex(b);
	cout<<"O antistrofos tou a einai :";printComplex(inva);cout<<endl;
	cout<<"O antistrofos tou b einai :";printComplex(invb);cout<<endl;
	test=multComplex(a,inva);
	CropComplex(test);
	cout<<"a * inva = ";printComplex(test);cout<<endl;
	test=multComplex(b,invb);
	CropComplex(test);
	cout<<"b * invb =  ";printComplex(test);cout<<endl;
	div=multComplex(a,findInverseComplex(b));
	cout<<"To a/b einai : ";printComplex(div);cout<<endl;
	Complex pi=CreateComplex(3.14,-3.14);
	cout<<"pi=";printComplex(pi);cout<<endl;
	return 0;
}

Complex getComplex(){
	Complex com;
	cout<<"Give the real part of the complex number: ";
	cin>>com.re;
	cout<<"Give the imaginary part of the complex number: ";
	cin>>com.im;
	return com;
}

void printComplex(Complex com){
	char sign;
	sign=com.im<0?'-':'+';
	cout<<com.re<<sign<<fabs(com.im)<<'j';
	return;
}

Complex addComplex(Complex x,Complex y){
	Complex add;
	add.re=x.re+y.re;
	add.im=x.im+y.im;
	return add;
}

Complex multComplex(Complex x,Complex y){
	Complex mult;
	mult.re=x.re*y.re-x.im*y.im;
	mult.im=x.re*y.im+x.im*y.re;
	return mult;
};

double normComplex(Complex x){
	double norm=sqrt(x.re*x.re+x.im*x.im);
	return norm;
}

Complex findInverseComplex(Complex x){
	Complex inv;
	double norm=normComplex(x);
	inv.re=x.re/(norm*norm);
	inv.im=-x.im/(norm*norm);
	return inv;
}

Complex CreateComplex(double a,double b){
	Complex x;
	x.re=a;
	x.im=b;
	return x;
}
void CropComplex(Complex &x){
	double ACC=1.0E-16;
	if(fabs(x.im)<ACC) x.im=0;
	return;
}
