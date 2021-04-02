#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "workshop_utilities.hpp"


int main(){

	int n = 5;
	std::vector<double> u(n);
	std::vector<std::vector<double>> v(n,std::vector<double> (n,0));

	//read matrix/vector file
	matrix_reader(v);
	

	//matrix testing
	std::vector<std::vector<double>> A(n,std::vector<double> (n,0));
	std::vector<std::vector<double>> B(n,std::vector<double> (n,0));
	std::vector<std::vector<double>> C(n,std::vector<double> (n,0));
	std::vector<double> a(n),b(n),c(n);
	matrices mat;
	mat.n = n;
	mat.a = a;
	mat.b = b;
	mat.c = c;
	mat.A = A;
	mat.B = B;
	mat.C = C;
	return 0;
}
