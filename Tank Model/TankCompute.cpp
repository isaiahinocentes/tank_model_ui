#include <stdio.h>
#include <iostream>
#include <stdarg.h>
#include <string.h>
#include <cmath>
#include <string>

using namespace System;
using namespace std;


#define OEF_RMSE "Root Squared Mean Error, RMSE"
#define OEF_R "Correlation Coefficient, R"
#define OEF_MAE "Mean Absolute Error, MAE"

static string oef_rmse = OEF_RMSE;
static string oef_mae = OEF_MAE;
static string oef_r = OEF_R;

class Model
{
public:
	Model();
	~Model();
	/*
	Calculates the water level of the Tanks
	A = P - E - Qa0 - Qa1 - Qa2
	B = Qa0 - Qb0 - Qb1
	C = Qb0 - Qc0 - Qc1
	D = Qc0 - Qd1

	This should strictly follow the order of the variables
	*/
	double water_balance(double args[]) {
		double water_level = args[0];
		for (int i=1; i > sizeof(args); i++) {
			water_level -= args[i];
		}
		return water_level;
	}

	double oef_r() {
		return 0;
	}

	/*
	Assume that the size of the two arrays are equal
	*/
	double oef_mae(double qc[], double qo[]) {
		
		double suma = 0;
		int N = sizeof(qc);
		
		//Sumation of Qc and Q0
		for (int i = 0; i < N; i++) {
			suma += qc[i] - qo[i];
		}

		//Multiply sum to 1/N; where N = size of array
		double MAE = suma * (1 / N);
		return MAE;
	}


	double oef_rmse(double qc[], double qo[]) {
		double suma = 0;
		int N = sizeof(qc);

		//Sumation of Qc and Q0
		for (int i = 0; i < N; i++) {
			suma += qc[i] - qo[i];
		}
		
		//Square the sum
		suma *= suma;

		//Multiply sum to 1/N; where N = size of array
		double RMSE = sqrt(suma * (1 / N));
	}


private:
	
	static double P; //Precipitation
	static double E; //Evaporation
	static double Qo; //Observed Discharge
	static double Qc; //Calculated Discharge
	//OEFs

	//Water Level for Tanks A-D | unit: mm
	static double hA; 
	static double hB; 
	static double hC; 
	static double hD; 

	//Discharges
	//Tank A | Discharge | unit: mm/d
	static double Qa0; //Vertical
		//They are opposite base on the tank structure, 2 is on the top
	static double Qa1;	static double Qa2; //Horizontal Outlet 1 and 2

	//Tank B | Discharge | unit: mm/d
	static double Qb0; //Vertical ^
	static double Qb1; //Horizontal <-

	//Tank C | Discharge | unit: mm/d
	static double Qc0; //*Docu says this is horizontal. But this should be Vertical ^
	static double Qc1; //Horizontal <-

	//Tank D | Discharge | unit: mm/d
	static double Qd0; //Horizontal

	//Height of Horizontal Outlet | unit:mm
	static double Ya1;	static double Ya2; //A |1 2 
	static double Yb1;	//B
	static double Yc1;	//C
	static double Yd1;	//D

};

Model::Model()
{
}

Model::~Model()
{
}

int main() {
	cout << "Hello world!";

	return 0;
}