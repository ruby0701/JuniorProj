// filter.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctype.h>
using namespace std;

#define attrNum 0

int main()
{
	//set thrsehold data, all
	double thres[12] = { 0
		, 0.548981
		, 0.000626959
		, 0.0104493
		, 0.0993665
		, 0.00264484
		, 0
		, 0.000522466
		, 0.306153
		, 0.0135841
		, 0
		, 0 };

	//remove all file first
	remove("result.txt");

	//input file of libSVM format, label 0
	//string fileName = to_string(fileNum) + "_" + fileType + ".txt";
	string fileName = "mid_label_0.txt";
	ifstream inFile;
	inFile.open(fileName);

	//output file of libSVM format, experiment
	string fileName2 = to_string(attrNum) + "A_mid_label_0.txt";
	ofstream outFile;
	outFile.open(fileName2, ios::out);

	//otput file for record
	string fileName3 = to_string(attrNum) + "A_mid_label_0_result.txt";
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

		//experiment
		/*l = 0;
		count = 0;
		while (l <= 20)
		{
			if (l == 0)
			{
				trans2[11] = trans1[0];
				count++;
			}
			if ((l >= 4 && l <= 14))
			{
				trans2[count] = trans2[l];
				count++;
			}			
			l++;
		}*/
		
	

		/*for (int i = 0; i < 12; i++)
		{
			cout << trans2[i] << "    ";
		}
		cout << endl;*/

		

		//set condition here///////////////////////////////////////////////////////////////////////
		if (stod(trans2[attrNum]) > thres[attrNum])
		{

		count = 0;
		outFile << trans2[11] << " ";
		count++;
		for (int i = 0; i < 11; i++)
		{
			/*if (i == 0 && count == 0)
			{
				outFile << trans2[i] << " ";
				count++;
			}
				
			else if (i != 0)*/
			{
				outFile << count << ":" << trans2[i] << " ";
				count++;
			}
		}						
		outFile << endl;

		//output record
		outFile2 << temp << endl;

		}
	}

	//system("pause");
	return 0;
}