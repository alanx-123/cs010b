#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Rational Class declaration
class Rational
{
private:
   int numerator;
   int denominator;

public:
   Rational();
   explicit Rational(int num);
   Rational(int numerator, int denominator);
   Rational add(const Rational &num) const;
   Rational subtract(const Rational &num) const;
   Rational multiply(const Rational &num) const;
   Rational divide(const Rational &num) const;
   void simplify();
   void display() const;
   int gcd(int a, int b)const
   {
      while (a != b){
         if (a > b){
            a -= b;
         }
         else{
            b -= a;
         }
      }
      return a;
   }
};

Rational::Rational()
{
   numerator = 0;
   denominator = 1;
}
Rational::Rational(int num)
{
   numerator = num;
   denominator = 1;
}
Rational::Rational(int numerator, int denominator)
{
   this->numerator = numerator;
   this->denominator = denominator;
}
Rational Rational::add(const Rational &num) const
{
   Rational sum;

   sum.numerator = ((numerator * num.denominator) + (num.numerator * denominator));
   sum.denominator = (denominator * num.denominator);

   return sum;
}
Rational Rational::subtract(const Rational &num) const
{
   Rational difference;

   difference.numerator = ((numerator * num.denominator) - (num.numerator * denominator));
   difference.denominator = denominator * num.denominator;

   return difference;
}
Rational Rational::multiply(const Rational &num) const
{
   Rational product;

   product.numerator = numerator * num.numerator;
   product.denominator = denominator * num.denominator;

   return product;
}
Rational Rational::divide(const Rational &num) const
{
   Rational quotient;

   quotient.numerator = numerator * num.denominator;
   quotient.denominator = num.numerator * denominator;

   return quotient;
}
void Rational::simplify()
{
   int gcd = gcd(numerator,denominator);
   numerator /= gcd;
   denominator /= gcd;
}

// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational &, const Rational &);

int main()
{
   Rational A, B, result;
   char choice;

   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;

   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;

   cout << "Enter Operation:" << endl
        << "a - Addition (A + B)" << endl
        << "s - Subtraction (A - B)" << endl
        << "m - Multiplication (A * B)" << endl
        << "d - Division (A / B)" << endl
        << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 'a')
   {
      result = A.add(B);
      displayResult("+", A, B, result);
   }
   else if (choice == 's')
   {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   }
   else if (choice == 'm')
   {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   }
   else if (choice == 'd')
   {
      result = A.divide(B);
      displayResult("/", A, B, result);
   }
   else if (choice == 'y')
   {
      A.simplify();
      A.display();
   }
   else
   {
      cout << "Unknown Operation";
   }
   cout << endl;

   return 0;
}

Rational getRational()
{
   int choice;
   int numer, denom;

   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
        << "2 - 2 parameters (numerator & denominator)" << endl
        << "1 - 1 parameter (numerator)" << endl
        << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 2)
   {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   }
   else if (choice == 1)
   {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   }
   else
   {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational &rhs, const Rational &result)
{
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}
