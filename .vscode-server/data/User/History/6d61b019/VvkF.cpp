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

    if (!inFS.eof() || flightPathAngles.size() == ){
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
        if (flightPathAngles[i] == angle)
        {
            return coeffOfLifts[i];
        }
        if (flightPathAngles[i + 1] > angle)
        {
            indexOfA = i + 1;
            indexOfC = i;
            break;
        }
    }

    double linearInterpolation = coeffOfLifts[indexOfA] + ((angle - flightPathAngles[indexOfA]) / (flightPathAngles[indexOfC] - flightPathAngles[indexOfA]) * (coeffOfLifts[indexOfC] - coeffOfLifts[indexOfA]));

    return linearInterpolation;
}
bool isOrdered(const vector<double> &nums)
{
    for (unsigned int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < nums[i - 1])
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
            if (flightPathAngles[j] < flightPathAngles[i])
            {
                double temp = flightPathAngles[j];
                flightPathAngles[j] = flightPathAngles[i];
                flightPathAngles[i] = temp;

                temp = coeffOfLifts[j];
                coeffOfLifts[j] = coeffOfLifts[i];
                coeffOfLifts[i] = temp;
            }
        }
    }
}
void inputFlightPathAngle(double angle, const vector<double> &flightPathAngles, const vector<double> &coeffOfLifts)
{ // for the sake of making main cleaner
    cout << "Input a flight-path angle: " << endl;
    cin >> angle;

    if (angle >= flightPathAngles[0] && angle <= flightPathAngles[flightPathAngles.size() - 1])
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

        if (angle >= flightPathAngles[0] && angle <= flightPathAngles[flightPathAngles.size() - 1])
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
