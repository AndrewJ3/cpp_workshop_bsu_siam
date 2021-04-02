#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>


int main(){

	std::ifstream data_file;
	data_file.open("a.mat");
	data_file.open("b.mat");
	int m,n;
	data_file >> m >> n;
	std::vector<std::vector<double>> v(m,std::vector<double> (n,0));

	//Read file contents
	for(int i = 0; i < m; ++i){
		if (n != 0){
			for(int j = 0; j < n; ++j){
				data_file >> v[i][j];
			}
		}
		else{
				data_file >> v[i][0];
		}
	}

	//print file contents
	for(int i = 0; i < m; ++i){
		if( n != 0 ){
			for(int j = 0; j < n; ++j){
				std::cout << v[i][j] << " ";
			}
		}
		else{
				std::cout << v[i][0] << " ";
		}

		std::cout << "" <<std::endl;
	}


}
