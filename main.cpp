#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cmath>
using namespace std;

double extractNumeric(const string& str);

int main() {
    double value;
    string input;

    while (true) {
        cout << "Enter a string (or END to quit)" << endl;
        cin >> input;

        if (input == "END") {
            break;
        }

        value = extractNumeric(input);
        value = round(value * 1000.0) / 1000.0;

        if (value != -999999.99) {
            cout << fixed << setprecision(3) << value << endl;
        } else {
            cout << "Invalid Input" << endl;
        }
    }

    return 0;
}

double extractNumeric(const string& str) {
    int length = str.length();
    double num;
    string tstr;
    // no invalid characters
    string valid = "+-1234567890.";
    for (char c : str) {
        if (str.find(c) == string::npos) {
            return -999999.99;
        }
    }
    // no invalid + or -
    for (int i = 1; i < length; i++) {
        if (str.substr(i, 1) == "+" || str.substr(i, 1) == "-") {
            return -999999.99;
        }
    }

    string sign = str.substr(0, 1);
    bool positive;
    if (sign == "-") {
        positive = false;
        tstr = str.substr(1);
    } else if (sign == "+") {
        positive = true;
        tstr = str.substr(1);
    } else {
        positive = true;
        tstr = str;
    }

    int index = tstr.find(".");
    if (index == string::npos) {
        for (char c : str) {
            num = num * 10 + (c - '0');
        }
    } else {
        string s1 = tstr.substr(0, index);
        string s2 = tstr.substr(index + 1, length - index - 1);
        double temp; 

        for (char c : s1) {
            num = num * 10 + (c - '0');
        }

        for (int i = s2.length() - 1; i >= 0; i--) {
            temp = temp / 10.0 + (s2.substr(i, 1)[0] - '0') / 10.0;
        }
        num += temp;
    }

    if (!positive) {
        num *= -1;
    }
    return num;
}