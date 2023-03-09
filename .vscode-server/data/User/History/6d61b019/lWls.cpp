#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void readData(const string &windTunnelFile, vector<double> &flightPathAngles, vector<double> &coeffOfLifts);
double interpolation(double angle, const vector<double> &windTunnelFile, const vector<double> &coeffOfLifts);
bool isOrdered(const vector<double> &nums);
void reorder(vector<double> &flightPathAngles, vector<double> &coeffOfLifts);
void printVector(const vector<double> &nums);
void inputFlightPathAngle(double angle, const vector<double> &flightPathAngles, const vector<double> &coeffOfLifts);

int main(int argc, char *argv[])
{
    string windTunnelFile = argv[1];
    vector<double> flightPathAngles;
    vector<double> coeffOfLifts;
    double angle = 0;

    readData(windTunnelFile, flightPathAngles, coeffOfLifts);
    reorder(flightPathAngles, coeffOfLifts);
    inputFlightPathAngle(angle, flightPathAngles, coeffOfLifts);

    return 0;
}
void readData(const string &windTunnelFile, vector<double> &flightPathAngles, vector<double> &coeffOfLifts)
{
    ifstream inFS;
    inFS.open(windTunnelFile);

    if (!inFS.is_open())
    {
        cout << "Error opening " << windTunnelFile << endl;
        exit(1);
    }

    double flightPathAngle;
    double coeffOfLift;

    while (inFS >> flightPathAngle && inFS >> coeffOfLift)
    {
        flightPathAngles.push_back(flightPathAngle);
        coeffOfLifts.push_back(coeffOfLift);
    }
    if (!inFS.eof() || flightPathAngles.size() == 0){
        cout << "Error while reading file, exiting" << endl;
        exit(1);
    }
}
double interpolation(double angle, const vector<double> &flightPathAngles, const vector<double> &coeffOfLifts)
{
    int indexOfA;
    int indexOfC;

    for (unsigned int i = 0; i < flightPathAngles.size(); i++)
    {
        if (flightPathAngles.at(i) == angle)
        {
            return coeffOfLifts.at(i);
        }
        if (flightPathAngles.at(i+1) > angle)
        {
            indexOfA = i + 1;
            indexOfC = i;
            break;
        }
    }

    double linearInterpolation = coeffOfLifts.at(indexOfA) + ((angle - flightPathAngles.at(indexOfA)) / (flightPathAngles.at(indexOfC) - flightPathAngles.at(indexOfA)) * (coeffOfLifts.at(indexOfC) - coeffOfLifts.at(indexOfA)));

    return linearInterpolation;
}
bool isOrdered(const vector<double> &nums)
{
    for (unsigned int i = 1; i < nums.size(); i++)
    {
        if (nums.at(i) < nums.at(i - 1))
        {
            return false;
        }
    }
    return true;
}
void reorder(vector<double> &flightPathAngles, vector<double> &coeffOfLifts)
{ // ascending order
    if (flightPathAngles.size() == 0)
    {
        return;
    }
    for (unsigned int i = 0; i < flightPathAngles.size() - 1; i++)
    {
        for (unsigned int j = i + 1; j < flightPathAngles.size(); j++)
        {
            if (flightPathAngles.at(i) < flightPathAngles.at(i))
            {
                double temp = flightPathAngles.at(j);
                flightPathAngles.at(j) = flightPathAngles.at(i);
                flightPathAngles.at(i) = temp;

                temp = coeffOfLifts.at(j);
                coeffOfLifts.at(j) = coeffOfLifts.at(i);
                coeffOfLifts.at(i) = temp;
            }
        }
    }
}
void inputFlightPathAngle(double angle, const vector<double> &flightPathAngles, const vector<double> &coeffOfLifts)
{ // for the sake of making main cleaner
    cout << "Input a flight-path angle: " << endl;
    cin >> angle;

    if (angle >= flightPathAngles.at(0) && angle <= flightPathAngles.at(flightPathAngles.size() - 1))
    {
        cout << "Coefficient of lift: " << interpolation(angle, flightPathAngles, coeffOfLifts);
    }

    string choice;

    cout << "Would you like to input another flight-path angle?" << endl;
    cout << endl;
    cin >> choice;

    while (choice == "Yes")
    {
        cout << "Input a flight-path angle" << endl;
        cout << endl;
        cin >> angle;

        if (angle >= flightPathAngles.at(0) && angle <= flightPathAngles.at(flightPathAngles.size() - 1))
        {
            cout << "Coefficient of lift: " << interpolation(angle, flightPathAngles, coeffOfLifts) << endl;
        }
        else{
            cout << "Error: entered flight-path angle is out of range. Exiting." << endl;
            exit(1);
        }
        cout << "Would you like to input another flight-path angle?" << endl;
        cout << endl;
        cin >> choice;
    }
}
