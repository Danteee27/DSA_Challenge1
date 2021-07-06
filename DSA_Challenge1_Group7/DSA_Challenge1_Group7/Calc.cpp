
#include "Calc.h"


double roundDouble(double var) {
	double value = (int)(var * 100 + 0.5);
	return (double)value / 100;
}

// count the number of foundation courses a student has taken
int countFound(Student a) {
	int count = 0, size = a.score.size();
	for (int i = 0; i < size; i++) {
		if (a.score[i].spec == 1)
			count++;
	}
	return count;
}

double CalcFoundGPA(Student a, int x) { // x: the number of all foundation courses 
	if (countFound(a) < x)
		return 0;
	double temp = 0, credits = 0;
	for (int i = 0; i < a.score.size(); i++) {
		if (a.score[i].spec == 1) {
			temp += a.score[i].grade * a.score[i].credits;
			credits += a.score[i].credits;
		}
	}
	double fGPA = temp / credits;
	return roundDouble(fGPA);
}

double CalcAllGPA(Student a) {
	double temp = 0, credits = 0;
	int size = a.score.size();
	for (int i = 0; i < size; i++) {
		if (a.score[i].spec != -1) {
			temp += a.score[i].grade * a.score[i].credits;
			credits += a.score[i].credits;
		}
	}
	double AllGPA = temp / credits;
	return roundDouble(AllGPA);
}

int CalcAcc_NCredits(Student& a) {
	int credits = 0, size = a.score.size();
	for (int i = 0; i < size; i++) {
		if (a.score[i].grade >= 5)
			credits += a.score[i].credits;
	}
	return credits;
}

bool isGreater(Student a, Student b) {
	if (a.foundGPA > b.foundGPA)
		return 1;
	else if (a.foundGPA < b.foundGPA)
		return 0;
	else {
		if (a.allGPA > b.allGPA)
			return 1;
		else if (a.allGPA < b.allGPA)
			return 0;
		else {
			if (a.Acc_Credits > b.Acc_Credits)
				return 1;
			else
				return 0;
		}
	}
}


// source: https://codereview.stackexchange.com/questions/167680/merge-sort-implementation-with-vectors
// sort danh sach sinh vien theo StudentID
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