#ifndef BIGDEC_H
#define BIGDEC_H

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <iomanip>
using namespace std;

class BigDec
{
private:
	string number_1;
public:
	BigDec();
	BigDec(string str1);
	BigDec operator+(BigDec S);
	BigDec operator-(BigDec D);
	string getNumber();
	string findsum2(string str1, string str2);
	string findDiff2(string str1, string str2);
	string findDiff(string str1, string str2);
	string findsum(string str1, string str2);
	bool isSmaller(string str1, string str2);
};
#endif // BIGDEC_H
