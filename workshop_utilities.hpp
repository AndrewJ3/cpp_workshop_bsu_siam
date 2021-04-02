#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>


/*c++ basics*/
void variable_declaration(){

	// variables, data types
	int i_a,i_b,i_c;
	double d_a,d_b,d_c;
	float f_a,f_b,f_c;

}

void data_structures(){

	int n = 10;
	//static C++ arrays 
	int i_a_static[n];
	double d_a_static[n];
	float f_a_static[n];

	//dynamic C++ arrays 
	int *i_a_dyn;
	double *d_a_dyn;
	float *f_a_dyn;
	i_a_dyn = new int[n];
	d_a_dyn = new double[n];
	f_a_dyn = new float[n];

	//STL Containers
	std::vector<int> i_a_vec;
	std::vector<double> d_a_vec;
	std::vector<float> f_a_vec;
}

//for and while loops
void loops(){

	//perform summation of integers in range 0 - 9
	int n = 10;
	int sum = 0;
	for(int i = 0; i < n; ++i){
		std::cout << "for: the sum is = " << sum;
		sum += 1;
	}

	sum = 0;
	while(sum < n){
		std::cout << "while: the sum is = " << sum;
		sum += 1;
	}

}

// if/ else if / else
double conditionals(){

	// check if numbers between 0 - 9 are even or odd
	int var = 0;
	for(int i = 0; i < 20; ++i){
		var = i;
		if (var % 2 == 0){
			std::cout << "even: " << var << std::endl;
		}
		else{
			std::cout << "odd: " << var << std::endl;
		}
	}
}

//read in matrix file
void matrix_reader(){

	std::ifstream data_file;
	data_file.open("a.mat");
	int m,n;
	data_file >> m >> n;
	std::vector<std::vector<double>> v(m,std::vector<double> (n,0));

	//Read file contents
	for(int i < 0; i < m; ++i){
		if (n != 0){
			for(int i < 0; i < n; ++i){
				data_file >> v[i][j];
			}
		}
		else{
				data_file >> v[i][0];
		}
	}
}

//file writer
void file_writer(std::vector<double> v, int n){

	//read file
	std::ofstream data_file;
	data_file.open("output.dat");
	for(int i = 0; i < n; ++i){
		data_file << v(i) << " ";
	}
	data_file.close();

}

/*numerical linear algebra*/
struct matrices {
	int n,maxiter;
	std::vector<std::vector<double>> A,B,C;
	std::vector<double> a,b,c,Ax;
	double alp, beta, ab, sum_j,sum_i,norm_a, tol;

	void matrix_reader();
	void gaussian_elimination();
	void gemv();
	void axpy();
	void dot();
	void sum();
	void gemm();
	
};


//read in matrix file
void matrices::matrix_reader(){

	std::ifstream data_file;
	data_file.open("a.mat");
	int m,n;
	data_file >> m >> n;
	std::vector<std::vector<double>> v(m,std::vector<double> (n,0));
	//Read file contents
	for(int i < 0; i < m; ++i){
		if (n != 0){
			for(int i < 0; i < n; ++i){
				data_file >> v[i][j];
			}
		}
		else{
				data_file >> v[i][0];
		}
	}
}

// Solve linear linear system via gaussian elimination
void matrices::gaussian_elimination(){

	for(int i = 0; i < n; ++i){
		if ( a[i][i] == 0 ) {
			std::cout << "Singular" << std::endl;
			break;
		}
		for(int j = i+1; j < n; ++j){
			alp = a[j][i]/a[i][i];
			for(int k = 0; k < n+1; ++k){
				a[j][k] -= alp * a[i][k];
			}
		}
	}

}


void::matrices::solve(){
	//solve via jacobi (converges for diagonally dominant matrices)
	double tmp = 0;
	double nrmrk = 1;
	double nrmfk = 0;	
	for(int k = 0; k < maxiter; ++k){
		for(int i = 0; i < n; ++i){
			tmp = 0;
			for(int j = 0; j < n; ++j){
				if(j == i){
					tmp += A[i][j]*u[j];
				}
			}
			x[i] = (1/A[i][i])*(b[i] - tmp);
		}
		matvec();
		for (int i = 0; i < n; ++){
			nrmrk += (Ax[i] - b[i]) * (Ax[i] - b[i]);
		}
		for (int i = 0; i < n; ++){
			nrmfk += b[i] * b[i];
		}
		if (nrmrk < tol){
			std::cout << nrmrk
			break;

		}
	}



}

//a = alp * b + a
void matrices::axpy(){

	// a += alp*b
	for(int i = 0; i < n; ++i){
		a[i] += alp*b[i];
	}
}

//perform a dot product of a matrix and vector
void matrices::dot(){
	
	for(int i = 0; i < n; ++i){
		ab += a[i] * b[i];
	}

}

//sum elements of a vector
void matrices::sum(){
	sum_i = 0;
	for(int i = 0; i < n; ++i){
		sum_i += a[i];
	}
}

//compu	te the norm or lenght of a vector
void matrices::norm(){
	sum_i = 0;
	for(int i = 0; i < n; ++i){
		sum_i += std::abs(a[i]*a[i]);
	}
	norm_a = std::sqrt(sum_i);
}

//matrix vector product
void matrices::gemv(){
		//  b = Ax
		for(int j = 0; j < n; ++j){
			sum_j = 0;
			for(int k = 0; k < n; ++k){
				sum_j += A[j][k] * x[k];
			}
			Ax[j] = sum_j;
		}
}

// matrix-matrix product
void matrices::gemm(){

	// C = AB
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < n; ++k){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}


/*numerical methods*/
struct numerical_methods{
	std::vector <std::vector<double>> A;
	std::vector <double> b;
	std::vector <double> u;
	




};



