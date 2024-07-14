#include <iostream>
#include "header.h"
#include <string>

int main () {
    long long int binaryInput;
    long long int decimalInput;

    std:: cout << "Enter a binary number: ";
    std:: cin >> binaryInput;

    std:: cout << "Enter a decimal number: ";
    std:: cin >> decimalInput;

    

    binaryConverter(binaryInput, decimalInput);
}