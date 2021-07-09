#include "Data.h"
#include "Output.h"

int main(int argc, char* argv[]) {
	if (argc < 3)
		return 0;

	int foundation_num = 0;

	vector<Score> FA_Score_List = ReadAF("Courses.csv", foundation_num);

	vector<Student> List_Student_Grading = ReadStudent_Grading(FA_Score_List, "Grading.csv");
	vector<Student> List_Student_Interest = ReadStudent_Interest("Interests.csv");

	sort(List_Student_Grading);
	sort(List_Student_Interest);

	HopNhatNhungHocSinhVoTinhBiTrung(List_Student_Grading, foundation_num);
	HopNhatHocSinh(List_Student_Interest, List_Student_Grading);
	XoaNhungHocSinhKhongCoThamVong(List_Student_Grading);

	sort_grade(List_Student_Grading);

	unordered_map<wstring, int> major = MajorRead("Majors.csv");
	SapDatThamVong(List_Student_Grading, major);

	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;

	if (strcmp(argv[1], "-all") == 0)
		NhungNguoiXungDang(List_Student_Grading, "Result.csv");


	if (strcmp(argv[1], "-s") == 0)
		TimNguoiThan(List_Student_Grading, converter.from_bytes(argv[2]));


	if (strcmp(argv[1], "-m") == 0)
		writeMajor(List_Student_Grading, argv[2]);
}