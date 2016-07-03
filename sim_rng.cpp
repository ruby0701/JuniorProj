#include <iostream>
#include <cstdlib> 
#include <fstream>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctype.h>

using namespace std;

#define rng 190
#define total 35910

int main()
{
	//remove("low_label0_rng_txt");
	int i, j, count = -1, choice[rng], temp;

	char buffer[total];

	ifstream fin;
	ofstream fout;//for record
	ofstream fout2;//for experiment

	srand(time(NULL));

	fin.open("all_label_0.txt", ios::in);

	do
	{
		fin.getline(buffer, sizeof(buffer));

		count++;

	} while (!fin.eof());

	for (i = 0; i < rng; i++)
	{
		temp = rand() % count;

		for (j = 0; j < i; j++)
		{
			if (temp == choice[j])
			{
				i--;
				break;
			}
		}
		if (temp != choice[j])
		{
			choice[i] = temp;
		}
	}

	fin.close();

	sort(choice, choice + rng);

	i = 0;
	count = -1;

	fin.open("all_label_0.txt", ios::in);
	fout.open("5_all_label0_result.txt", ios::out);
	fout2.open("5_all_label0_rng.txt", ios::out);
	

	do
	{
		fin.getline(buffer, sizeof(buffer));

		count++;

		if (choice[i] == count)
		{
			//output for experiment
			string trans1[20];
			string temp(buffer);

			//get rid of the space first
			stringstream ss(temp);
			string item;
			int l = 0;
			while (getline(ss, item, ' '))
			{
				trans1[l] = item;

				if (l == 0 || (l >= 9 && l <= 20))
				{
					fout2 << trans1[l] << " ";
				}

				l++;
			}
			fout2 << endl;
			
			//output for record
			fout << buffer << endl;
			i++;
		}

	} while (!fin.eof());

	return 0;
}