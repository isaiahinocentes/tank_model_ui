#pragma once
#include "Model.h" //Tank Model Variables
#include <iomanip> //For output formatting

//Conversions
//l/ps to mm³/day
static double lps2mmd(double lps) {
	return lps * 86400000000;
}
//km² to mm²
static double km2mm(double km) {
	return km * 1000000000000;
}
static double Qlps2Qmmd() {

}

//Get the average Q Observed
static double ave_QO() {
	double sum = 0;
	for each (double QO in vQObserved)
	{
		sum += QO;
	}
	double ave = sum / sizeof(vQObserved);
	cout << "Average for QO: " << ave << endl;
	return ave;
}

//Get Average Precipitation
static double ave_Prec() {
	double sum = 0;
	for each (double p in vPrecipitation)
	{
		sum += p;
	}
	double ave = sum / sizeof(vPrecipitation);
	cout << "Average for Precipitation: " << ave << endl;
	return ave;
}

//Water balance Equations
static double c_hA(double p, double e, double qa1, double qa2, double qa0) {
	return p - e - qa1 - qa2 - qa0;
}
static double c_hB(double qa0, double qb1, double qb0) {
	return qa0 - qb1 - qb0;
}
static double c_hC(double qb0, double qc1, double qc0) {
	return QB0 - QC1 - QC0;
}
static double c_hD(double qc0, double qd1) {
	return qc0 - qd1;
}
static void compute_h() {
	int n = vQObserved.size();
	for (int i = 0; i < n; i++)
	{
		hA = c_hA(vQObserved.at(i), Evap, QA1, QA2, QA0); //The first parameter should be Precipitation.at(i)
		hB = c_hB(QA0, QB1, QB0);
		hC = c_hC(QB0, QC1, QC0);
		hD = c_hD(QC0, QD1);
	}
}



//Compute QC
static void compute() {
	int n = vQObserved.size();
	for (int i = 0; i < n; i++)
	{
		init_Qs(vQObserved.at(i));

		hA = c_hA(vPrecipitation.at(i), Evap, QA1, QA2, QA0); 
		hB = c_hB(QA0, QB1, QB0);
		hC = c_hC(QB0, QC1, QC0);
		hD = c_hD(QC0, QD1);

		cout << "Values for \"h\": " << endl
			<< "hA:" << setprecision(10) << hA << endl
			<< "hB:" << setprecision(10) << hB << endl
			<< "hC:" << setprecision(10) << hC << endl
			<< "hD:" << setprecision(10) << hD << endl << endl;

		nA1 = c_nA1(hA);
		nA2 = c_nA2(hA);
		nB1 = c_nB1(hB);
		nC1 = c_nC1(hC);
		nD1 = c_nD1(hD);

		cout << "Multipliers [1/0]: " << endl
			<< "A1:" << nA1 << endl
			<< "A2:" << nA2 << endl
			<< "B1:" << nB1 << endl
			<< "C1:" << nC1 << endl
			<< "D1:" << nD1 << endl << endl;

		double tmp_QC =
			(QA1 * nA1) +
			(QA2 * nA2) +
			(QB1 * nB1) +
			(QC1 * nC1) +
			(QD1 * nD1);

		cout << "QC = " << endl
			<< QA1 << "*" << nA1 << " + " << endl
			<< QA2 << "*" << nA1 << " + " << endl
			<< QB1 << "*" << nB1 << " + " << endl
			<< QC1 << "*" << nC1 << " + " << endl
			<< QD1 << "*" << nD1 << " = " << endl
			<< tmp_QC << endl << endl;

		vQCalculated.push_back(tmp_QC);
	}

	cout << "Finished Copmutations..." << endl << endl;
}
static double c_QC() {
	return
		(QA1 * nA1) +
		(QA2 * nA2) +
		(QB1 * nB1) +
		(QC1 * nC1) +
		(QD1 * nD1);
}
static void computeQCalculated() {
	//Get values for h
	//hA = c_hA();
	//hB = c_hB();
	//hC = c_hC();
	//hD = c_hD();

	//get the height of the tanks
	//HA = c_HA();
	//HB = c_HB();
	//HC = c_HC();
	//HD = c_HD();

	//the Multipliers
	//nA1 = c_nA1();
	//nA2 = c_nA2();
	//nB1 = c_nB1();
	//nC1 = c_nC1();
	//nD1 = c_nD1();

	//Compute QC
	QComp = c_QC();
}