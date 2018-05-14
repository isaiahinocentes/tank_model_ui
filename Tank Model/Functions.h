#pragma once
#include <fstream>	//filestream
#include <iostream>	//cout / cin
#include <string>	//for: cout << <string>
#include <string.h>	//String Manipulation
#include <iomanip>	//Showing Precisions
#include "Model.h"	//Tank Model Variables	
#include "form_menu.h"
#include "Compute.h" //Computations and Conversions

using namespace std;

//Read file with the filepath and set Values for Tank Model Variables
static void read_file_init(string path) {
	ifstream file(path);
	if (file.fail()) {
		//Show dialog that file Can't be opened
	}

	int row = 0;
	string str;

	//Set the Drainage Area to mm units
	file >> str;
	DA_km = atof(str.c_str());
	//Conver km² to mm²
	DA_mm = km2mm(DA_km);

	//Read the P and Qo from the file
	while (!file.eof()) {
		//Read Precipitation
		file >> str;
		vPrecipitation.push_back(atof(str.c_str()));

		//Read QObserved
		file >> str;
		vQObserved.push_back(lps2mmd(atof(str.c_str())));
		
		row++;
	}

	//Get the Averages of QO and Precipitaion | for chtng
	QO_ave = ave_QO();
	Prec_ave = ave_Prec();
}
static boolean file_tank_config(string path) {

	try
	{
		ifstream file(path);
		if (file.fail()) {

		}

		string str;
		file >> str;
		YA1 = atof(str.c_str());
		file >> str;
		YA2 = atof(str.c_str());
		file >> str;
		YB1 = atof(str.c_str());
		file >> str;
		YC1 = atof(str.c_str());
		file >> str;
		YD1 = atof(str.c_str());

		TankHeight = YA1 + YA2 + YB1 + YC1 + YD1;
		
		return true;
	}
	catch (const std::exception&)
	{

	}
	return false;
}

static boolean read_prec(string path) {
	
	try
	{
		ifstream file(path);
		if (file.fail()) {

		}

		int row = 0;
		string str;

		vPrecipitation.clear();
		
		//read Ps
		while (!file.eof()) {
			//Read Precipitation
			file >> str;
			vPrecipitation.push_back(atof(str.c_str()));
		}
		return true;
	}
	catch (const std::exception&)
	{
		
	}
	return false;
}

static boolean save_file(int method) {
	//cout << endl << "_______ Saving File ________" << endl;
	//Change this with current time
	srand(time(NULL));

	string filepath = "C:\\Users\\isaia\\Desktop\\model.txt";
	//strcat(filepath, filepath);
	//filepath += filepath + ".txt";

	//cout << "Filepath: " << filepath << endl;

	ofstream file(filepath);

	if (file.good()) {

		//cout << "File is Good, saving Values..." << endl;

		file << setprecision(10);

		//Save Tank Height
		//file << "TankHeight:" << TankHeight << endl;

		//Save Ys = Height of Orifices
		/*file << "YA1:" << YA1 << endl;
		file << "YA2:" << YA2 << endl;
		file << "YB1:" << YB1 << endl;
		file << "YC1:" << YC1 << endl;
		file << "YD1:" << YD1 << endl;*/
		file << YA1 << endl;
		file << YA2 << endl;
		file << YB1 << endl;
		file << YC1 << endl;
		file << YD1 << endl;

		if (method == 1) {
			//file << "Root Squared Mean Error (RMSE): " << OEFv << endl;
		}
		else if (method == 2) {
			//Coeff
			//file << "Coefficient Correlation (R): " << OEFv << endl;
		}
		else if (method == 3) {
			//file << "Mean Absolute Error (MAE): " << OEFv << endl;
		}
		//Save Qs
		/*file << "QA1:" << QA1 << endl;
		file << "QA2:" << QA2 << endl;
		file << "QA0:" << QA0 << endl;

		file << "QB1:" << QB1 << endl;
		file << "QB0:" << QB0 << endl;

		file << "QC1:" << QC1 << endl;
		file << "QC0:" << QC0 << endl;

		file << "QD1:" << QD1 << endl;*/


		//cout << "file Saved!.." << endl;
		return true;
	}
	else {
		//cout << "File Can't be created..." << endl;
		return false;
	}
}