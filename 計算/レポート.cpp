#include<iostream>
#include<ctime>
#include <stdio.h>
#include <cmath>
using namespace std;

//aを求める関数
double lsm01(double x[], double y[], double* a)
{
	int i;
	double A00 = 0, A01 = 0, A02 = 0, A11 = 0, A12 = 0;

	for (i = 0; i < 4; i++) {
		A00 += 1.0;
		A01 += x[i];
		A02 += y[i];
		A11 += x[i] * x[i];
		A12 += x[i] * y[i];
	}

	*a = (A00 * A12 - A01 * A02) / (A00 * A11 - A01 * A01);
	

	return *a;
}


int main() {
	//乱数を出すため
	srand((unsigned int)time(NULL));


	//問題のデータ
	double data[4][2] = {


		{30,0.43},
		{50,0.5},
		{70,0.57},
		{90,0.7},
		





	};

	double x[4];
	double y[4];
	double A[2000];//aのデータ
	
	//2000回resample
	for (int j = 0; j < 2000; j++) {

		double a = 0;



		for (int i = 0; i < 4; i++) {

			int temp = 0;
			temp = rand() % 4;


			x[i] = data[temp][0];
			y[i] = data[temp][1];


		}

		A[j]=lsm01(x, y, &a);
		

	}
	
	//小さい順にソートする
	for (int k = 0; k < 2000 - 1; k++) {


		for (int l = 0; l < 2000 - k - 1; l++) {


			if (A[l] > A[l + 1]) {


				double temp01 = A[l];

				A[l] = A[l + 1];

				A[l + 1] = temp01;




			}




		}





	}




	cout << "low=  " << A[316]<<endl;

	cout<< "up = " <<A[1682]<< endl;

    system("pause");

	return 0;




}