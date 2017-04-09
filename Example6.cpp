// Example 6
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;




//Define a class
class Complex {

public :
Complex(){}; //default constructor

//void showComplex(); //define the showcomplex function
void getComplex(); //define the getcomplex function
Complex conjComplex();


Complex operator+(Complex); //define operator +
Complex operator-(Complex); //define operator -
Complex operator*(Complex); //define operator *
Complex operator++(); //define operator prefix 
Complex operator++(int); //define operator postfix
bool operator==(Complex); //define operator == typoy bool giati thelw na vgalei 1 i 0 (True False)
/*Complex addComplex(Complex); //define the addcoplex function with complex because return values
Complex multiComplex(Complex); //define the addcoplex function with complex because return values */


double normComplex(); //define the norm double because give number
friend ostream& operator<<(ostream& outstream, Complex& ); //Xreiazetai & gia anathesi giati alliws dn leitourgei
friend istream& operator>>(istream& instream, Complex& );  //Xreiazetai & gia anathesi giati alliws dn leitourgei

Complex (double x, double y){ //second Constructor
re=x;
im=y;
}


//private
private:
double re,im;
};

//show Complex function to show the values
/*void Complex :: showComplex() {
	char sign;
	sign=im<0?'-':'+';
	cout<<re<<sign<<fabs(im)<<"i"<<endl;
}*/

//getComplex function to get values 
/*void Complex :: getComplex() {
//	Complex a;
	cout<<"\nReal Part :"<<endl;
	cin>>re;
	cout<<"\nImaginary Part :"<<endl;
	cin>>im;
// return a;
}
*/
Complex Complex :: conjComplex()
{	double real,image;
	real=re;
	image=-im;
	return Complex(real,image);
}

/* //addComplex function to calculate the sum
Complex Complex :: addComplex(Complex y) {
	double real,image;
	real=re+y.re;
	image=im+y.im;
	Complex add(real,image);
	return add;
	
} */


//Operator Addition
Complex Complex::operator+(Complex b){

return Complex(re+b.re,im+b.im);
}

//Operator Substraction
Complex Complex::operator-(Complex b){

	return Complex(re-b.re,im-b.im);
}

//Operator Product
Complex Complex::operator*(Complex b){

	return Complex(re*b.re-im*b.im,re*b.im+im*b.re);
}

//Operator prefix
Complex Complex::operator++(){
	++re;
	++im;
	
	return Complex(re,im);
}


//Operator postfix
Complex Complex::operator++(int dummy){
	re++;
	im++;
	
	return Complex(re,im);
}

//Ostream cout
ostream& operator<<(ostream& outstream, Complex& b){
char sign;
sign=b.im<0?'-':'+';
outstream << b.re << sign << fabs(b.im) << "i" << endl;
return outstream;
}

//Ostream Cin
istream& operator>>(istream& instream, Complex& b){
	cout<<"\nReal Part :"<<endl;
	cin>>b.re;
	cout<<"\nImaginary Part :"<<endl;
	cin>>b.im;
return instream;
}

//Operator equality
bool Complex::operator==(Complex b)
{
return ((re==b.re) && (im==b.im));
}

//multiComplex function to calculate the multiplication 
/*Complex Complex :: multiComplex(Complex y)
{
double real,image;

real=re*y.re-im*y.im;
image=re*y.im+im*y.re;
Complex multi(real,image);

return multi;

}*/

//normComplex function to calculate the norm
double Complex :: normComplex() {

	double norm;
	norm=sqrt(pow(re,2.0)+pow(im,2.0));
	return norm;

}


int _tmain(int argc, char *argv[])
{
	//Complex c1,c2,c3,c5;
//	double e,f;

	bool test;
	Complex a,b,c,d,e,f,g; //define variables
	cin>>a; //get values for the variable a
	cin>>b; //get values for the variable b
	test=(a==b);

	cout<<"\nThe a is : \n"<<a<<endl;
	
	cout<<"\nThe b is : \n"<<b<<endl;

	cout<<"\n a=b?? : "<<test<<endl;

	c=a+b;
	cout<<"\nThe c is : \n"<<c<<endl;
	
	d=b-a;
	cout<<"\nThe d is : \n"<<d<<endl;
	
	e=a*b;
	cout<<"\nThe e is : \n"<<e<<endl;
	
	f=a++;
	cout<<"\nThe f is : \n"<<f<<endl;
	
	g=++a;
	cout<<"\nThe g is : \n"<<g<<endl;
	

	/*
	e=a.conjComplex();
	cout<<"\nThe conjugate of a is : "<<endl;
	e.showComplex();
	c=a.addComplex(b); //calculate the sum of the variables a and b
	cout<<"\nThe sum of a and b is : "; //Print the sum
	c.showComplex(); 
	d=a.multiComplex(b); //calculate the multiplication of the variables a and b
	cout<<"\nThe multiplication of a and b is : "; //Print the multiplication
	d.showComplex();
	cout<<"The norm of a is : "<<a.normComplex()<<endl; //Print the norm of tha variable a 
	cout<<"The norm of b is : "<<b.normComplex()<<endl; //Print the norm of tha variable b 
	cout<<"The norm of c is : "<<c.normComplex()<<endl; //Print the norm of tha variable c 
	cout<<"The norm of d is : "<<d.normComplex()<<endl; //Print the norm of tha variable d */


	system("pause");	
	return 0;
}
