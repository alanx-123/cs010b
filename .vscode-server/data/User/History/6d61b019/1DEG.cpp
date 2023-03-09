#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void readData(const string &windTunnelFile, vector<double> &flightPathAngles, vector<double> &coeffLifts);
double interpolation(double angle, const vector<double> &windTunnelFile, const vector<double> &coeffLifts);
bool isOrdered(const vector<double> &nums);
void reorder(vector<double> &flightPathAngles, vector<double> &coeffLifts);
void printVector(const vector<double> &nums);
void inputFlightPathAngle(double angle, const vector<double> &flightPathAngles, const vector<double> &coeffLifts);

int main(int argc, char *argv[])
{
    string windTunnelFile = argv[1]; 
    vector<double> flightPathAngles;
    vector<double> coeffLifts;
    double angle = 0;

    readData(windTunnelFile, flightPathAngles, coeffLifts);

    reorder(flightPathAngles, coeffLifts);

    inputFlightPathAngle(angle, flightPathAngles, coeffLifts);

    return 0;
}
void readData(const string &windTunnelFile, vector<double> &flightPathAngles, vector<double> &coeffLifts)
{
    ifstream inFS;
    inFS.open(windTunnelFile);

    if (!inFS.is_open())
    {
        cout << "Error opening " << windTunnelFile << endl;
        exit(1);
    }

    double flightAngle;
    double coeffLift;

    while (inFS >> flightAngle && inFS >> coeffLift)
    {
        flightPathAngles.push_back(flightAngle);
        coeffLifts.push_back(coeffLift);
    }
}
double interpolation(double angle, const vector<double> &flightPathAngles, const vector<double> &coeffLifts)
{
    int indexOfA;
    int indexOfC;

    for (unsigned int i = 0; i < flightPathAngles.size(); i++)
    {
        if (flightPathAngles[i] == angle)
        {
            return coeffLifts[i];
        }
        if (flightPathAngles[i + 1] > angle)
        {
            indexOfA = i + 1;
            indexOfC = i;
            break;
        }
    }

    double linearInterpolation = coeffLifts[indexOfA] + ((angle - flightPathAngles[indexOfA]) / (flightPathAngles[indexOfC] - flightPathAngles[indexOfA]) * (coeffLifts[indexOfC] - coeffLifts[indexOfA]));

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
void reorder(vector<double> &flightPathAngles, vector<double> &coeffLifts)
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

                temp = coeffLifts[j];
                coeffLifts[j] = coeffLifts[i];
                coeffLifts[i] = temp;
            }
        }
    }
}
void printVector(const vector<double> &nums)
{ // for testing purposes
    for (double num : nums)
    {
        cout << num << " ";
    }
}
void inputFlightPathAngle(double angle, const vector<double> &flightPathAngles, const vector<double> &coeffLifts)
{ // for the sake of making main cleaner
    cout << "Input a flight-path angle: " << endl;
    cin >> angle;

    if (angle >= flightPathAngles[0] && angle <= flightPathAngles[flightPathAngles.size() - 1])
    {
        cout << "Coefficient of lift: " << interpolation(angle, flightPathAngles, coeffLifts);
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
            cout << "Coefficient of lift: " << interpolation(angle, flightPathAngles, coeffLifts) << endl;
        }
        cout << "Would you like to input another flight-path angle?" << endl;
        cout << endl;
        cin >> choice;
    }
}
