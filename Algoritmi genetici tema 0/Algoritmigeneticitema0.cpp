// Algoritmigeneticitema0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <math.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <float.h>

# define PI           3.14159265358979323846

using namespace std;

vector<float>interval(2);
int	val;
double min=DBL_MAX;
double total;
void De_Jong_fct(vector < float > &vectr_val) {
	float sum = 0;
	for (int i = 0;i<vectr_val.size();i++) {
		sum += vectr_val.at(i)*vectr_val.at(i);
	}
	if (min > sum)min = sum;
	total += sum;
//	cout << "\n De J:" << sum;

}
void Schwefel_7(vector<float>&vectr_val) {
	float sum = 0;
	for (int i = 0; i < vectr_val.size(); i++)sum += (-vectr_val.at(i)*sin(sqrt(abs(vectr_val.at(i)))));
//	cout << "\n Schwefel:" << sum;
	if (min > sum)min = sum;
	total += sum;
}

void Rastrigin(vector<float>&vectr_val) {
	float sum = 10 * vectr_val.size();
	for (int i = 0; i < vectr_val.size(); i++) {
		sum += vectr_val.at(i)*vectr_val.at(i) - 10 * cos(2 * PI*vectr_val.at(i));
	}
	//cout << "\n Rastrigin:" << sum;
	if (min > sum)min = sum;
	total += sum;
}

void Six_Hump(vector<float>&vectr_val) {
	float sum;
	sum = (4 - 2.1*pow(vectr_val.at(0), 2) + pow(vectr_val.at(0), 4 / 3))*pow(vectr_val.at(0), 2) + vectr_val.at(0)*vectr_val.at(1) + (-4 + 4 * pow(vectr_val.at(1), 2))*pow(vectr_val.at(1), 2);
	//cout << "\n Six-Hump:" << sum;
	if (min > sum)min = sum;
	total += sum;
}

void randFloatGen(vector<float>&vectr_val, vector<float>interval) {
	for (int i = 0; i < vectr_val.size();i++) {
		vectr_val.at(i) = interval.at(1) - rand() % abs((int)interval.at(1)) - rand() / static_cast<float>(RAND_MAX);
		if (rand() % 2 == 0)vectr_val.at(i) = -vectr_val.at(i);
		//i = rand() % interval.at(1);
		//i = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		//i =interval.at(0)+rand()%abs(interval.at(0))+static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		//cout << i << ":"<<vectr_val.at(i)<<"\n";
	}
}


int main()
{
	clock_t start, finish;
	
	srand(static_cast <signed>(time(0)));
	string		_function;

	cout << " 1)De Jong \n 2)Schwefel 7 \n 3)Rastrigin \n 4)Six Hump \n Introduceti tipul de functie:";
	getline(cin, _function);
	cout << "\n";
	int run_times;
	cout << " Numar de rulari:";
	cin >> run_times;
	run_times = abs(run_times);
	start = clock();
	if (_function.at(0) >= ('0') && _function.at(0) <= (3 + '0')) {
		cout << " Introduceti numarul de elemnete:";
		cin >> val;
		cout << "\n";
	}
	if (_function.at(0) == '0' + 1) {

		vector<float> vectr_val(val);

		interval.at(0) = -5.12;
		interval.at(1) = 5.12;
		for (int i = 0; i < run_times; i++) {
			randFloatGen(vectr_val, interval);

			De_Jong_fct(vectr_val);
		}
	}

	if (_function.at(0) == '0' + 2) {
		//cout << " Introduceti numarul de elemnete:";
		//cin >> val;
		//cout << "\n";
		vector<float> vectr_val(val);
		
		interval.at(0) = -500;
		interval.at(1) = 500;
		for (int i = 0; i < run_times; i++) {
			randFloatGen(vectr_val, interval);

			Schwefel_7(vectr_val);
		}
	}
	
	if (_function.at(0) == '0' + 3) {
		//cout << " Introduceti numarul de elemente:";
		//cin >> val;
		//cout << "\n";
		vector<float> vectr_val(val);
		
		interval.at(0) = -5.12;
		interval.at(1) = 5.12;
		for (int i = 0; i < run_times; i++) {
			randFloatGen(vectr_val, interval);

			Rastrigin(vectr_val);
		}
	}

	if (_function.at(0) == '0' + 4) {
		val = 2;
		vector<float> vectr_val_x1(1);
		vector<float> vectr_val(2);
		vector<float> vectr_val_x2(1);
	
		interval.at(0) = -3;
		interval.at(1) = 3;
		randFloatGen(vectr_val_x1, interval);
		vectr_val.at(0) = vectr_val_x1.at(0);
	
		interval.at(0) = -2;
		interval.at(1) = 2;
		for (int i = 0; i < run_times; i++) {
			randFloatGen(vectr_val_x2, interval);
			vectr_val.at(1) = vectr_val_x2.at(0);

			Six_Hump(vectr_val);
		}
	}
	if(!(_function.at(0)<='0'+4&&_function.at(0)>='0'+1))
	{
		cout<< "NOT A GOOD VALUE!";
	}
	cout << "\n";
	finish = clock();
	cout << " Execution time:" << (float)(finish - start) / CLOCKS_PER_SEC << " seconds \n";
	cout << " Min:" << min << "\n Medie:" << total / run_times;
	cout << "\n" << DBL_MIN;
    return 0;
}

