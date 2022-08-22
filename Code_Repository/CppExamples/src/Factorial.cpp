/*
 * Factorial.cpp
 *
 *  Created on: 6 Haz 2022
 *      Author: furkan.altay
 */


#include "iostream"


using namespace std;


unsigned long long factorial (unsigned long long n){
	if(n== 0)
		return 1;

	return n * factorial(n-1);
}


unsigned long long fibonacci (unsigned long long n){
	if(n <= 1)
		return n;

	return fibonacci(n-1) + fibonacci(n-2);
}

int main(){

	int fac_num=0;
	cout << "Enter number : ";
	cin >> fac_num;

//	cout << factorial(fac_num) << endl;
	cout << fibonacci(fac_num) << endl;

	return 0;
}

