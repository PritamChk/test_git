#include<iostream>
#include<bits/stdc++.h>
//#define Max 100

using namespace std;

namespace LinSimEq{
class Gauss_Eli{
	double **a,*b,*x;
	int n;
public:
	Gauss_Eli(){}
	Gauss_Eli(double **,double *,int n);
	void solve();
	double *getRoot();
	void showRoot();
};

Gauss_Eli::Gauss_Eli(double **c,double *b1,int n){
	a=new double*[n];
	x=new double[n];
	b=new double[n];
	for(int i=0;i<n;i++){
		a[i]=new double[n];
	}	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			a[i][j]=c[i][j];
		b[i]=b1[i];
	}
	Gauss_Eli::n=n;
}

void Gauss_Eli::solve(){
	int i=0,j=0,k=0;
	double m=0,s=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		//	cout<<a[i][j]<<"\t";
			if(i!=j){
				m=a[j][i]/a[i][i];
				for(k=0;k<n;k++)
					a[j][k]=a[j][k]-m*a[i][k];
				b[j]=b[j]-b[i]*m;
			}
			//cout<<endl;
		}
	}
	//to show intermediate steps
	//end
	x[n-1]=b[n-1]/a[n-1][n-1];
	for(i=n-2;i>=0;i--){
		s=0;
		for(j=i+1;j<n;j++){
			s+=a[i][j]*x[j];
		}
		x[i]=(b[i]-s)/a[i][i];
	}
}
double *Gauss_Eli::getRoot(){
	return x;
}
void Gauss_Eli::showRoot(){
	cout<<"Roots are :->\n";
	for(int i=0;i<n;i++){
		cout<<"x["<<(i+1)<<"]= "<<x[i]<<endl;
	}
}
}
namespace linEq=LinSimEq;
