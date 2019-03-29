#include"ge.h"
#include<cmath>
#include"Darray.h"
#include<iostream>
using namespace std;
using namespace linEq;
using namespace Darr;

namespace lstSqFit{
	class LeastSqFit{
		double **xi,*yx,*a;
		double *x,*y;
		int deg,points;
		double sumXi(int);
		double sumYX(int);
	public:
		LeastSqFit(){}
		LeastSqFit(double *,double *,int,int);
		void fitCurve();
		void show_Dtls();
		double *get_coeff();
	};
	LeastSqFit::LeastSqFit(double *x1,double *y1,int d,int nop){
		Array X(nop),Y(nop);
		x=X.get_1d();
		y=Y.get_1d();
		x=x1;
		y=y1;
		deg=d;
		deg=deg+1;
		points=nop;
		Array Xi(deg,deg),YX(deg),A(deg);
		xi=Xi.get_2d();
		yx=YX.get_1d();
		a=A.get_1d();
	}
	double LeastSqFit::sumXi(int p){
		int i=0;
		double s=0;
		for(i=0;i<points;i++)
			s+=pow(x[i],p);
		return s;
	}
	double LeastSqFit::sumYX(int p){
		double s=0;
		int i=0;
		for(i=0;i<points;i++)
			s+=y[i]*pow(x[i],p);
		return s;
	}
	void LeastSqFit::fitCurve(){
		int i,j;
		//xi[0][0]=deg;
		for(i=0;i<deg;i++)
		{
			for(j=0;j<deg;j++){
				//if(i==0&&j==0)
				//	continue;
				xi[i][j]=sumXi(i+j);
			}
			yx[i]=sumYX(i);
		}
		Gauss_Eli G(xi,yx,deg);
		G.solve();
		a=G.getRoot();
	}
	double *LeastSqFit::get_coeff(){
		return a;
	}
	void LeastSqFit::show_Dtls()
	{
		int i,j;
		cout<<"In LSF : \n";
		cout<<"\ndeg:"<<deg<<"\t points: "<<points;
		cout<<"\nAll points:->\nx:\ty:\n---\t---\n";
		for(i=0;i<points;i++){
			cout<<x[i]<<"\t"<<y[i]<<endl;
		}
		cout<<"\nsumXi[]:\n";
		for(i=0;i<deg;i++){
			for(j=0;j<deg;j++)
				cout<<xi[i][j]<<"\t";
			cout<<"\n";
		}
		cout<<"\nsumYX[]:->:\n";
		for(i=0;i<deg;i++){
			cout<<yx[i]<<endl;
		}
	}
}
namespace LSF=lstSqFit;
