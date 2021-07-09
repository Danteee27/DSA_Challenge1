#include "Output.h"
#include "Data.h"

void NhungNguoiXungDang(vector<Student> StuList, string path) {
	wofstream fout(path);
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
	fout.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
	fout << L"StudentID,LastName,FirstName,RegDate,I1,I2,I3,I4,I5,I6,Selected,Chosen,GPA_Foundation,GPA_All" << endl;
	for (int i = 0; i < StuList.size(); i++) {
		fout << StuList[i].StudentID << L"," << StuList[i].last << L"," << StuList[i].first << L"," << StuList[i].RegDate << L",";
		for (int iuthich = 0; iuthich < 6; iuthich++)
			fout << StuList[i].interest[iuthich] << L",";
		fout << StuList[i].Selected << L"," << StuList[i].Chosen << L"," << StuList[i].foundGPA << L"," << StuList[i].allGPA << endl;
	}
}

void writeMajor(vector<Student> major_list, string path) {
	wofstream fout(path + ".csv");
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
	converter.from_bytes(path);
			
	fout.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));

	// line dau tien
	fout << L"StudentID,LastName,FirstName,RegDate,Chosen,GPA_Foundation,GPA_All" << endl;

	// may thang sinh vien
	for (int i = 0; i < major_list.size(); i++) {
		if (major_list[i].Selected == converter.from_bytes(path)) {
			fout << major_list[i].StudentID << L",";
			fout << major_list[i].last << L",";
			fout << major_list[i].first << L",";
			fout << major_list[i].RegDate << L",";
			fout << major_list[i].Chosen << L",";
			fout << major_list[i].foundGPA << L",";
			fout << major_list[i].allGPA << endl;
		}
	}

}