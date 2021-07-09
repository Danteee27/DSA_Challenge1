#include "Data.h"
#include "Calc.h"

void Vietlanguage() {
	_setmode(_fileno(stdin), 0x00020000);
	_setmode(_fileno(stdout), 0x00020000);
}

void ASCIIlanguage() {
	_setmode(_fileno(stdin), _O_TEXT);
	_setmode(_fileno(stdout), _O_TEXT);
}


int checkSpec(Score sco, vector<Score> sco_list) {
	for (int i = 0; i < sco_list.size(); i++)
		if (sco.ID == sco_list[i].ID)
			return sco_list[i].spec;
	return -1;
}


vector<Score> ReadAF(string path, int &foundation) {
	wfstream fin(path, wfstream::in);

	fin.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));

	fin.seekg(-1, std::ios_base::end);
	int end = fin.tellg(); // Ki tu cuoi cung cua .csv
	fin.seekg(0, std::ios_base::beg);

	fin.ignore(100, wchar_t(0xfeff)); // Bo ki tu dau tien 

	fin.ignore(256, '\n'); // Bo line dau tien 

	vector<Score> res;

	Score sco_temp;

	wstring temp;

	while (fin.tellg() < end) {
		getline(fin, sco_temp.ID, L',');
		Vietlanguage();
		getline(fin, sco_temp.name, L',');
		ASCIIlanguage();
		getline(fin, temp);
		if (temp == L"foundation") { 
			sco_temp.spec = 1; 
			foundation++;
		}
		else if (temp == L"sub") sco_temp.spec = 0;

		res.push_back(sco_temp);
	}

	return res;

}

vector<Student> ReadStudent_Interest(string path) {
	vector<Student> List;

	wfstream fin(path, wfstream::in);

	fin.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));

	fin.seekg(-1, std::ios_base::end);

	int end = fin.tellg(); // Ki tu cuoi cung cua .csv
	fin.seekg(0, std::ios_base::beg);

	fin.ignore(100, wchar_t(0xfeff)); // Bo ki tu dau tien 

	fin.ignore(256, '\n'); // Bo line dau tien 

	wstring temp;

	Student Stu_Temp;

	int debug = 0;

	



	for(int i = 0; i < 440; i++) {

		Stu_Temp.interest.clear();

		getline(fin, Stu_Temp.StudentID, L',');

		getline(fin, Stu_Temp.last, L',');

		getline(fin, Stu_Temp.first, L',');

		getline(fin, temp, L','); // REGDATE

		
		getline(fin, temp, L',');
		Stu_Temp.interest.push_back(temp);
		getline(fin, temp, L',');
		Stu_Temp.interest.push_back(temp);
		getline(fin, temp, L',');
		Stu_Temp.interest.push_back(temp);
		getline(fin, temp, L',');
		Stu_Temp.interest.push_back(temp);
		getline(fin, temp, L',');
		Stu_Temp.interest.push_back(temp);
		getline(fin, temp);
		Stu_Temp.interest.push_back(temp);

		List.push_back(Stu_Temp);
	}
	return List;

}

