/*
 * arrayexample.cpp
 *
 *  Created on: 7 Haz 2022
 *      Author: furkan.altay
 */

#include "iostream"

using namespace std;


void print(int arr[],int num){

	cout << "[" ;

	for(int cntr; cntr < num ; cntr++){
		cout <<  arr[cntr] << " ";
	}

	cout << "]" ;

	cout << endl;
}

int *apply_all(int arr1[],int size1,int arr2[],int size2){
	int *arr_tot = new int[size1 * size2];


	for(int i=0;i<size1;i++){
		for(int j=0;j<size2;j++){
			for(int k=0;k<size1 * size2;i++){
				arr_tot[k] = arr1[i] * arr2[j];
			}
		}
	}

	return arr_tot;
}


int main(){

	int array1[] {1,2,3,4,5};
	int array2[] {10,20,30};

	int *tot_arr{nullptr};

	cout << "Array 1:";
	//print Array1;
	print(array1,5);

	cout << "Array 2:";
	//print Array2;
	print(array2,3);

	tot_arr	= apply_all(array1, 5,array2, 3);
	print(tot_arr,15);

	return 0;
}



