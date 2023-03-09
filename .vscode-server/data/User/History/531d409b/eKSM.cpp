#include <iostream>
#include <string>

using namespace std;

class Date
{
private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

public:
   // creates the date January 1st, 2000.
   Date();
   /* parameterized constructor: month number, day, year
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message:

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned month, unsigned day, unsigned year);

   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message:

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).

       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor.

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);

   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012".
      Does not output a newline at the end.
   */
   void printNumeric() const;

   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january.
      Does not output a newline at the end.
   */
   void printAlpha() const;

private:
   /* Returns true if the year passed in is a leap year, otherwise returns false.
    */
   bool isLeap(unsigned y) const;

   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};

Date::Date(){
   this->month = 1;
   this->day = 1;
   this->year = 2000;
}

Date::Date(unsigned m, unsigned d, unsigned y)
{
   this->month = m;
   this->day = d;
   this->year = y;

   if (m > 12)
   {
      this->month = 12;
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year  << "."<< endl;
   }
   else if (m < 1){
      this->month = 0;
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year  << "."<< endl;
   }
   if (d > daysPerMonth(m, y))
   {
      this->day = daysPerMonth(m, y);
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }
   else if (d < 1){
      this->day = 1;
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }
}
Date::Date(const string &mn, unsigned d, unsigned y)
{
   unsigned monthNum = number(mn);


   if (monthNum < 1){
      monthNum = 1;
   }
   else if (monthNum > 12)
   {
      MonthNum = 12;
   }

   if (d > daysPerMonth(monthNum, y))
   {
      this->day = daysPerMonth(monthNum, y);
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << endl;
   }
   if (mn != name(monthNum))
   {
      cout << "Invalid month name: the Date was set to 1/1/2000" << endl;
      this->month = 1;
      this->day = 1;
      this->year = 2000;
   }
   else
   {
      this->month = monthNum;
      this->day = d;
      this->year = y;
   }

   if (d < 1){
      this -> day = 1;
   }
   
}
bool Date::isLeap(unsigned y) const
{
   bool leapYear = true;
   if (y % 4 == 0)
   {
      if (y % 100 == 0)
      {
         if (y % 400 != 0)
         {
            leapYear = false;
         }
      }
   }
   else
   {
      leapYear = false;
   }
   return leapYear;
}
unsigned Date::daysPerMonth(unsigned m, unsigned y) const
{
   unsigned numDays = 1;
   switch (m)
   {
   case 1:
      numDays = 31;
      break;
   case 2:
      if (isLeap(y) == true)
      {
         numDays = 29;
      }
      else 
      {
         numDays = 28;
      }
      break;
   case 3:
      numDays = 31;
      break;
   case 4:
      numDays = 30;
      break;
   case 5:
      numDays = 31;
      break;
   case 6:
      numDays = 30;
      break;
   case 7:
      numDays = 31;
      break;
   case 8:
      numDays = 31;
      break;
   case 9:
      numDays = 30;
      break;
   case 10:
      numDays = 31;
      break;
   case 11:
      numDays = 30;
      break;
   case 12:
      numDays = 31;
      break;
   }
   return numDays;
}
void Date::printNumeric() const
{
   cout << month << "/" << day << "/" << year;
}
void Date::printAlpha() const
{
   string monthText;

   monthText = name(month);
   cout << monthText << " " << day << ", " << year;
}
unsigned Date::number(const string &mn) const
{
   unsigned monthNum = ;

   if (mn == "January" || mn == "january")
   {
      monthNum = 1;
   }
   else if (mn == "February" || mn == "february")
   {
      monthNum = 2;
   }
   else if (mn == "March" || mn == "march")
   {
      monthNum = 3;
   }
   else if (mn == "April" || mn == "april")
   {
      monthNum = 4;
   }
   else if (mn == "May" || mn == "may")
   {
      monthNum = 5;
   }
   else if (mn == "June" || mn == "june")
   {
      monthNum = 6;
   }
   else if (mn == "July" || mn == "july")
   {
      monthNum = 7;
   }
   else if (mn == "August" || mn == "august")
   {
      monthNum = 8;
   }
   else if (mn == "September" || mn == "september")
   {
      monthNum = 9;
   }
   else if (mn == "October" || mn == "october")
   {
      monthNum = 10;
   }
   else if (mn == "November" || mn == "november")
   {
      monthNum = 11;
   }
   else if (mn == "December" || mn == "december")
   {
      monthNum = 12;
   }

   return monthNum;
}
string Date::name(unsigned m) const
{
   string monthText;
   switch (m)
   {
   case 1:
      monthText = "January";
      break;
   case 2:
      monthText = "February";
      break;
   case 3:
      monthText = "March";
      break;
   case 4:
      monthText = "April";
      break;
   case 5:
      monthText = "May";
      break;
   case 6:
      monthText = "June";
      break;
   case 7:
      monthText = "July";
      break;
   case 8:
      monthText = "August";
      break;
   case 9:
      monthText = "September";
      break;
   case 10:
      monthText = "October";
      break;
   case 11:
      monthText = "November";
      break;
   case 12:
      monthText = "December";
      break;
   }

   return monthText;
}

// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main()
{

   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;

   return 0;
}

Date getDate()
{
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
        << "1 - Month Number" << endl
        << "2 - Month Name" << endl
        << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1)
   {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   }
   else if (choice == 2)
   {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   }
   else
   {
      return Date();
   }
}
