// attribute_decrease.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctype.h>
using namespace std;

#define fileNum 1
string fileType = "low";
#define attrNum 11

int main()
{
	//remove all file first
	remove("result.txt");

	//input file of libSVM format
	string fileName = to_string(fileNum) + "_" + fileType + ".txt";
	ifstream inFile;
	inFile.open(fileName);

	//output file of libSVM format
	string fileName2 = to_string(fileNum) + "_" + fileType + "_-A" + to_string(attrNum) + ".txt";
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
		int count = 1;
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

		trans2[0] = trans1[0];

		count = 0;
		for (int i = 0; i < 12; i++)
		{
			if (i == 0 && count==0)
			{
				outFile << trans2[i] << " ";
				count++;
			}
			if (i == attrNum)
			{
				cout << trans2[i];
			}
			else
			{
				if (i!=0)
				{
					outFile << count << ":" << trans2[i] << " ";
					count++;
				}		
			}	
		}
		outFile << endl;
	}

	//system("pause");
	return 0;
}