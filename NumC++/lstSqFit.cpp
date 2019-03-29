#include<iostream>
#include"leastsq.h"
//#include"Darray.h"
using namespace std;
using namespace LSF;
//using namespace Darr;

int main(){
	int noe,d;
	cout<<"How Many points are there: ";
	cin>>noe;
	cout<<"What will be the degree of the polynomial: ";
	cin>>d;
	Array X(noe),Y(noe);
	double *x=X.get_1d(),*y=Y.get_1d();
	cout<<"Input The points:\n";
	for(int i=0;i<noe;i++){
		cout<<"x["<<(i+1)<<"]= ";
		cin>>x[i];
		cout<<"y["<<(i+1)<<"]= ";
		cin>>y[i];
	}
	LeastSqFit L(x,y,d,noe);
	double *a;
	L.fitCurve();
	//L.show_Dtls();
	a=L.get_coeff();
	cout<<"\nFitted curve is :->\n"; 
	for(int i=0;i<d+1;i++){
		if(a[i]>=0)
		cout<<"+("<<a[i]<<")x^"<<i;
		else
			cout<<a[i]<<"x^"<<i;
	}
	cout<<endl;
	return 0;
}

