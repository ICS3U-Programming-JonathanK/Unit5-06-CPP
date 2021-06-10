// Copyright (c) 2019 St. Mother Teresa HS All rights reserved.
//
// Created by : Jonathan Kene
// Created on : June 9 2021
// This program rounds a decimal to the number of a decimal places entered

#include <iostream>
#include <cmath>


void RoundDecimals(float &decimalNum, int &numPlace) {
  // function adds 1, by reference
  decimalNum = decimalNum*pow(10, numPlace);
  decimalNum = decimalNum + 0.5;
  decimalNum = static_cast<int>(decimalNum);
  decimalNum = decimalNum/pow(10, numPlace);
}

main() {
  // this function gets a number and calls the AddOne function
  std::string userDecimalNumString;
  float userDecimalNumInt;
  std::string userNumPlacesIntString;
  int userNumPlacesInt;
  float result;
  std::cout <<"This program rounds a decimal to the number of a decimal places"
              " entered"<< std::endl;

  // input
  std::cout << "Enter a decimal number: ";
  std::cin >> userDecimalNumString;

  try {
    userDecimalNumInt = std::stof(userDecimalNumString);
    if (userDecimalNumInt <= 0) {
            std::cout << userDecimalNumInt << " is not a positive"
                                              " number"<< std::endl;
    } else {
      std::cout << "Enter the number of decimal places: ";
      std::cin >> userNumPlacesIntString;

      try {
        userNumPlacesInt = std::stoi(userNumPlacesIntString);
        if (userNumPlacesInt <= 0) {
          std::cout << userNumPlacesInt << " is not a positive"
                                           " number"<< std::endl;
        } else {
          RoundDecimals(userDecimalNumInt, userNumPlacesInt);
          std::cout << userDecimalNumString <<" rounded to " << userNumPlacesInt
                    << " decimals is: " << userDecimalNumInt
                    << std::endl;
        }
        } catch (std::invalid_argument) {
          // The user did not enter an integer.
          std::cout << "\n";
          std::cout << "Please enter a valid number.\n";
        }
      }
    } catch (std::invalid_argument) {
      // The user did not enter an integer.
      std::cout << "\n";
      std::cout << "Please enter a valid number.\n";
    }
}
