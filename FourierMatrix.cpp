#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
const double PI = 4 * atanf(1.0);

struct cplx{
	double rp,ip;
};

class FM{
public:
	FM(int);
	void conj();
	void print();
	void printconj();

private:
	int order;
	cplx *fmat, *fmatc;
};
//Class implementation
FM::FM(int n){
	order=n;
	fmat=new cplx[n*n]; // 1D array of n*n cplx #s
	int k,m;
	for(k=0; k<order; k++)
		for(m=0; m<order; m++){
			fmat[k*order+m].rp=cos(2*PI*k*m/n);
			fmat[k*order+m].ip=sin(2*PI*k*m/n);
		}
}
void FM::print(){
int k, m;
	for(k=0; k<order; k++){
		for(m=0; m<order; m++){
			cout<<"(";
			cout<<setprecision(2)<<fixed<<fmat[k*order+m].rp;
			cout<<",";
			cout<<setprecision(2)<<fixed<<fmat[k*order+m].ip;
			cout<<")"<<" ";
		}
		cout<<endl;
	}
}
void FM::conj(){
int k,m;
	fmatc=new cplx[order*order]; 
	for(k=0; k<order; k++)
		for(m=0; m<order; m++){
			fmatc[k*order+m].rp=fmat[k*order+m].rp;
			fmatc[k*order+m].ip=-fmat[k*order+m].ip;
		}
}
void FM::printconj(){
int k, m;
	for(k=0; k<order; k++){
		for(m=0; m<order; m++){
			cout<<"(";
			cout<<setprecision(2)<<fixed<<fmatc[k*order+m].rp;
			cout<<",";
			cout<<setprecision(2)<<fixed<<fmatc[k*order+m].ip;
			cout<<")"<<" ";
		}
		cout<<endl;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	FM f(2),g(4),*fptr;
	f.print();
	cout<<"\n\n";
	g.print();
	fptr=&f;
	cout<<"\n\n";
	fptr->print();
	fptr->conj();
	fptr->printconj();
	return 0;
}








function [FM] = GenFMat(n)
W=exp(j*2*pi/n);
for k=1:n
   for l=1:n
       kk=k-1;
       ll=l-1;
       FM(k,l)=W^(kk*ll);
   end
end


