/*
 * ClassExerciseAnswers.cpp
 *
 *  Created on: 28 Eyl 2022
 *      Author: furkan.altay
 */



#define FIG3_1 false
#define FIG3_2 false
#define FIG3_3 false
#define FIG3_6 false
#define FIG3_7 false
#define FIG3_9 false
#define FIG3_10 false


#if(FIG3_1 == true)

/*    a)Every class definition contains the keyword ........ followed immediately by the
	  class’s name
  	  a)Ans - class

  	  b) A class definition is typically stored in a file with the ..... filename extension.
  	  b)Ans - .h

  	  c)Each parameter in a function header specifies both a(n) ...  and a(n) . ....
  	  c)Ans - type , name

  	  d) When each object of a class maintains its own copy of an attribute,
  	     the variable that represents the attribute is also known as a(n) ......
  	  d)Ans - data member

  	  e) Keyword public is a(n) ......
	  e)Ans - access specifier

  	  f) Return type ..... indicates that a function will perform a task but will not return
  	  any information when it completes its task.
	  f)Ans - void

  	  g) Function ..... from the <string> library reads characters until a newline character
  	  is encountered, then copies those characters into the specified string.
	  g)Ans - getline

  	  h) When a member function is defined outside the class definition, the function header
  	  must include the class name and the .... , followed by the function name to “tie” the
  	  member function to the class definition.
	  h) Ans - binary scope resolution operator(::)

  	  i) The source-code file and any other files that use a class can include the class’s header via
  	  a(n) ..... preprocessor directive.
  	  i) Ans - #include
  */

#endif

#if(FIG3_2 == true)

/*
 * State whether each of the following is true or false. If false, explain why.
  a) By convention, function names begin with a capital letter and all subsequent words in
  the name begin with a capital letter.
  Ans-a)False +

  b) Empty parentheses following a function name in a function prototype indicate that the
  function does not require any parameters to perform its task.
  Ans-b)True +

  c) Data members or member functions declared with access specifier private are accessible to
  member functions of the class in which they’re declared.
  Ans-c)True +

  d) Variables declared in the body of a particular member function are known as data members
  and can be used in all member functions of the class.
  Ans-d)False , it doesnt have to be data member , it could be local variables that could be used by functions.

  e) Every function’s body is delimited by left and right braces ({ and }).
  Ans-e)True +

  f) Any source-code file that contains int main() can be used to execute a program.
  Ans-f)True +

  g) The types of arguments in a function call must be consistent with the types of the corresponding
  parameters in the function prototype’s parameter list.
  Ans -g)True +

 */
#endif


#if(FIG3_3 == true)
/*
 * What is the difference between a local variable and a data member?
 * Ans) Local variable is defined in the body of the member function , but
 * data member is defined in the class. local variable is only accessible by function its defined
 * but data member is accessible by all its class member elements.
 */

#endif

#if(FIG3_6 == true)
/*
 * What’s a default constructor? How are an object’s data members initialized if
 * a class has only an implicitly defined default constructor?
 *
 * C++ provides constructor call to ensure that each object of class initiliased properly
 * Constructor call be be done implicitly or explicitly.
 * If constructor call is not defined explicitly , the compiler always creates constructor of a class
 * implicitly. This constructor doesnt take any arguments and returns nothing.
 * Default constructor implicitly calls each data members's each data members default constructor to
 * ensure that the data member is initialised properly.
 *
 */
#endif


#if(FIG3_7 == true)
/*
 * (Data Members) Explain the purpose of a data member.
 *
 *a class can have multiple member functions , instead of defining every time same local variables
 *a as a parameter of fuctions , data members can be used to be accessible every members of class functions.
 *a data member is exists throughout the life of the object
 */
#endif


#if(FIG3_9 == true)
/*
 *(Using a Class Without a using Directive) Explain how a program could use class string
	without inserting a using directive.
 *
 *
 */
#endif


#if(FIG3_10 == true)
/*
 * (Set and Get Functions) Explain why a class might provide a set function and a get function
	for a data member.
 *	Set functions is used for allowing clients of class to change the value of private data member.
 *  Get functiobs is used for aloowing clinets of class to read the value of private data member.
 */
#endif

#include <stdio.h>

void gizem1( char *, const char * );

int main(){

  	char string1[ 80 ], string2[ 80 ];

	printf( "ilk string giriniz: " );
	scanf( "%s", string1 );
	printf("İkinci sayiyi giriniz :");
	scanf("%s",string2);
	gizem1( string1, string2 );
	printf(" %s", string1 );
//	system("pause");

	return 0;
}



void gizem1( char *s1, const char *s2 )
{
while ( *s1 != '\0' )
 ++s1;

for ( ; *s1 = *s2; s1++, s2++ )
	; /* boş ifade */
}
