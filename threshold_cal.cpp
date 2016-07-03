// threshold_cal.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctype.h>
using namespace std;

#define DATA 2550

int main()
{
	//remove all file first
	remove("result.txt");

	//input file of libSVM format
	string fileName = "top_label0_rng.txt";
	ifstream inFile;
	inFile.open(fileName);

	//output file 
	string fileName2 = "top0_threshold.txt";
	ofstream outFile;
	outFile.open(fileName2, ios::out);

	//provide warning if fail to open file
	while (!inFile.is_open())
	{
		cout << "fail to open file!" << endl;
		return 0;
	}

	//2 temporary string array used for transforming
	string trans1[12];
	string trans2[12];
	double thrs[12] = { 0 };

	for (int i = 0; i < 12; i++)
	{
		trans1[i] = "";
		trans2[i] = "";
	}

	//process of data
	while (!inFile.eof())
	{
		string temp = "";
		getline(inFile, temp);

		//get rid of the space first
		stringstream ss(temp);
		string item;
		int l = 0;
		while (getline(ss, item, ' '))
		{
			trans1[l] = item;
			l++;
		}

		for (int i = 0; i < 12; i++)
		{
			cout << trans1[i] << " ";
		}
		cout << endl;

		//get rid of the ordering and :
		l = 0;
		int count = 0;
		for (int i = 1; i < 12; i++)//0:label
		{
			stringstream ss(trans1[i]);
			string item;

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

		for (int i = 0; i < 12; i++)
		{
			cout << trans2[i] << "    ";
		}
		cout << endl;

		trans2[11] = trans1[0];

		for (int i = 0; i < 12; i++)
		{
			thrs[i] += stod(trans2[i]);
		}
	}

	for (int i = 0; i < 12; i++)
	{
		thrs[i] = thrs[i] / DATA;
		outFile << "label " << i << " : " << thrs[i] << endl;
	}

	outFile.close();

	//system("pause");
	return 0;
}

