#ifndef Data
#define Data

#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<fstream>
#include<locale>
#include<codecvt>
#include<Windows.h>
#include<sstream>
#include<fcntl.h>
#include<io.h>

using namespace std;

struct Score {
	wstring ID;
	wstring name;
	int term;
	double grade;
	int credits = 0;
	int spec;
};

struct Student {
	wstring StudentID;
	wstring last;
	wstring first;
	wstring programID;
	vector<Score> score;
	vector<Score> foundation;
	double allGPA;
	double foundGPA;
	int Acc_Credits = 0;
};

#endif
