#pragma once
#include <fstream>	//filestream
#include <iostream>	//cout / cin
#include <string>	//for: cout << <string>
#include <string.h>	//String Manipulation
#include <iomanip>	//Showing Precisions
#include "Model.h"	//Tank Model Variables	
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
	
	//Get Tank Height
	file >> str;
	TA = atof(str.c_str());

	//Read the P and Qo from the file
	while (!file.eof()) {
		//Read Precipitation
		file >> str;
		vPrecipitation.push_back(atof(str.c_str()));

		//Read QObserved
		file >> str;
		double qo = atof(str.c_str());
		//Convert QObserved to mm³/day
		qo = lps2mmd(qo);
		vQObserved.push_back(qo);
		
		row++;
	}

	//Get the Averages of QO and Precipitaion | for chtng
	QO_ave = ave_QO();
	Prec_ave = ave_Prec();
}