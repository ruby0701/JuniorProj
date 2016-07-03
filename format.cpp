// format.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctype.h>
using namespace std;

#define attrNum 5

int main()
{
	//remove all file first
	remove("result.txt");

	//input file of libSVM format
	string fileName = to_string(attrNum)+"_all.txt";
	ifstream inFile;
	inFile.open(fileName);

	//output file of WEKA format
	string fileName2 = to_string(attrNum) + "_all_WEKA.txt";
	ofstream outFile;
	outFile.open(fileName2,ios::out);

	outFile << "名稱 性別 生日 血型 出沒地 學校 公司 職業 興趣 感情狀態 網址 結果" << endl;

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
			if (i == 1 || i == 9 || i == 11)
			{
				if (trans2[i] == to_string(0))
				{
					outFile << "incorrect ";
				}
				if (trans2[i] == to_string(1))
				{
					outFile << "correct ";
				}
			}
			else
			{
				outFile << trans2[i] << " ";
			}		
		}
		outFile << endl; 
	}

	//system("pause");
	return 0;
}

