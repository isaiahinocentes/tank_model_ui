#pragma once
#include "Model.h" //Tank Model Variables
#include <iomanip> //For output formatting

//Conversions
//l/ps to mm³/day
static double lps2mmd(double lps) {
	return (lps * 86400000000) / DA_mm;
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

//Multipliers for QC
static void compute_multipliers() {
	QA1 >= YA1 ? nA1 = 1 : nA1 = 0;
	QA2 >= YA2 ? nA2 = 1 : nA2 = 0;
	QB1 >= YB1 ? nB1 = 1 : nB1 = 0;
	QC1 >= YC1 ? nC1 = 1 : nC1 = 0;
	QD1 >= YD1 ? nD1 = 1 : nD1 = 0;
}

//Compute QC
static void compute(System::Windows::Forms::TextBox^ Log) {
	
	//File output for QC
	string optQc = "C:\\Users\\isaia\\Desktop\\optQc.txt";
	ofstream fQc(optQc);
	
	//File output for QO
	string optQo = "C:\\Users\\isaia\\Desktop\\optQo.txt";
	ofstream fQo(optQo);
	
	if (fQc.bad() || fQo.bad()) {
		return;
	}

	fQc << setprecision(10);
	fQo << setprecision(10);

	
	double tmp_QC = 0;

	for (int i = 0; i < vQObserved.size(); i++){

		//Initialize QS using QO
		init_Qs(vQObserved.at(i));

		//Calculate water level on tanks
		hA = c_hA(vPrecipitation.at(i), Evap, QA1, QA2, QA0);  //This will be - if P = 0
		hB = c_hB(QA0, QB1, QB0);
		hC = c_hC(QB0, QC1, QC0);
		hD = c_hD(QC0, QD1);

		compute_multipliers();

		tmp_QC =
			(QA1 * nA1) +
			(QA2 * nA2) +
			(QB1 * nB1) +
			(QC1 * nC1) +
			(QD1 * nD1);

		Log->Text += tmp_QC + "\r\n";

		//Save to QC
		vQCalculated.push_back(tmp_QC);

		//Save to file QC
		fQc << tmp_QC << endl;
		//Save to file QO
		fQo << vQObserved.at(i) << endl;
	}

	//Close file streams
	fQc.close();
	fQo.close();
	//
	//cout << "Finished Copmutations..." << endl << endl;
}

//For Predictions
static double predictRainfall(double prec) {
	
	double QC = 0;

	if (prec < YA2) {
		return YA2 - prec;
	} else {
		prec -= YA2;
		QC += prec;

		if (prec < YB1) {
			QC += YB1 - prec;
		} else {
			prec -= YC1;
			QC += prec;

			if (prec < YC1) {
				QC += YC1 - prec;
			} else {
				prec -= YD1;
				QC += prec;
			}
		}
	}

	return QC;
	/*
	if (prec == 0) {
		QC += 0;
	}
	else {
		QC += YA1;
		prec -= YA2; //-9
		if (prec <= 0) {
			QC += YA2;
			//QC += YA2 - prec;
		}
		else {
			QC += YB1;
			prec -= YB1;
			if (prec <= 0) {
				QC += YB1 - prec;
			}
			else {
				QC += YC1;
				prec -= YC1;
				if (prec <= 0) {
					QC += YC1 - prec;
				}
				else {
					QC += YD1;
					prec -= YD1;
					if (prec <= 0) {
						QC += YD1 - prec;
					}
				}
			}
		}
	}
	return QC; */

	//QA1
	/*if (YA1 > QA1) {
		QA1 = YA1;
	} else {
		prec -= YA1;
		QA1 = prec;
		//QA2
		if (YA2 > QA1) {
			QA2 = YA2;
			return QA1 + QA2;
		} else {
			QA2 = QA1 - YA2;
			//QB1
			if (YB1 > QB1) {
				QB1 = YB1;
				return QA1 + QA2 + QB1;
			} else {
				QB1 = QA2 - YB1;
				//QC1
				if (YC1 > QC1) {
					QC1 = YC1;
					return QA1 + QA2 + QB1 + QC1;
				} else {
					QC1 = QB1 - YC1;
					//QD1
					if (YD1 > QD1) { QD1 = YD1; } else { QD1 = QC1 - YD1; }
					return QA1 + QA2 + QB1 + QC1 + QD1;
				}
			}
		}
	}
	return QA1;*/
}
