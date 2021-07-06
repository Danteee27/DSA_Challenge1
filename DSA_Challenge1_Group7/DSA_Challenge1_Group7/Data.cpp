#include "Data.h"

void Vietlanguage()
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
}

void ASCIIlanguage()
{
	_setmode(_fileno(stdin), _O_TEXT);
	_setmode(_fileno(stdout), _O_TEXT);
}


int checkSpec(Score sco, vector<Score> sco_list) {
	for (int i = 0; i < sco_list.size(); i++)
		if (sco.ID == sco_list[i].ID)
			return sco_list[i].spec;
	return -1;
}

vector<Score> ReadAF(string path, int& foundation) {
	wfstream fin(path, wfstream::in);

	fin.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));

	fin.seekg(-1, ios_base::end);
	int end = fin.tellg(); // Ki tu cuoi cung cua .csv
	fin.seekg(0, ios_base::beg);

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


vector<Student> ReadStudent(vector<Score> sco_list,int foundNum, string path) {  // File chua hoan thien nen chi doc toi line 16690

	vector<Student> List;

	wfstream fin(path, wfstream::in);

	fin.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));

	fin.seekg(-1, ios_base::end);
	int end = fin.tellg(); // Ki tu cuoi cung cua .csv
	fin.seekg(0, ios_base::beg);

	fin.ignore(100, wchar_t(0xfeff)); // Bo ki tu dau tien 

	fin.ignore(256, '\n'); // Bo line dau tien 

	wstring temp;

	wstring temp2;

	Student stu_temp;

	Score sco_temp;

	int first_check = 0;


	int debug_count = 0;

	const int DEBUG_UNTIL_CRASH = 16691; // Line 16692 la line loi~

	while (/*fin.tellg() < end*/ debug_count < DEBUG_UNTIL_CRASH)
	{
		getline(fin, temp, L','); // Bo qua MAJ

		getline(fin, temp, L',');

		if (first_check == 0) temp2 = temp; // Lan dau tien set temp_ID2

		if (temp != temp2) {
			stu_temp.score.foundGPA = CalcFoundGPA(stu_temp, foundNum);
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

		debug_count++;

		getline(fin, Num_Temp, L',');	// GradeType la` o^ tro^'ng

		getline(fin, Num_Temp);
		sco_temp.credits = stoi(Num_Temp);

		sco_temp.spec = checkSpec(sco_temp, sco_list);


		stu_temp.score.push_back(sco_temp);





		first_check = 1;

	}




	return List;
}