vector<Student> ReadStudent_Grading(vector<Score> sco_list, string path) {

	vector<Student> List;

	wfstream fin(path, wfstream::in);

	fin.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));

	fin.seekg(-1, std::ios_base::end);
	int end = fin.tellg(); // Ki tu cuoi cung cua .csv
	fin.seekg(0, std::ios_base::beg);

	fin.ignore(100, wchar_t(0xfeff)); // Bo ki tu dau tien 

	fin.ignore(256, '\n'); // Bo line dau tien 

	wstring temp;

	wstring temp2;

	Student stu_temp;

	Score sco_temp;

	int first_check = 0;


	int debug_count = 0;

	const int DEBUG_UNTIL_CRASH = 16691;

	while (fin.tellg() < end)
	{
		getline(fin,temp, L','); // Bo qua MAJ

		getline(fin, temp, L',');

		if (first_check == 0) temp2 = temp; // Lan dau tien set temp_ID2

		if (temp != temp2) {
			List.push_back(stu_temp);

			stu_temp.score.clear();					// Reset vector score trong Student

			first_check = 0; 
		}

		temp2 = temp; // Gan gia tri ID de check cho den khi ID khac'

		stu_temp.StudentID = temp2;
		getline(fin, stu_temp.last, L',');
		getline(fin, stu_temp.first, L',');
		getline(fin, stu_temp.programID, L',');
		
		wstring Num_Temp;
		getline(fin, Num_Temp, L','); // Bo qua 1 cot AY
	

		getline(fin, Num_Temp, L',');
		
		sco_temp.term = stoi(Num_Temp);
		getline(fin, sco_temp.ID, L','); 
		
		Vietlanguage();
		getline(fin, sco_temp.name, L',');
		ASCIIlanguage();

		getline(fin, Num_Temp, L',');   // Bo qua 1 cot Class


		getline(fin, Num_Temp, L',');
		sco_temp.grade = Num_Temp == L"NULL" ? 0 : stod(Num_Temp);


		getline(fin, Num_Temp, L',');	// GradeType la` o^ tro^'ng

		getline(fin, Num_Temp);
		sco_temp.credits = stoi(Num_Temp);

		sco_temp.spec = checkSpec(sco_temp, sco_list);

		
		stu_temp.score.push_back(sco_temp);
		


		first_check = 1;

		
	}
	
		return List;
}


unordered_map<wstring, int> MajorRead(string path) {
	unordered_map<wstring, int> res;
	wfstream fin(path, wfstream::in);

	fin.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));

	fin.seekg(-1, std::ios_base::end);

	int end = fin.tellg(); // Ki tu cuoi cung cua .csv
	fin.seekg(0, std::ios_base::beg);

	fin.ignore(100, wchar_t(0xfeff)); // Bo ki tu dau tien 

	fin.ignore(256, '\n'); // Bo line dau tien 

	wstring s_temp;
	wstring s_temp2;


	while (fin.tellg() < end) {
		getline(fin, s_temp, L',');
		getline(fin, s_temp, L',');
		getline(fin,s_temp2);

		res[s_temp] = stoi(s_temp2);
	}

	return res;
}


void TimNguoiThan(vector<Student> StuList, wstring TenNguoiThan) {
	for (int i = 0; i < StuList.size(); i++) {
		//TIM KIEM TUAN LOC
		if (StuList[i].StudentID == TenNguoiThan) {
			wcout << StuList[i].StudentID << " " << StuList[i].last << " " << StuList[i].first << " " << StuList[i].RegDate << " ";
			for (int damme = 0; damme < 6; damme++)
				wcout << StuList[i].interest[damme] << " ";
			wcout << StuList[i].Selected << " " << StuList[i].Chosen << " " << StuList[i].foundGPA << " " << StuList[i].allGPA << endl;
		}
	}
}

void SapDatThamVong(vector<Student>&StuList, mapWSI Majors) {
	for (int i = 0; i < StuList.size(); i++) {
		if (StuList[i].Chosen != -1) continue;
		for (int j = 0; j < 6; j++) {
			if (Majors[StuList[i].interest[j]] > 0) {
				Majors[StuList[i].interest[j]]--;
				StuList[i].Chosen = j + 1;
				StuList[i].Selected = StuList[i].interest[j];
				break;
			}
		}
	}
}

void XoaNhungHocSinhKhongCoThamVong(vector<Student>& List) {
	auto it = List.begin();

	while (it != List.end()) {
		if ((*it).interest.size() < 6) {
			it = List.erase(it);
		}
		else it++;
	}
}

