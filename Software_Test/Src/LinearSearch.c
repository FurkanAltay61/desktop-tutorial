/*
 * LinearSearch.c
 *
 *  Created on: 9 Eyl 2022
 *      Author: furkan.altay
 */


#include <stdio.h>

#define LENGTH	100

int LinearSearch(const int [],int,int , int *);


/*İkili arama tekniği, her karşılaştırmadan sonra sıralanmış bir dizideki elemanların yarısını
elemektedir. Algoritma, dizinin ortadaki elemanını bulmakta ve bu elemanın değerini arama
değeriyle karşılaştırmaktadır. Eğer ikisi eşitse, arama değeri bulunmuştur ve o elemanın dizi
belirteci geri döndürülür. Eğer bu iki değer eşit değilse, problem dizinin yarısını aramaya
indirgenmiştir. Eğer arama değeri dizinin ortadaki elemanından daha küçükse, dizinin ilk
yarısı aranır. Aksi takdirde ise dizinin ikinci yarısı aranır. Eğer arama değeri belirlenen alt
dizide de (orijinal dizinin bir parçası) bulunamazsa, algoritma orijinal dizinin dörtte birinde
tekrarlanır. Arama, alt dizilerden birinin ortadaki elemanıyla arama değeri eşit olunca ya da
alt dizi arama değerine eşit olmayan tek bir elemana sahip oluncaya dek (yani arama değeri
bulunamayıncaya dek) devam eder.*/

int BinarySearch(const int [] , int , int , int, int *);

int main(){

	int a[LENGTH]={0} , keyValue = 0 , member = 0 ,result = 0 , iteration_num = 0;

	for(uint8_t n=0; n <= LENGTH -1;n++){
		a[n] = 2 * n;
	}

	keyValue = 50;

	member = LinearSearch(a,keyValue,LENGTH , &iteration_num);
	iteration_num = 0;
	member = BinarySearch(a,keyValue,0,LENGTH-1, &iteration_num);

	if(member != -1){
		result = 1;
	}
	else{
		result = 0;
	}

	while(1);
}


int LinearSearch(const int arr[],int key,int length ,int *itnum){

	for(uint8_t n = 0; n <= length - 1; ++n){
		(*itnum)++;

		if(arr[n] == key)
			return n;
	}

	return -1;
}

int BinarySearch(const int b[] , int keyValue , int min , int max , int *itnum){

	int middle = 0,result = -1;

	while(min <= max){

		(*itnum)++;

		middle  = (min + max) / 2;

		if(keyValue == b[middle]){
			result = b[middle];
			break;
		}
		else if(keyValue < b[middle]){
			max = middle -1;
		}
		else{
			min = middle + 1;
		}

	}

	return result;
}



