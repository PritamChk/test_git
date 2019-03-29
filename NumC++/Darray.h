namespace dyn_arr{
	class Array{
		double **a,*b;
		int n,m;
	public:
		Array(int);
		Array(int,int);
		double** get_2d();
		double* get_1d();
	};
	Array::Array(int n){
		b=new double[n];
	}
	Array::Array(int n,int m){
		a=new double*[n];
		for(int i=0;i<n;i++)
			a[i]=new double[m];
	}
	double** Array::get_2d(){
		return a;
	}
	double* Array::get_1d(){
		return b;
	}
}
namespace Darr=dyn_arr;