void HopNhatHocSinh(vector<Student> Interest_List, vector<Student>& Grade_List) {
	int j = 0;
	for (int i = 0; i < Grade_List.size(); i++) {
		for (j = 0; j < Interest_List.size(); j++) {
			if (Interest_List[j].StudentID == Grade_List[i].StudentID) {
				Grade_List[i].interest = Interest_List[j].interest;
			}
		}
	}


}

void HopNhatNhungHocSinhVoTinhBiTrung(vector<Student>& List_Student_Grading, int foundation) {
	int j = 0;
	vector<Student>::iterator it1;
	vector<Student>::iterator it2;
	for (int i = 0; i < List_Student_Grading.size(); i++) {
		it1 = List_Student_Grading.begin() + i;
		int j = i + 1;

		int erase = 0;

		for (; j < List_Student_Grading.size(); j++) {
			if (List_Student_Grading[i].StudentID == List_Student_Grading[j].StudentID) {
				for (int z = 0; z < List_Student_Grading[j].score.size(); z++) {
					List_Student_Grading[i].score.push_back(List_Student_Grading[j].score[z]);
				}
				it2 = List_Student_Grading.begin() + j;
				erase++;
				
				if (List_Student_Grading[i].StudentID != List_Student_Grading[j + 1].StudentID) break;
			}
			else break;
		}
		List_Student_Grading[i].foundGPA = CalcFoundGPA(List_Student_Grading[i], foundation);
		List_Student_Grading[i].allGPA = CalcAllGPA(List_Student_Grading[i]);

		if (erase > 0) {
			List_Student_Grading.erase(it1+1, it2+1);
		}
	}

}

// source: https://codereview.stackexchange.com/questions/167680/merge-sort-implementation-with-vectors

void mergeSort(vector<Student>& left, vector<Student>& right, vector<Student>& bars)
{
	int nL = left.size();
	int nR = right.size();
	int i = 0, j = 0, k = 0;

	while (j < nL && k < nR)
	{
		wstring b1 = left[j].StudentID;
		wstring b2 = right[k].StudentID;
		int c1 = stoi(b1.erase(0, 2));
		int c2 = stoi(b2.erase(0, 2));

		if (c1 < c2) {
			bars[i] = left[j];
			j++;
		}
		else {
			bars[i] = right[k];
			k++;
		}
		i++;
	}
	while (j < nL) {
		bars[i] = left[j];
		j++; i++;
	}
	while (k < nR) {
		bars[i] = right[k];
		k++; i++;
	}
}
void sort(vector<Student>& bar) {
	if (bar.size() <= 1) return;

	int mid = bar.size() / 2;
	vector<Student> left;
	vector<Student> right;

	for (size_t j = 0; j < mid; j++)
		left.push_back(bar[j]);
	for (size_t j = 0; j < (bar.size()) - mid; j++)
		right.push_back(bar[mid + j]);

	sort(left);
	sort(right);
	mergeSort(left, right, bar);
}

void mergeSort_grade(vector<Student>& left, vector<Student>& right, vector<Student>& bars)
{
	int nL = left.size();
	int nR = right.size();
	int i = 0, j = 0, k = 0;

	while (j < nL && k < nR)
	{

		if (isGreater(left[j], right[k])) {
			bars[i] = left[j];
			j++;
		}
		else {
			bars[i] = right[k];
			k++;
		}
		i++;
	}
	while (j < nL) {
		bars[i] = left[j];
		j++; i++;
	}
	while (k < nR) {
		bars[i] = right[k];
		k++; i++;
	}
}
void sort_grade(vector<Student>& bar) {
	if (bar.size() <= 1) return;

	int mid = bar.size() / 2;
	vector<Student> left;
	vector<Student> right;

	for (size_t j = 0; j < mid; j++)
		left.push_back(bar[j]);
	for (size_t j = 0; j < (bar.size()) - mid; j++)
		right.push_back(bar[mid + j]);

	sort_grade(left);
	sort_grade(right);
	mergeSort_grade(left, right, bar);
}
