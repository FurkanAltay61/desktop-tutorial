/*
 * StringExamples.c
 *
 *  Created on: 16 Eyl 2022
 *      Author: furkan.altay
 */


#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"
#include "string.h"

#define __NOP()                        __asm volatile ("nop")

#define TRUE  1
#define FALSE 0

#define FIG8_2_EX	FALSE	/* Pointer string mechanism */
#define FIG8_4_EX	FALSE	/*atof usage */
#define FIG8_9_EX	FALSE	/*strtod usage example*/
#define FIG8_13_EX	FALSE	/* recursive string function*/
#define FIG8_18_EX	FALSE	/*strcpy usage example*/
#define FIG8_19_EX	FALSE	/* strcat & strncat usage example*/
#define FIG8_21_EX	FALSE	/*strcmp & strncmp usage example*/
#define FIG8_23_EX	FALSE	/*strchr usage example*/
#define FIG8_24_EX	FALSE	/*strcspn usage example*/
#define FIG8_25_EX  FALSE	/*strpbrk usage example*/
#define FIG8_28_EX  TRUE	/*strstr usage example*/


#if (FIG8_13_EX == TRUE )
void ters(const char * const);

#endif


int main(){

#if (FIG8_2_EX == TRUE )
char renk[] = "mavi";			/*İlk bildirim 5 elemanlı renk dizisini yaratır.
							  	  Bu dizinin elemanları ‘m’,’a’,’v’,’i’ ve ’\0’ karakterleridir.*/

const char * renkPtr = "mavi";	/*İkinci bildirim, hafızada bir yerlerde bulunan “mavi” stringini
								  gösteren bir gösterici değişkeni olan renkPtr’yi yaratır. */
#endif

#if (FIG8_4_EX == TRUE )
	double d = 0;
	d = atof("99.77");

	int i = 0;
	i = atoi("2593");
__NOP();
#endif

#if (FIG8_9_EX == TRUE )

	double d;
	const char *string = "51.2% kabul edildi";
	char *stringPtr;

	d = strtod(string,&stringPtr);

	__NOP();
#endif

#if (FIG8_13_EX == TRUE )
	char cumle[25] = {"Merhaba Nasilsiniz"};
	ters(cumle);
#endif

#if (FIG8_18_EX == TRUE )
	char x[]="Dogum Gunun Kutlu Olsun";
	char y[25] = {0},z[15] = {0};
	strcpy(y,x);

	strncpy(z,x,11);
	z[11] = '\0';
	__NOP();
#endif

#if (FIG8_19_EX == TRUE )
	char s1[20] = "Mutlu ";
	char s2[] = "Yeni Yillar";
	char s3[40] = "";

	strcat(s1,s2); 			/*strcat fonksiyonu, ikinci argümanını (bir string) ilk argümanına (bir string içeren karakter
							dizisi) eklemektedir. İkinci argümanın ilk karakteri, ilk argümandaki stringin sonlandırıcı null
							karakterinin yerini alır.*/

	strncat(s3,s1,6);		/*strncat, ikinci stringten ilk stringe belli sayıdaki karakteri ekler. Sonlandırıcı null
							karakter sonuca otomatik olarak eklenir.*/

	__NOP();
#endif

#if (FIG8_21_EX == TRUE )

	/*strcmp fonksiyonu, ilk argümanının karakterlerini ikinci argümanını karakterleriyle teker
teker karşılaştırır. Fonksiyon eğer stringler eşitse 0 değerini, eğer ilk string ikinci stringten
küçükse negatif bir değeri, eğer ilk string ikinci stringten büyükse pozitif bir değeri döndürür.*/

	int8_t result = 0;
	const char *s1 = "Mutlu Yeni Yillar";
	const char *s2 = "Mutlu Yeni Yillar";
	const char *s3 = "Mutlu Tatiller";

	result = strcmp(s1,s2);
	result = strcmp(s1,s3);
	result = strcmp(s3,s1);

/*strncmp, strcmp’ye benzer ancak karşılaştırma yalnızca ilk stringteki n karakter için yapılır.
strncmp bir string içinde null karakterden sonra gelen karakterleri karşılaştırmaz. Program,
her fonksiyon çağrısından döndürülen tamsayı değerlerini yazdırmaktadır. */

	result = strncmp(s1,s3,6);
	result = strncmp(s1,s3,7);
	result = strncmp(s3,s1,7);

	__NOP();

#endif

#if (FIG8_23_EX == TRUE )
	const char *string = "Bu bir testtir";
	char character1 = 'u', character2 = 'z';
	char * result = 0;

/*strchr fonksiyonu, bir karakterin bir string içindeki ilk konumunu arar. Eğer karakter
bulunursa, strchr string içindeki karakteri gösteren bir gösterici döndürür. Aksi takdirde
strchr NULL döndürür*/

	result = strchr(string,character1);
	result = strchr(string,character2);
	__NOP();

#endif

#if (FIG8_24_EX == TRUE )

	/* NOTE : strcspn fonksiyonu (Şekil 8.24), ilk argümanı olan stringin içinde ikinci argümanı olan
	   stringin içindeki karakterlerden oluşmayan ilk kısmı bulur ve bu kısmın uzunluğunu
	   döndürür.
	*/
	const char *string1 = "Değe1 3.141593";
	const char *string2 = "1234567890";
	int8_t result = 0;

	result = strcspn(string1,string2);
	__NOP();
#endif

#if (FIG8_25_EX == TRUE )

	/*
	 * NOTE: strbrk fonksiyonu, ikinci argümanındaki stringte yer alan herhangi bir karakterin ilk
	   argümanındaki stringte ilk konumunu arar. Eğer ikinci argümandaki karakter bulunursa,
	   strbrk ilk argümandaki karakteri gösteren bir gösterici döndürür.Aksi takdirde, strbrk
	   fonksiyonu NULL döndürür.

	 */

	const char *string1 = "Bu bir testtir";
	const char *string2 = "dikkat";
	char *temp_str = 0;

	temp_str = strpbrk(string1,string2);
#endif


#if (FIG8_28_EX == TRUE )

	/*
	 * NOTE: strstr fonksiyonu, ikinci string argümanının, ilk string argümanında bulunduğu ilk konumu
	   arar. Eğer ikinci string ilk string içinde bulunursa, ilk argüman içindeki stringi gösteren bir
       gösterici döndürülür.

	 */

	const char *string1 = "abcdefgrhs";
	const char *string2 = "gr";

	char *temp_str = 0;

	temp_str = strstr(string1,string2);

	/*
	 * NOTE: strtok fonksiyonu, bir stringi atomlarına ayırmak için kullanılır.
	 * Atom, boşluk ya da noktalama karakterleri gibi sınırlayıcı bazı
	 *  karakterlere kadar olan karakter serileridir.
	 */

    char dataStr[] = "123:abc:657:jhg:klm";
	char  *atomPTr = 0, *tempPtr = 0;

	do{
		atomPTr = strtok(dataStr,":");
		__NOP();
	}while(atomPTr == NULL);

//	atomPTr = strtok(dataStr,":");
//
//	while(atomPTr != NULL){
//		tempPtr = atomPTr;
//		atomPTr = strtok(NULL,":");
//		__NOP();
//	}



#endif

	while(1);


	return 0;

}


#if (FIG8_13_EX == TRUE )
void ters(const char * const sPtr){
	static char Newstr[25] = {0};
	static uint8_t cntr = 0;

	if(sPtr[0] == '\0'){
		cntr = 0;
		return;
	}
	else{
		ters(&sPtr[1]);
		Newstr[] = sPtr[0];
		cntr++;
	}

	__NOP();
}
#endif


#if (FIG8_25_EX == TRUE )

#endif
