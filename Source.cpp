/*************************************************
			03 Calculate age in seconds
	- This program for : Calculate age.
	- Author : Ibrahim Mohamed Abdul-Meged.
		 	 : facebook.com/Ibrahiim.Pasha
			 : github.com/Ibrahiim-Pasha
	- Date : 27/9/2016 - 2:51 AM

*************************************************/

#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>
using namespace std;

// Creating functions
void welcome();
void start();
void getDateNow();
void big(string anyBig);
void differenceDate_Draw();
void again();
void wrongChoice();
void exit();

// Creating Variables
int nowYear, nowMonth, nowDay,
year, month, day,
differenceYears, differenceMonth, differenceDays,
yearsToMonth, monthToDays, daysToWeeks, daysToHours, hoursToMin, MinToSec;


int main()
{
	welcome();

	system("PAUSE");
	return 0;
}

void welcome() // Start of the program
{
	char startAnswer;
	cout << "\t\tHello in your program to calculate your age." << endl << endl
		<< "\n\t\tDo you want to continue [Y/N]? : ";

	cin >> startAnswer;
	if (startAnswer == 'Y' || startAnswer == 'y')
	{
		start();
	}
	else if (startAnswer == 'N' || startAnswer == 'n')
	{
		exit();
	}
	else
	{
		wrongChoice();
		system("CLS");
		welcome();
	}
}

void start()
{
	getDateNow();

	cout << "\nPlease enter your birthday" << endl;
	cout << "Your day : ";
	cin >> day;

	if (day > 31 || day == 0 || day < 0)
	{
		cout << "This error does not exist in the month Day "<< day << "!\n\n";
		again();
	}
	else
	{
		cout << "Your month : ";
		cin >> month;
		if (month > 12 || month == 0 || month < 0)
		{
			cout << "This error does not exist in the number of months No. " << month << "!\n\n";
			again();
		}
		else if (month == 2)
		{
			if (day > 29)
			{
				cout << "February does not contain a " << day << "-day\n\n";
				again();
			}
			else
			{
				goto start;
			}
		}
		else
		{
			start:
			cout << "Your year : ";
			cin >> year;

			if (year > nowYear)
			{
				cout << "You have not been born yet!\n\n";
				again();
			}
			else
			{
				if (day > nowDay && month > nowMonth)
				{
					big("day and month");
				}
				else if (day > nowDay)
				{
					big("day");
				}
				else if (month > nowMonth)
				{
					big("month");
				}
				else
				{
					differenceDate_Draw();
				}
			}
		}
	}
}
void getDateNow()
{
	struct tm tm;
	time_t tt = time(NULL);
	localtime_s(&tm, &tt);

	nowYear = tm.tm_year + 1900; // Years are counted from 1900.
	nowMonth = tm.tm_mon + 1; // month are counted from 0.
	nowDay = tm.tm_mday;
}

