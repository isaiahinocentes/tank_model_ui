#pragma once
#include <string>

//Use Forms and UI functions
using namespace System;
using namespace System::Windows::Forms;
using namespace std;

#define OEF_RMSE "Root Squared Mean Error, RMSE"
#define OEF_R "Correlation Coefficient, R"
#define OEF_MAE "Mean Absolute Error, MAE"

static string oef_rmse = OEF_RMSE;
static string oef_mae = OEF_MAE;
static string oef_r = OEF_R;


public class MyClass
{
public:
	MyClass();
	~MyClass();

	void runTest(){

	};

private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}