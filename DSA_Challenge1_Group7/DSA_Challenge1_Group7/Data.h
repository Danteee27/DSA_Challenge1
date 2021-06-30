#ifndef __DATA
#define __DATA

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
	double allGPA;
	double foundGPA;
	int Acc_Credits = 0;
};


void Vietlanguage();

void ASCIIlanguage();

int checkSpec(Score sco, vector<Score> sco_list);

vector<Score> ReadAF(string path, int& foundation);

vector<Student> ReadStudent(vector<Score> sco_list, string path);

#endif
