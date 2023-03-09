#include "Distance.h"
#include <iostream>

using namespace std;

/*
 private:
 Used by the 2 parameterized constructors to convert any negative values to positive and
        inches >= 12 to the appropriate number of feet and inches.

   void init();


   unsigned feet;
   double inches;

*/

/* Constructs a default Distance of 0 (0 feet and 0.0 inches)
 */
Distance::Distance()
{
    feet = 0;
    inches = 0.0;
}

/* Constructs a distance of ft feet and in inches,
     unless in >= 12, in which case the values of feet and inches
     are adjusted accordingly. A Distance will always be positive.
     Just convert negative inches to positive. Don't subtract from feet.
*/
Distance::Distance(unsigned ft, double in)
{
    if (in < 12)
    {
        feet = ft;
        inches = in;
    }
    else
    {
        feet = ft;
        inches = in;
        init();
    }
}

/* Constructs a distance of 0 ft and in inches,
     unless in >= 12, in which case the values of feet and inches
     are adjusted accordingly. A Distance will always be positive.
     Just convert negative inches to positive. Don't subtract from feet.
*/
Distance::Distance(double in)
{
    if (in < 12)
    {
        feet = 0;
        inches = in;
    }
    else
    {
        feet = ft;
        inches = in;
        init();
    }
}

/* Returns just the feet portion of the Distance
 */
Distance::getFeet() const
{
    return feet;
}

/* Returns just the inches portion of the Distance
 */
Distance::getInches() const
{
    return inches;
}

/* Returns the entire distance as the equivalent amount of inches.
     (e.g., 4 feet 3.5 inches would be returned as 51.5 inches)
*/
Distance::distanceInInches() const
{
    double totalInches;

    totalInches = (feet * 12.0) + inches;

    return totalInches;
}

/* Returns the entire distance as the equivalent amount of feet.
     (e.g., 3 feet 6 inches would be returned as 3.5 feet)
*/
Distance::distanceInFeet() const
{
    double totalFeet;

    totalFeet = feet + (inches / 12.0);

    return totalFeet;
}

/* Returns the entire distance as the equivalent amount of meters.
     1 inch equals 0.0254 meters.
     (e.g., 2 feet 8.12 inches would be returned as 0.815848 meters)
*/
Distance::distanceInMeters() const
{
    double totalMeters;

    totalMeters = (feet * 3.28084) + (inches * 0.0254);

    return totalMeters;
}

const Distance operator+(const Distance &rhs) const
{
    unsigned feetSum = feet + rhs.feet;
    double inchSum = inches + rhs.inches;

    return Distance(feetSum, inchSum);
}

/* Returns the difference between 2 Distances.
 */
const Distance operator-(const Distance &rhs) const
{
    unsigned feetDiff = feet - rhs.feet;
    double inchDiff = inches - rhs.inches;

    return Distance(feetDiff, inchDiff);
}

/* Outputs to the stream out the Distance in the format:
     feet' inches'' (i.e. 3' 3.41'')
*/
ostream &operator<<(ostream &out, const Distance &rhs)
{
    out << rhs.feet << "' " << rhs.inches << "'";
    return out;
}