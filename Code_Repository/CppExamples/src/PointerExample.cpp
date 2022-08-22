/*
 * PointerExample.cpp
 *
 *  Created on: 7 Haz 2022
 *      Author: furkan.altay
 */




#include "iostream"
#include "string"
#include "vector"

using namespace std;


int main(){

	int score{100};
	int *score_ptr{&score};

	cout << *score_ptr << endl;

	*score_ptr = 200;

	cout << *score_ptr << endl;
	cout << score << endl;

	cout << "\n-------------------------" << endl;

	double high_temp{100.7};
	double low_temp{37.4};

	double *temp_ptr{&high_temp};

	cout << *temp_ptr << endl;

	temp_ptr = &low_temp;


	cout << *temp_ptr << endl;

	cout << "\n-------------------------" << endl;

	string name{"Frank"};

	string *string_ptr{&name};

	cout << *string_ptr << endl;

	name = "James";

	cout << *string_ptr << endl;

	cout << "\n-------------------------" << endl;

	vector < string > stooges {"Larry", "Moe" , "Curly" };

	vector < string> *temp_stooges{nullptr};

	temp_stooges = &stooges;

	cout << "First stooge :" << (*temp_stooges).at(0) << endl;

	cout << "Stooges :";

//	for(auto stooge: *temp_stooges)
//		cout << stooge << " ";
//	cout << endl;

	for(size_t i=0;i < (*temp_stooges).size(); i++){
		cout << (*temp_stooges).at(i) << " ";
	}
	cout << endl;

	cout << "\n-------------------------" << endl;



	return 0;
}
