// Assign10-SalesFunctions.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

string	nameFormat(string, string);
double	orderAmount(double, int);
double	salesTaxAmount(double, double);
void	displayOutput(string, double, double);

int main()
{
	const	double	SALES_TAX_RATE = 0.09265;

	string	lastName;
	string	firstName;
	int		qty;
	double	itemPrice;

	string	nameString;
	double	orderTotal;
	double	salesTax;
	ifstream	salesTrans;

	salesTrans.open("SalesTransactions.txt");

	if (!salesTrans)
	{
		cout << endl << "Error opening Sales Transactions file." << endl << endl;
		system("pause");
		return -1;
	}

	salesTrans >> lastName;

	while (!salesTrans.eof())
	{
		salesTrans >> firstName >> qty >> itemPrice;

		nameString = nameFormat(lastName, firstName);
		orderTotal = orderAmount(itemPrice, qty);
		salesTax = salesTaxAmount(orderTotal, SALES_TAX_RATE);
		displayOutput(nameString, orderTotal, salesTax);

		salesTrans >> lastName;
	}

	salesTrans.close();

	cout << endl << endl;
	system("pause");
    return 0;
}

string	nameFormat(string lastName, string firstName)
{
	string nameStr;
	nameStr = lastName + ", " + firstName;
	return nameStr;
}
double	orderAmount(double itemPrice, int qty)
{
	double amt;
	amt = itemPrice * qty;
	return amt;
}
double	salesTaxAmount(double orderTotal, double SALES_TAX_RATE)
{
	double tax;
	tax = orderTotal * SALES_TAX_RATE;
	return tax;
}
void	displayOutput(string nameString, double orderTotal, double salesTax)
{
	cout << fixed << setprecision(2);
	cout << endl << left << setw(25) << nameString << "  " << right << setw(9) << orderTotal << "  " 
		 << right << setw(8) << salesTax;
}

