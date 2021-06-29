#include "Data.h"

double roundDouble(double var) 
{
	double value = (int)(var * 100 + 0.5);
	return (double)value / 100;
}

void CalcFoundGPA(Student& a) { 
	if (a.foundation.size() < 7) {
		a.foundGPA = 0;
		return;
	}
	double temp = 0, credits = 0;
	for (int i = 0; i < 7; i++) {
		temp += a.foundation[i].grade * a.foundation[i].credits;
		credits += a.foundation[i].credits;
	}
	double fGPA = temp / credits;
	a.foundGPA = roundDouble(fGPA);
}

void CalcAllGPA(Student& a) { 
	double temp = 0, credits = 0;
	int size = a.score.size();
	for (int i = 0; i < size; i++) {
		if (a.score[i].spec != -1) {
			temp += a.score[i].grade * a.score[i].credits;
			credits += a.score[i].credits;
		}
	}
	double AllGPA = temp / credits;
	a.allGPA = roundDouble(AllGPA);
}

void CalcAcc_NCredits(Student& a) {
	int credits = 0, size = a.score.size();
	for (int i = 0; i < size; i++) {
		if (a.score[i].grade >= 5)
			credits += a.score[i].credits;
	}
	a.Acc_Credits = credits;
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