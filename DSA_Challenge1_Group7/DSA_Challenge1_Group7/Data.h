#ifndef __DATA
#define __DATA

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <locale>
#include <codecvt>
#include <Windows.h>
#include <sstream>
#include <fcntl.h>  
#include <io.h>
#include <map>
#include <unordered_map>
#include <cstdio>


using std::unordered_map;

using std::string;

using std::cout;

using std::cin;

using std::vector;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::fstream;



typedef unordered_map<string, int> mapWSI;
typedef struct Student Student;

void Vietlanguage();
void ASCIIlanguage();


struct Score {
	string ID;
	string name;
	int term;
	double grade;
	int credits = 0;
	int spec;
};


struct Student {
	string StudentID;
	string last;
	string first;
	string programID;
	vector<Score> score;
	string RegDate;
	vector<string> interest;
	string Selected;
	int Chosen = -1;
	double allGPA;
	double foundGPA;
	int Acc_Credits = 0;
};

int checkSpec(Score sco, vector<Score> sco_list);

vector<Score> ReadAF(string path, int& foundation);
vector<Student> ReadStudent_Interest(string path);
vector<Student> ReadStudent_Grading(vector<Score> sco_list, string path);

unordered_map<string, int> MajorRead(string path);

void TimNguoiThan(vector<Student> StuList, string TenNguoiThan);
void SapDatThamVong(vector<Student>&StuList, mapWSI Majors);
void XoaNhungHocSinhKhongCoThamVong(vector<Student>& List);
void HopNhatHocSinh(vector<Student> Interest_List, vector<Student>& Grade_List);
void HopNhatNhungHocSinhVoTinhBiTrung(vector<Student>& List_Student_Grading, int foundation);

void mergeSort(vector<Student>& left, vector<Student>& right, vector<Student>& bars);
void sort(vector<Student>& bar);

void mergeSort_grade(vector<Student>& left, vector<Student>& right, vector<Student>& bars);
void sort_grade(vector<Student>& bar);
#endif
