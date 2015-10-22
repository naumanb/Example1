//============================================================================
// Name        : Lab1.cpp
// Author      : Nauman Baig
// Course      : BME506
// Section     : 04
// Description : Lab1
//============================================================================

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

string dnainput(void) {
    string dna1;
    cout << "Please enter a DNA string: " << endl;
    getline(cin, dna1);
    return(dna1);
}

string validity(string dna1) {
    string dnacheck;
    int valid = dna1.find_first_not_of("aAtTgGcC");
    if (valid!=(-1)) {
    	dnacheck = "INVALID";
    }
    else {
    	dnacheck = "VALID";
    }
    return (dnacheck);
}

string complement(string dna2){
	int size = dna2.size();
	string dnacomp = dna2;
	for (int i=0; i<size; ++i){
		if (dna2[i]=='a'){
			dnacomp[i]='t';
		}
		if (dna2[i]=='A'){
			dnacomp[i]='T';
		}
		if (dna2[i]=='g'){
			dnacomp[i]='c';
		}
		if (dna2[i]=='G'){
			dnacomp[i]='C';
		}
		if (dna2[i]=='t'){
			dnacomp[i]='a';
		}
		if (dna2[i]=='T'){
			dnacomp[i]='A';
		}
		if (dna2[i]=='c'){
			dnacomp[i]='g';
		}
		if (dna2[i]=='C'){
			dnacomp[i]='G';
		}
	}
	return (dnacomp);
}

void mutate(string &dna3){
	int size = dna3.size();
	srand(time(NULL));

	string a = "[";
	string b = "]";

	int randnum = rand()%(size) +1;
	int randlet = rand()%4 +1;

	if ((randlet == 1)&&((dna3[randnum]!='a')||(dna3[randnum]!='A'))){
		dna3[randnum]='A';
	}
	else if ((randlet == 2)&&((dna3[randnum]!='t')||(dna3[randnum]!='T'))){
		dna3[randnum]='T';
	}
	else if ((randlet == 3)&&((dna3[randnum]!='g')||(dna3[randnum]!='G'))){
		dna3[randnum]='G';
	}
	else if ((randlet == 4)&&((dna3[randnum]!='c')||(dna3[randnum]!='C'))){
		dna3[randnum]='C';
	}

	dna3.insert(randnum,a);
	dna3.insert(randnum+2,b);
}

int main() {
	string dna = " ";
	int exit = 1;
	while(exit==1){
		dna = dnainput();
		string dnav1 = dna;
		string dnacheck = validity(dna);
		string dnacomp = complement(dna);
		mutate(dnav1);
		if (dna=="exit"){
			cout << "\nExiting..." << endl;
			exit = 0;
		}
		else {
			cout << "\n" << dna << " (" << dna.size() << " chars) : " << dnacheck << " DNA";
			if (dnacheck=="VALID"){
				cout << " : Compliment (" << dna << ") = " << dnacomp << " : mutate " << dna << " -> " << dnav1 << '\n' << endl;
			}
			else {
				cout << "\n" << endl;
			}
		}
	}
	return 0;
}
