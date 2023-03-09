#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void readData(const string &windTunnelFile, vector<double> &flightPaths, vector<double> &coeffLifts);
double interpolation(double angle, const vector<double> &windTunnelFile, const vector<double> &coeffLifts);
bool isOrdered(const vector<double> &nums);
void reorder(vector<double> &flightPaths, vector<double> &coeffLifts);
void printVector(const vector<double> &nums);
void inputFlightPathAngle(double angle, const vector<double> & flightPaths, const vector<double> &coeffLifts);

int main(int argc, char *argv[])
{
    string windTunnelFile = argv[1]; // replace later
    vector<double> flightPaths;
    vector<double> coeffLifts;
    double angle;

    readData(windTunnelFile, flightPaths, coeffLifts);

    reorder(flightPaths, coeffLifts);

    
    return 0;
}
void readData(const string &windTunnelFile, vector<double> &flightPaths, vector<double> &coeffLifts)
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
        flightPaths.push_back(flightAngle);
        coeffLifts.push_back(coeffLift);
    }
}
double interpolation(double angle, const vector<double> &flightPaths, const vector<double> &coeffLifts)
{
    int indexOfA;
    int indexOfC;

    for (unsigned int i = 0; i < flightPaths.size(); i++)
    {
        if (flightPaths[i] == angle)
        {
            return coeffLifts[i];
        }
        if (flightPaths[i + 1] > angle)
        {
            indexOfA = i + 1;
            indexOfC = i;
            break;
        }
    }

    double linearInterpolation = coeffLifts[indexOfA] + ((angle - flightPaths[indexOfA]) / (flightPaths[indexOfC] - flightPaths[indexOfA]) * (coeffLifts[indexOfC] - coeffLifts[indexOfA]));

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
void reorder(vector<double> &flightPaths, vector<double> &coeffLifts)
{ // ascending order
    if (flightPaths.size() == 0){
        return;
    }
    for (unsigned int i = 0; i < flightPaths.size() - 1; i++)
    {
        for (unsigned int j = i + 1; j < flightPaths.size(); j++)
        {
            if (flightPaths[j] < flightPaths[i])
            {
                double temp = flightPaths[j];
                flightPaths[j] = flightPaths[i];
                flightPaths[i] = temp;

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
void inputFlightPathAngle(double angle, const vector<double> & flightPaths, const vector<double> &coeffLifts){
    cout << "Input a flight-path angle: " << endl;
    cin >> angle;

    if (angle >= flightPaths[0] && angle <= flightPaths[flightPaths.size() - 1])
    {
        cout << "Coefficient of lift: " << interpolation(angle, flightPaths, coeffLifts);
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

        if (angle >= flightPaths[0] && angle <= flightPaths[flightPaths.size() - 1])
        {
            cout << "Coefficient of lift: " << interpolation(angle, flightPaths, coeffLifts) << endl;
        }
        cout << "Would you like to input another flight-path angle?" << endl;
        cout << endl;
        cin >> choice;
    }
}
