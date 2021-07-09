#include "Output.h"
#include "Data.h"

void NhungNguoiXungDang(vector<Student> StuList, string path) {
	ofstream fout(path);
	fout << "StudentID,LastName,FirstName,RegDate,I1,I2,I3,I4,I5,I6,Selected,Chosen,GPA_Foundation,GPA_All" << endl;
	for (int i = 0; i < StuList.size(); i++) {
		fout << StuList[i].StudentID << "," << StuList[i].last << "," << StuList[i].first << "," << StuList[i].RegDate << ",";
		for (int iuthich = 0; iuthich < 6; iuthich++)
			fout << StuList[i].interest[iuthich] << ",";
		fout << StuList[i].Selected << "," << StuList[i].Chosen << "," << StuList[i].foundGPA << "," << StuList[i].allGPA << endl;
	}
}

void writeMajor(vector<Student> major_list, string path) {
	ofstream fout(path + ".csv");
			
	// line dau tien
	fout << "StudentID,LastName,FirstName,RegDate,Chosen,GPA_Foundation,GPA_All" << endl;

	// may thang sinh vien
	for (int i = 0; i < major_list.size(); i++) {
		if (major_list[i].Selected == path) {
			fout << major_list[i].StudentID << ",";
			fout << major_list[i].last << ",";
			fout << major_list[i].first << ",";
			fout << major_list[i].RegDate << ",";
			fout << major_list[i].Chosen << ",";
			fout << major_list[i].foundGPA << ",";
			fout << major_list[i].allGPA << endl;
		}
	}

}