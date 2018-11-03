#include "BigDec.h"

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <iomanip>

BigDec::BigDec()
{
	number_1 = "";
}
BigDec::BigDec(string str1)
{
	number_1 = str1;
}

BigDec BigDec::operator+(BigDec S)
{
	string str_1 = this->number_1;
	string str_2 = S.getNumber();
	cout << findsum(str_1, str_2) << endl;
	return findsum(str_1, str_2);
}



BigDec BigDec::operator-(BigDec D)
{
	string str_1 = this->number_1;
	string str_2 = D.getNumber();
	cout << findDiff(str_1, str_2);
	return findDiff(str_1, str_2);
	/* int n1 = str_1.length(), n2 = str_2.length();

	string str = "";


	reverse(str_1.begin(), str_1.end());
	reverse(str_2.begin(), str_2.end());

	int carry = 0;

	for (int i=0; i<n2; i++)
	{

	int sub = ((str_1[i]-'0')-(str_2[i]-'0')-carry);

	if (sub < 0)
	{
	sub = sub + 10;
	carry = 1;
	}
	else
	carry = 0;

	str.push_back(sub + '0');
	}


	for (int i=n2; i<n1; i++)
	{
	int sub = ((str_1[i]-'0') - carry);


	if (sub < 0)
	{
	sub = sub + 10;
	carry = 1;
	}
	else
	carry = 0;

	str.push_back(sub + '0');
	}


	reverse(str.begin(), str.end());

	cout<<str;
	return str;

	//cout << findDiff(str_1 , str_2) <<endl;*/
}


string BigDec::getNumber()
{
	return this->number_1;
}

bool BigDec::isSmaller(string str1, string str2)
{

	int n1 = str1.length(), n2 = str2.length();

	if (n1 < n2) {
		return true;
	}
	if (n2 < n1) {
		return false;
	}

	for (int i = 0; i<n1; i++) {
		if (str1[i] < str2[i]) {
			return true;
		}
		else if (str1[i] > str2[i]) {
			return false;
		}
	}
	return false;
}

string BigDec::findDiff2(string str1, string str2)
{

	// Before proceeding further, make sure str1
	// is not smaller
	if (isSmaller(str1, str2))
		swap(str1, str2);

	// Take an empty string for storing result
	string str = "";

	// Calculate length of both string
	int n1 = str1.length(), n2 = str2.length();

	// Reverse both of strings
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;

	// Run loop till small string length
	// and subtract digit of str1 to str2
	for (int i = 0; i<n2; i++)
	{
		// Do school mathematics, compute difference of
		// current digits

		int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);

		// If subtraction is less then zero
		// we add then we add 10 into sub and
		// take carry as 1 for calculating next step
		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}

	// subtract remaining digits of larger number
	for (int i = n2; i<n1; i++)
	{
		int sub = ((str1[i] - '0') - carry);

		// if the sub value is -ve, then make it positive
		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}

	// reverse resultant string
	reverse(str.begin(), str.end());

	return str;
}


string BigDec::findsum(string str1, string str2)
{
	if (str1[0] == '-' && str2[0] == '-')
	{
		str1.erase(0, 1);
		str2.erase(0, 1);
		return findsum(str1, str2);
	}
	if (str1[0] == '-') {
		str1.erase(0, 1);
		return findDiff2(str1, str2);
	}


	if (str2[0] == '-') {
		str2.erase(0, 1);
		return findDiff2(str2, str1);
	}

	if (str1.length() > str2.length())
	{
		swap(str1, str2);
	}
	string str = "";
	int n1 = str1.length();
	int n2 = str2.length();

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;

	for (int i = 0; i < n1; ++i)
	{
		int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}
	for (int i = n1; i < n2; ++i)
	{
		int sum = ((str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}
	if (carry)
	{
		str.push_back(carry + '0');
	}
	reverse(str.begin(), str.end());
	return str;
}


string BigDec::findsum2(string str1, string str2)
{
	if (str1.length() > str2.length())
	{
		swap(str1, str2);
	}
	string str = "";
	int n1 = str1.length();
	int n2 = str2.length();

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;

	for (int i = 0; i < n1; ++i)
	{
		int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}
	for (int i = n1; i < n2; ++i)
	{
		int sum = ((str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}
	if (carry)
	{
		str.push_back(carry + '0');
	}
	reverse(str.begin(), str.end());
	return str;
}



string BigDec::findDiff(string str1, string str2)
{
	if (str1[0] == '-' && str2[0] == '-') {
		str1.erase(0, 1);
		str2.erase(0, 1);
		return findDiff2(str1, str2);
	}
	if (str1[0] == '-') {
		str1.erase(0, 1);
		return findsum2(str1, str2);
	}

	if (str2[0] == '-') {
		str2.erase(0, 1);
		return findsum2(str1, str2);
	}

	// Before proceeding further, make sure str1
	// is not smaller
	if (isSmaller(str1, str2))
		swap(str1, str2);

	// Take an empty string for storing result
	string str = "";

	// Calculate length of both string
	int n1 = str1.length(), n2 = str2.length();

	// Reverse both of strings
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;

	// Run loop till small string length
	// and subtract digit of str1 to str2
	for (int i = 0; i<n2; i++)
	{
		// Do school mathematics, compute difference of
		// current digits

		int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);

		// If subtraction is less then zero
		// we add then we add 10 into sub and
		// take carry as 1 for calculating next step
		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}

	// subtract remaining digits of larger number
	for (int i = n2; i<n1; i++)
	{
		int sub = ((str1[i] - '0') - carry);

		// if the sub value is -ve, then make it positive
		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		str.push_back(sub + '0');
	}

	// reverse resultant string
	reverse(str.begin(), str.end());

	return str;
}

