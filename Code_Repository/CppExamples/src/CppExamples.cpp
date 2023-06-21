//============================================================================
// Name        : CppExamples.cpp
// Author      : Furkan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	string input_text;
	cout << "Enter the input text :";
	getline(cin,input_text);

	string output_text;

	for(size_t i=0;i < input_text.size();i++){

		output_text += input_text.at(i);

		string temp_text;

		if(i > 0){
			for(size_t j=0;j<=i;j++){
				temp_text += input_text.at(i - j);
			}
			temp_text = temp_text.substr(1,i);
		}


//		cout << " Output text :" << output_text << endl;
//		cout << " Temp text :" << temp_text << endl;
		cout << " final string :" << output_text + temp_text << endl;
	}
	system("pause");
	return 0;
}
