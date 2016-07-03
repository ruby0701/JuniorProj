// attr_sort.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <map>
using namespace std;

#define attrNum 10
#define bound 51

std::multimap<double, int>attr;
std::multimap<double, int>::reverse_iterator rit;

int main()
{
	//remove all file first
	remove("result.txt");

	//input file of libSVM format, label 0
	//string fileName = to_string(fileNum) + "_" + fileType + ".txt";
	string fileName = "low_label_0.txt";
	ifstream inFile;
	inFile.open(fileName);

	//output file of libSVM format, experiment
	string fileName2 = to_string(attrNum) + "A_low_label_0.txt";
	ofstream outFile;
	outFile.open(fileName2, ios::out);

	//otput file for record
	string fileName3 = to_string(attrNum) + "A_low_label_0_result.txt";
	ofstream outFile2;
	outFile2.open(fileName3, ios::out);

	//provide warning if fail to open file
	while (!inFile.is_open())
	{
		cout << "fail to open file!" << endl;
		return 0;
	}

	//2 temporary string array used for transforming
	string trans1[22];
	string trans2[22];

	//variable for sorting
	int attrCount = 0;

	for (int i = 0; i < 12; i++)
	{
		trans1[i] = "";
		trans2[i] = "";
	}

	//process of data
	while (!inFile.eof())
	{
		int line = 0;
		string temp = "";
		getline(inFile, temp);
		attrCount++;

		//get rid of the space first
		stringstream ss(temp);
		string item;
		int l = 0;
		while (getline(ss, item, ' '))
		{
			trans1[l] = item;
			l++;
		}

		//get rid of the ordering and :

		int count = 0;
		for (int i = 1; i < 21; i++)//0:label
		{
			stringstream ss(trans1[i]);
			string item;

			l = 0;
			while (getline(ss, item, ':'))
			{
				if (l % 2 == 1)
				{
					trans2[count] = item;
					count++;
				}
				l++;
			}
		}

		trans2[11] = trans1[0];

		//sorting while inserting
		attr.insert(pair<double, int>(stod(trans2[attrNum]),attrCount));
	}

	//record sorting result
	int bd[bound] = { 0 };
	int b = 0;
	while (b < bound)
	{
		for (rit = attr.rbegin(); rit != attr.rend(); ++rit)
		{
			bd[b] = (*rit).second;
			b++;

			if (b >= bound)
				break;
		}
	}
	

	//output starts here
	inFile.close();
	inFile.open(fileName);
	attrCount = 0;

	while (!inFile.eof())
	{
		int line = 0;
		string temp = "";
		getline(inFile, temp);
		attrCount++;

		//get rid of the space first
		stringstream ss(temp);
		string item;
		int l = 0;
		while (getline(ss, item, ' '))
		{
			trans1[l] = item;
			l++;
		}

		//get rid of the ordering and :

		int count = 0;
		for (int i = 1; i < 21; i++)//0:label
		{
			stringstream ss(trans1[i]);
			string item;

			l = 0;
			while (getline(ss, item, ':'))
			{
				if (l % 2 == 1)
				{
					trans2[count] = item;
					count++;
				}
				l++;
			}
		}

		trans2[11] = trans1[0];

		for (int b = 0; b < bound; b++)
		{
			if (bd[b] == attrCount)
			{
				//record
				outFile2 << temp << endl;

				//experiment
				count = 0;
				outFile << trans2[11] << " ";
				count++;
				for (int i = 0; i < 11; i++)
				{
					outFile << count << ":" << trans2[i] << " ";
					count++;					
				}
				outFile << endl;
			}
		}

	}
	//system("pause");
	return 0;
}