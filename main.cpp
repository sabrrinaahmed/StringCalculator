#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;

    string firstDigit = "";
    string SecondDigit = "";
    char operatorGiven = 'n';


    while (firstDigit != "q" || firstDigit != "quit"){
    	cout << ">> ";
    	cin >> firstDigit;
    	if (firstDigit == "q" || firstDigit == "quit") {
    		break;
        } else if (firstDigit[0] == '0'){
            firstDigit = trim_leading_zeros(firstDigit);
        } else if (firstDigit[0] == '-' && firstDigit[1] == '0'){
            firstDigit = trim_leading_zeros(firstDigit);
        } else {
    	 cin >> operatorGiven >> SecondDigit;
        }
        if(firstDigit != "" && SecondDigit == "" && operatorGiven == 'n'){
            cout << endl << "ans =" << endl  << endl << "    " << firstDigit << endl << endl;
        }
    	if (operatorGiven == '+'){
    		cout << endl << "ans =" << endl << endl << "    " << add(firstDigit,SecondDigit) << endl << endl;
    	} else if (operatorGiven == '-'){
    		cout << endl << "ans =" << endl << endl << "    " << subtract(firstDigit,SecondDigit) << endl << endl;
    	} else if (operatorGiven == '*'){
    		cout << endl << "ans =" << endl  << endl << "    " << multiply(firstDigit,SecondDigit) << endl << endl;
    	}

    }

    cout << endl << "farvel!" << endl;
    cout << endl;

}

