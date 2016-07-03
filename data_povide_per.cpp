// data_povide_per.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctype.h>
using namespace std;

#define dataNum 190
int attrCount[12] = { 0 };

int main()
{
	//removes all files first
	remove("report.txt");
	remove("result.txt");
	remove("label_1.txt");
	remove("label_0.txt");

	//open this file for recording all the situations that are out of control
	ofstream logFile;
	logFile.open("mid_report.txt", ios::out);

	//open this file for similarity result
	ofstream result;
	result.open("mid_result.txt", ios::out);

	ofstream label_1;
	label_1.open("mid_label_1.txt", ios::out);

	ofstream label_0;
	label_0.open("mid_label_0.txt", ios::out);

	//open 2 files in 2 for loops
	for (int index_PTT = 1; index_PTT <= dataNum; index_PTT++)
	{
		string fileName1 = to_string(index_PTT) + "_PTT.txt";//PTT
		//string fileName2 = to_string(index_FB) + "_mid_FB.txt";//FB
		ifstream file1;
		ifstream file2;

		file1.open(fileName1);
		//file2.open(fileName2);

		while (!file1.is_open())
		{
			break;
		}

		while (file1.is_open())
		{
			//store the datas from 2 files individually, use string array , do the rest of the processing in each function
			string data1[12];
			//string data2[12];

			for (int i = 0; i < 12; i++)
			{
				data1[i] = "";
				//data2[i] = "";
			}

			int count = 1;
			while (!file1.eof())
			{
				if (count < 10)
				{
					string temp = "";
					getline(file1, temp);
					temp = temp.substr(2, temp.length());
					data1[count - 1] = temp;
					//cout << data1[count - 1] << endl;
					count++;
				}
				if (count >= 10)
				{
					string temp = "";
					getline(file1, temp);
					temp = temp.substr(3, temp.length());
					data1[count - 1] = temp;
					//cout << data1[count - 1] << endl;
					count++;
				}
				if (count >= 12)
					break;
			}

			file1.close();
			file2.close();

			//count starts here
			for (int i = 0; i < 12; i++)
			{
				if (data1[i] != "")
				{
					attrCount[i]++;
				}
				
			}
		}
	}
		for (int index_FB = 1; index_FB <= dataNum; index_FB++)
		{
			//string fileName1 = to_string(index_PTT) + "_mid_PTT.txt";//PTT
			string fileName2 = to_string(index_FB) + ".txt";//FB
			//ifstream file1;
			ifstream file2;

			//file1.open(fileName1);
			file2.open(fileName2);

			while (!file2.is_open())
			{
				break;
			}

			while (file2.is_open())
			{
				//store the datas from 2 files individually, use string array , do the rest of the processing in each function
				//string data1[12];
				string data2[12];

				for (int i = 0; i < 12; i++)
				{
					//data1[i] = "";
					data2[i] = "";
				}

				int count = 1;
				while (!file2.eof())
				{
					if (count < 10)
					{
						string temp = "";
						getline(file2, temp);
						temp = temp.substr(2, temp.length());
						data2[count - 1] = temp;
						//cout << data2[count - 1] << endl;
						count++;
					}
					if (count >= 10)
					{
						string temp = "";
						getline(file2, temp);
						temp = temp.substr(3, temp.length());
						data2[count - 1] = temp;
						//cout << data2[count - 1] << endl;
						count++;
					}
					if (count >= 12)
						break;
				}

				file2.close();

				//count starts here
				for (int i = 0; i < 12; i++)
				{
					if (data2[i] != "")
					{
						attrCount[i]++;
					}
				}
			}
		}
	

	double count = 0;
	for (int i = 0; i < 12; i++)
	{
		count += attrCount[i];
	}

	double rate = 0;
	rate = count / (dataNum * 22);
	cout << rate << endl;

	return 0;
}