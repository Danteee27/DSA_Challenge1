#include "Data.h"

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

double CalcFoundGPA(Student& a, int x) { // x: the number of all foundation courses 
	if (countFound(a) < x) 
		return 0;
	double temp = 0, credits = 0;
	for (int i = 0; i < x; i++) {
		if (a.score[i].spec == 1) {
			temp += a.score[i].grade * a.score[i].credits;
			credits += a.score[i].credits;
		}
	}
	double fGPA = temp / credits;
	return roundDouble(fGPA);
}

double CalcAllGPA(Student& a) { 
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