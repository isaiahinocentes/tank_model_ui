#pragma once
#include <iostream> //for COUT and CIN
#include <cmath>	//For Computation
#include <string.h> //For String
#include <string>	//For cout << string
#include <stdlib.h>	//srand, rand
#include <time.h>	//time
#include <iomanip>	//For Output Formatting
#include <vector>	//Vectors
#include "form_menu.h"


using namespace std;

//Function Prototypes
static void init_Qs(double);
static void init_Heights(double);
static double random(double, double);
double n;

///FOR FILE READING
//RainFall mm³/day
static double RFall;
//Drainage Area in km²
static double DA_km;
//Drainage Area in mm²
static double DA_mm;

///FOR SAVING FILE
//Precipitaiton in mm/day
static double Prec = 0, Prec_ave;
static vector<double> vPrecipitation;
//Evaporation mm/day
static double Evap = 0, Evap_ave;
static vector<double> vEvaporation;
//Tank Height
static double TankHeight;
//Height of the Orifice in the Tanks
static double YA1; //The top level orifice.
static double YA2;
static double YB1;
static double YC1;
static double YD1;
//liters/second = mm³/day
static double QComp, QC_ave;
static vector<double> vQCalculated;
static double QObs, QO_ave;
static vector<double> vQObserved;
//PARAMETERS
static double tmp_QC = 0;
static double A0 = 0;
static double A1 = 0;
static double A2 = 0;
static double B0 = 0;
static double B1 = 0;
static double C0 = 0;
static double C1 = 0;
static double D1 = 0;
//OEF
static double OEFv;

///FOR COMPUTATIONs
//Discharges mm/day | Random/calibrated Values
static double QA1, QA2, QA0;
static double QB1, QB0;
static double QC1, QC0;
static double QD1;
//Discharges on Tanks A-D mm³/day
static double hA;
static double hB;
static double hC;
static double hD;
//Water Level on Tanks mm
static double  HA;
static double  HB;
static double  HC;
static double  HD;
//Discharge(Qx) Multipliers | 0 or 1
static double nA1, nA2, nB1, nC1, nD1;


///FOR RANDOMIZATIONS AND INITIALIZATIONS
static double HIGHER_MARGIN = 0.04;
static double BASE_MARGIN = 0.02;
//Init Qs Depending on QO | This uses percentage
static void init_Heights(double base) {
	QA1 = random(base * (HIGHER_MARGIN), base * (BASE_MARGIN));
	QA2 = random(base * (HIGHER_MARGIN), base * (BASE_MARGIN));
	QB1 = random(base * (HIGHER_MARGIN), base * (BASE_MARGIN));
	QC1 = random(base * (HIGHER_MARGIN), base * (BASE_MARGIN));
	QD1 = random(base * (HIGHER_MARGIN), base * (BASE_MARGIN));
	
	YA1 = 0;
	YA2 = (QA1 + QA2 + QA0) / 3;
	YB1 = (QB1 + QB0) / 2;
	YC1 = (QC1 + QC0) / 2;
	YD1 = QD1;

	TankHeight = YA1 + YA2 + YB1 + YC1 + YD1;
}

//Initialize Smaller Tank Heights
static double Q_MARGIN = -0.10;
static void init_Qs(double QO) {

	QA1 = QO * random(.50 + Q_MARGIN, .50);
	QA2 = QO * random(.40 + Q_MARGIN, .40);
	QA0 = QO * random(.39 + Q_MARGIN, .39);

	QB1 = QO * random(.20 + Q_MARGIN, .20);
	QB0 = QO * random(.19 + Q_MARGIN, .19);

	QC1 = QO * random(.15 + Q_MARGIN, .15);
	QC0 = QO * random(.14 + Q_MARGIN, .14);

	QD1 = QO * random(.10 + Q_MARGIN, .10);
}

//Reset Values
static void resetValues() {

	QComp = 0; QC_ave = 0;
	vQCalculated.clear();

	QObs = 0; QO_ave = 0;
	vQObserved.clear();

	RFall = 0;

	DA_km = 0;
	DA_mm = 0;

	TankHeight = 0;

	Prec = 0; Prec_ave = 0;
	vPrecipitation.clear();

	Evap = 0; Evap_ave = 0;
	vEvaporation.clear();

	QA1 = 0; QA2 = 0; QA0 = 0;
	QB1 = 0; QB0 = 0;
	QC1 = 0; QC0 = 0;
	QD1 = 0;

	hA = 0; hB = 0; hC = 0; hD = 0;
	HA = 0; HB = 0; HC = 0; HD = 0;

	YA1 = 0; YA2 = 0;
	YB1 = 0;
	YC1 = 0;
	YD1 = 0;

}

//generate randome
double random(double max, double min){
	return (max - min) * ((double)rand() / (double)RAND_MAX) + min;
}

//Show the Values to Log textbox
static void ShowPandQOtoLog(System::Windows::Forms::TextBox^ Log) {
	
	std::cout << setprecision(2);
	Log->Text += "Drainage Area: " + DA_mm + "\r\n";
	Log->Text += "Precipitation \t\t|\tQObserved\r\n";
	for (int i = 0; i < vPrecipitation.size() && i < vQObserved.size(); i++) {
		Log->Text += vPrecipitation.at(i)  + " \t\t|\t" + vQObserved.at(i) + "\r\n";
	}
}