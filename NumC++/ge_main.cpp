#include<iostream>
#include"ge.h"
#include<bits/stdc++.h>
using namespace std;
using namespace linEq;

int main(){
	int n;
	double **a,*b;
	cout<<"How Many Variables(n):";
	cin>>n;
	a=new double*[n];
	b=new double[n];
	for(int i=0;i<n;i++)
	{
		a[i]=new double[n];
	}
	cout<<"\nEnter Values for coefficient matrix and b[matrix]:->\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<"c["<<(i+1)<<"]["<<(j+1)<<"]=";
			cin>>a[i][j];
		}
		cout<<"b["<<(i+1)<<"]= ";
		cin>>b[i];
	}
	system("clear");
	Gauss_Eli G(a,b,n);
	G.solve();
	cout<<endl;
	G.showRoot();
	return 0;
}

