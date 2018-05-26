#pragma once
#include <fstream>	//filestream
#include <iostream>	//cout / cin
#include <string>	//for: cout << <string>
#include <string.h>	//String Manipulation
#include <iomanip>	//Showing Precisions
#include "Model.h"	//Tank Model Variables	
#include "form_menu.h"
#include "Compute.h" //Computations and Conversions
//For removing string characters
#include <iterator>
#include <algorithm>

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
		remove_copy(str.begin(), str.end(), back_inserter(str), ',');
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

		file >> str; YA1 = atof(str.c_str());
		file >> str; YA2 = atof(str.c_str());
		file >> str; YB1 = atof(str.c_str());
		file >> str; YC1 = atof(str.c_str());
		file >> str; YD1 = atof(str.c_str());
		//Skip the text part
		file >> str; 
		file >> str;
		//
		file >> str; A0 = atof(str.c_str());
		file >> str; A1 = atof(str.c_str());
		file >> str; A2 = atof(str.c_str());
		file >> str; B0 = atof(str.c_str());
		file >> str; B1 = atof(str.c_str());
		file >> str; C0 = atof(str.c_str());
		file >> str; C1 = atof(str.c_str());
		file >> str; D1 = atof(str.c_str());
		
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
			return false;
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
	
	ofstream file("..\\tank_optimized.txt");

	if (file.good()) {
		file << setprecision(10);
		file << YA1 << endl;
		file << YA2 << endl;
		file << YB1 << endl;
		file << YC1 << endl;
		file << YD1 << endl;
		file << "OUTLET PARAMETERS:" << endl;
		file << A0 << endl;
		file << A1 << endl;
		file << A2 << endl;
		file << B0 << endl;
		file << B1 << endl;
		file << C0 << endl;
		file << C1 << endl;
		file << D1 << endl;
		return true;
	}

	return false;
}