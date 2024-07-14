#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <ctime>
#include <stdio.h>

//function to show the binary numbers in the form of a list by iterating through the list for each element
void showList(const std::list<int>& binary) {
    for (int bit : binary) {
        std::cout << bit;
    }
    std::cout << std::endl;
}

class Decimal{
    private:
        long value;
    public:
        //initalize the class
        Decimal(long long int val)
        : value(val) {}

        void next(){
            std::list <int> binary; //list for the binary that we will return
            //edge case for if 0 then automatically append to the last element of the list
            if (value == 0){
                binary.push_back(0);
            }
            //while the value is greater than 0:
            while (value > 0){
                if (value % 2 != 0){
                    //if the remainder is not 0 then add 1 to the array
                    binary.push_front(1);
                }
                else{
                    //if the remainder is zero add 0 to the list
                    binary.push_front(0);
                }
                //then continously divide by 2
                value /= 2;
            }
            //finally return the binary list value
            showList(binary);
        }
};

void binaryToDecimal(long long int binary){
    int number = 0;
    std::string numberString = std::to_string(binary);

    //reverse the order so that the binary number begins first
    reverse(numberString.begin(), numberString.end());

    //loop through the array of the binary string
    for (size_t i = 0; i < numberString.length(); i++){
        int numberInt = numberString[i] - '0'; //convert char to integer
        int total = numberInt * pow(2, i); //multiply by 2^i and add to the number that this functions returns
        number += total;
    }   
    //Return a number based on binary
    std::cout << "Number: " << number << std::endl;
}

void binaryConverter(long long int inputBinary, long long int inputDecimal){
    Decimal decimalValue(inputDecimal);
    decimalValue.next();

    binaryToDecimal(inputBinary);
}