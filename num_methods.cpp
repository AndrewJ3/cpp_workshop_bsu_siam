#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h>
//#include "workshop_utilities.hpp"

//quadratic function x
void func_quad(std::vector<double>& x, std::vector<double>& f){
	int n = x.size();
	for(int i= 0; i< n; ++i){
		f[i] = x[i] * x[i];
	}
}

//derivative of quadratic function x^2
void dfunc_quad(std::vector<double>& x, std::vector<double>& df){
	int n = x.size();
	for(int i= 0; i< n; ++i){
		df[i] = 2 * x[i];
	}
}

//linear function x
void func_linear(std::vector<double>& x, std::vector<double>& f){
	int n = x.size();
	for(int i= 0; i< n; ++i){
		f[i] = x[i];
	}
}

//derivative of linear function x
void dfunc_linear(std::vector<double>& x, std::vector<double>& df){
	int n = x.size();
	for(int i= 0; i< n; ++i){
		df[i] = 1;
	}
}

//sqrt(x)
void func_sqrt(std::vector<double>& x, std::vector<double>& f){
	int n = x.size();
	for(int i= 0; i< n; ++i){
		f[i] = std::sqrt(x[i]);
	}
}

//derivative of sqrt(x)
void dfunc_sqrt(std::vector<double>& x, std::vector<double>& df){
	int n = x.size();
	for(int i= 0; i< n; ++i){
		df[i] = 0.5/(std::sqrt(x[i] + 2.3e-14));
	}
}

//sin(x)
void func_sin(std::vector<double>& x, std::vector<double>& f){
	int n = x.size();
	for(int i = 0; i < n; ++i){
		f[i] = std::sin(x[i]);
	}
}

//derivative of sin(x)
void dfunc_sin(std::vector<double>& x, std::vector<double>& df){
	int n = x.size();
	for(int i = 0; i < n; ++i){
		df[i] = std::cos(x[i]);
	}
}

int main(){

	int m = 3,n = 100;
	std::vector<double> u(n),df(n),df_exact(n),f(n),b(n),x(n);
	std::vector<std::vector<double>> A(n,std::vector<double> (n,0));
	double h = 2.0/(1.0*n - 1);
	for(int i = 0; i < n; ++i){
		x[i] = -1 + i*h;
//		std::cout << "x[i]  = " << x[i] << std::endl;
	}

	// 1d finite differences dudx \approx (2h)^{-1} * (u_{i-1} - u_{i+1}) + O(h^2)
	func_sin(x,f);

	for (int i = 1; i < n-1; ++i){
		df[i] = (1.0/(2.0*h))*(f[i+1] - f[i-1]);
	}

//	for (int i = 1; i < n-1; ++i){
//		std::cout << "dfdx fd approx. =  "<< df[i] <<std::endl;
//	}

	dfunc_sin(x,df_exact);
//	std::cout << "  " << std::endl;
//	for (int i = 1; i < n-1; ++i){
//		std::cout << "dfdx fd exact =  "<< df_exact[i] <<std::endl;
//	}
//	std::cout << "  " << std::endl;
	double err = 0 ,err_d = 0 ;
	for (int i = 1; i < n-1; ++i){
		err += std::fabs(df[i] - df_exact[i]) *  std::fabs(df[i] - df_exact[i]);
		err_d += std::sqrt(std::fabs(df_exact[i]));
		std::cout << "dfdx error =  "<< std::fabs(df[i] - df_exact[i]) <<std::endl;
	}

	err = std::sqrt(err);
	err_d = std::sqrt(err_d);

	std::cout<< "Relative Error:" << err/err_d <<std::endl;
// solve u'' = f, u = 0 on the boundary
//	for(int i = 0; i < m; ++i){
//	for(int j = 0; j < m; ++j){
//			if (i == j ){
//				A[i][j] = -2;
//			}
//			else if (i == j-1){
//				A[i][j] = 1;
//
//			}
//			else if (i == j+1){
//				A[i][j] = 1;
//			}
//		}
//	}
//	for(int i = 0; i < m; ++i){
//		b [i] = -1;
//	}

	
	return 0;
}
