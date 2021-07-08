#ifndef _CALC_
#define _CALC_

#include "Data.h"


double roundDouble(double var);

int countFound(Student a);

double CalcFoundGPA(Student a, int x);

double CalcAllGPA(Student a);

int CalcAcc_NCredits(Student& a);

bool isGreater(Student a, Student b);

#endif
