#pragma once
#include <vector>

//Function Prototypes
static double mean(vector<double>);
static double sum(vector<double>);
static double sqsum(vector<double>);
static double stdev(vector<double>);
static vector<double> operator-(vector<double>, double);
static vector<double> operator*(vector<double>, vector<double>);


ofstream oef("..\\OEF_Computations.txt");
static bool init_file() {
	if (oef.bad()) {
		return false;
	}
	oef << setprecision(10);
	return true;
}

//Correlation Function | Range -1.0 - 1.0 | optimal -1 or 1
static double COEFFCORREL(vector<double> QC, vector<double> QO)
{
	double r = sum((QC - mean(QC))*(QO - mean(QO))) / (QC.size()*stdev(QC)* stdev(QO));
	oef << "OEF for R: " << r << endl;
	return r;
}

//Add R2 | Range 0 - 1.0 | optimal 1
static double R2(vector<double> QC, vector<double> QO)
{
	double r2 = pow(sum((QC - mean(QC))*(QO - mean(QO))) / (QC.size()*stdev(QC)* stdev(QO)), 2);
	oef << "OEF for R²: " << r2 << endl;
	return r2;
}

//MAE | range 0.0 - inf | optimal 0.0
static double MAE(vector<double> QC, vector <double> QO) {
	double suma;
	int N = QC.size();
	for (unsigned i = 0; i < N; i++) {
		suma = abs(QC.at(i) - QO.at(i));
		oef << suma << endl;
	}
	double MAE = suma / N;
	oef << "OEF for MAE: " << MAE << endl;
	if (oef.is_open()) {
		oef.close();
	}
	return MAE;
}

//RMSE | range 0 - inf | 0.0
static double RMSE(vector <double> QC, vector <double> QO) {
	double suma;
	int N = QC.size();
	for (unsigned i = 0; i < N; i++) {
		suma = pow(QC.at(i) - QO.at(i), 2);
		oef << suma << endl;
	}
	double rmse = sqrt(suma / N);
	
	oef << "OEF for RMSE: " << rmse << endl;
	if (oef.is_open()) {
		oef.close();
	}
	return rmse;
}

//--These are all for Coeffcorrel
static double mean(vector<double> a)
{
	return sum(a) / a.size();
}
static double sum(vector<double> a)
{
	double s = 0;
	for (int i = 0; i < a.size(); i++)
	{
		s += a[i];
	}
	return s;
}
static double sqsum(vector<double> a)
{
	double s = 0;
	for (int i = 0; i < a.size(); i++)
	{
		s += pow(a[i], 2);
	}
	return s;
}
static double stdev(vector<double> nums)
{
	double N = nums.size();
	return pow(sqsum(nums) / N - pow(sum(nums) / N, 2), 0.5);
}
static vector<double> operator-(vector<double> a, double b)
{
	vector<double> retvect;
	for (int i = 0; i < a.size(); i++)
	{
		retvect.push_back(a[i] - b);
	}
	return retvect;
}
static vector<double> operator*(vector<double> a, vector<double> b)
{
	vector<double> retvect;
	for (int i = 0; i < a.size(); i++)
	{
		retvect.push_back(a[i] * b[i]);
	}
	return retvect;
}
//--