void differenceDate_Draw()
{
	int leab = 0;
	differenceYears = nowYear - year;
	differenceMonth = nowMonth - month;
	differenceDays = nowDay - day;

	yearsToMonth = (differenceYears * 12) + differenceMonth;
	monthToDays = (yearsToMonth * 30.4368499) + differenceDays;
	daysToWeeks = monthToDays * 0.142857143;
	daysToHours = monthToDays * 24;
	hoursToMin = daysToHours * 60;
	MinToSec = hoursToMin * 60;

	for (int i = year; i <= nowYear; i++)
	{
		if (i % 4 == 0 || i % 400 == 0)
		{
			leab++;
		}
	}

	if (differenceDays == 0)
	{
		cout << "\nYou live in " << differenceYears << " years, "
			<< differenceMonth << " months." << endl << endl;
	}
	else if (differenceMonth == 0)
	{
		cout << "\nYou live in " << differenceYears << " years, "
			<< "and " << differenceDays << " days." << endl << endl;
	}

	else if (differenceYears == 0)
	{
		cout << "\nYou live in "
			<< differenceMonth << " months and " << differenceDays << " days." << endl << endl;
	}
	else if (differenceDays == 0 && differenceMonth == 0)
	{
		cout << "\nYou live in " << differenceYears << " years." << endl << endl;
	}
	else if (differenceMonth == 0 && differenceYears == 0)
	{
		cout << "\nYou live in " << differenceDays << " days." << endl << endl;
	}
	else if (differenceDays == 0 && differenceYears == 0)
	{
		cout << "\nYou live in " << differenceMonth << " months." << endl << endl;
	}
	else
	{
		cout << "\nYou live in " << differenceYears << " years, "
			<< differenceMonth << " months and " << differenceDays << " days." << endl << endl;
	}


	cout << "Or : " << "You live in " << yearsToMonth << " months and " << differenceDays << " days.\n" << endl
		<< "Or : " << "You live in " << daysToWeeks << " weeks.\n" << endl
		<< "Or : " << "You live in " << monthToDays << " days.\n" << endl
		<< "Or : " << "You live in " << daysToHours << " hours.\n" << endl
		<< "Or : " << "You live in " << hoursToMin << " minutes.\n" << endl
		<< "Or : " << "You live in " << MinToSec << " seconds." << endl << endl
	    << "The number of leap years in your life is " << leab << ".\n" << endl;
	again();
}


void big(string anyBig)
{
	if (anyBig == "day")
	{
		switch (nowMonth)
		{
		case 4 || 6 || 9 || 11:
			
			nowMonth = nowMonth - 1;
			nowDay = nowDay + 31;
			differenceDate_Draw();
			break;
		case 2:
			if (nowYear % 4 == 0 || nowYear % 400 == 0)
			{
				nowMonth = nowMonth - 1;
				nowDay = nowDay + 29;
				differenceDate_Draw();
			}
			else
			{
				nowMonth = nowMonth - 1;
				nowDay = nowDay + 28;
				differenceDate_Draw();
			}
			break;
		default:
			nowMonth = nowMonth - 1;
			nowDay = nowDay + 30;
			differenceDate_Draw();
			break;
		}
		
	}
	else if(anyBig == "month")
	{
		nowYear = nowYear - 1;
		nowMonth = nowMonth + 12;
		differenceDate_Draw();
	}
	else if (anyBig == "day and month")
	{

		switch (nowMonth)
		{
		case 4 || 6 || 9 || 11:
			
			nowMonth = nowMonth - 1;
			nowDay = nowDay + 31;
			
			nowYear = nowYear - 1;
			nowMonth = nowMonth + 12;

			differenceDate_Draw();
			break;
		case 2:
			if (nowYear % 4 == 0 || nowYear % 400 == 0)
			{
				nowMonth = nowMonth - 1;
				nowDay = nowDay + 29;
				differenceDate_Draw();
			}
			else
			{
				nowMonth = nowMonth - 1;
				nowDay = nowDay + 28;
				differenceDate_Draw();
			}
			break;
		default:
			nowMonth = nowMonth - 1;
			nowDay = nowDay + 30;

			nowYear = nowYear - 1;
			nowMonth = nowMonth + 12;

			differenceDate_Draw();
			break;
		}

	}
}

void again()
{
	char againAnswer;
	cout << "Again[Y/N]? : ";
	cin >> againAnswer;
	if (againAnswer == 'Y' || againAnswer == 'y')
	{
		system("CLS");
		start();
	}
	else if (againAnswer == 'N' || againAnswer == 'n')
	{
		exit();
	}
	else
	{
		wrongChoice();
		again();
	}
}


void wrongChoice()
{
	cout << "\nWrong choice! ..";
	Sleep(2000);
	system("CLS");
}

void exit()
{
	cout << endl << "Goodbye! .. " << endl;
	Sleep(2000);
	exit(0);
}