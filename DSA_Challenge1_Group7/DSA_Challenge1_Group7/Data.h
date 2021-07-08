#ifndef __DATA
#define __DATA

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <locale>
#include<codecvt>
#include<Windows.h>
#include <sstream>
#include <fcntl.h>  
#include <io.h>
#include <map>
#include <unordered_map>

using namespace std;

typedef unordered_map<wstring, int> mapWSI;
//
//
//
//
//

void Vietlanguage();

void ASCIIlanguage();


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
	wstring RegDate;
	vector<wstring> interest;
	wstring Selected;
	int Chosen = -1;
	double allGPA;
	double foundGPA;
	int Acc_Credits = 0;
};

int checkSpec(Score sco, vector<Score> sco_list);

vector<Score> ReadAF(string path, int& foundation);
vector<Student> ReadStudent_Interest(string path);
vector<Student> ReadStudent_Grading(vector<Score> sco_list, string path);

unordered_map<wstring, int> MajorRead(string path);

void TimNguoiThan(vector<Student> StuList, wstring TenNguoiThan);
void SapDatThamVong(vector<Student>&StuList, mapWSI Majors);
void XoaNhungHocSinhKhongCoThamVong(vector<Student>& List);
void HopNhatHocSinh(vector<Student> Interest_List, vector<Student>& Grade_List);
void HopNhatNhungHocSinhVoTinhBiTrung(vector<Student>& List_Student_Grading, int foundation);

#endif
