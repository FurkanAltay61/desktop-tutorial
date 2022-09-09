/*
 * BubbleSort.c
 *
 *  Created on: 9 Eyl 2022
 *      Author: furkan.altay
 */


#include <stdio.h>

#define LENGTH	10

/*Karşılaştırmaların yapılma yöntemi yüzünden büyük bir değer tek bir turda
  dizide aşağıya doğru bir çok pozisyon ilerleyebilirken, küçük bir değer
  yukarıya doğru yalnızca tek bir pozisyon ilerleyebilir.
  İlk turda, en büyük değerin dizinin en alttaki elemanı olan a[9]’a gitmesi
  garanti altına alınmıştır. İkinci turda, ikinci en büyük değerin a[8]’e gideceği garantidir.
  Dokuzuncu turda, dokuzuncu en büyük değerin a[1]’e gitmesi garantidir.
  Bu, en küçük değeri a[0]’da bırakır, böylece dizinin 10 elemanı olmasına rağmen
  diziyi sıralamak için yalnızca 9 geçiş gereklidir. */

int main(){
	int a[LENGTH] = {2 , 20 , 56 , 32 , 87 , 23 , 15 , 3 , 7 , 10 };
	int i,round,hold;

	for(round = 1 ; round <= LENGTH-1 ; round++){
		for(i=0;i <= LENGTH - 2 ; i++){
			if(a[i] > a[i+1]){
				hold = a[i];
				a[i] = a[i+1];
				a[i+1] = hold;
			}
		}
	}
}
