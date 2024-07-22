#include <iostream>
#include <string>
#include <tuple>
#include <sstream>
#include "Jordan_Finn_HeartRates.h"

// Comment 8:
// The following are function prototypes to handle the logic for:
// recieving/displaying the user's name,
// recieving/displaying the user's date of birth,
// and recieving/displaying the user's calculated data.
// The intention here is to minimalize what's being handled in main.
// AKA doing the best I could think of to keep main clean :)
std::pair<std::string, std::string> getUserFullName();
std::tuple<int, int, int> getUserDateOfBirth();
void displayUserInfo(HeartRates&, std::tuple<int, int, int>);

int main()
{
     // Comment 9:
     // These two functions are for recieving the user's information
     // and are stored in variables to then be passed to the object of the class,
     // HeartRates. Look at the function declarations to see how they operate.
     auto names = getUserFullName();
     auto dob = getUserDateOfBirth();

     // Comment 10:
     // This is an object of the HeartRates class.
     // Look at the function declarations for getUserFullName() and getUserDateOfBirth()
     // for the explanation of these paramater data types.
     HeartRates userHeartRateData(names.first, names.second, std::get<0>(dob), std::get<1>(dob), std::get<2>(dob));

     // Comment 11:
     // This function is used to display the user's info
     // given the user's heart rate data and date of birth
     // as arguments.
     displayUserInfo(userHeartRateData, dob);

     return 0;
}

// Comment 12:
// This function recieves nothing but first creates
// 3 string variables used to store the user's first,
// last, and full name in which the full name is
// used for string operations provided by the iostream and 
// string libraries. This then prompts the user to provide values for
// these variables. This then 'pairs' the strings so that it can
// then be returned as a 'pair data type' to later be accessed and
// used as arguments for declaring the string values of the HeartRates object.
// 
// Disclaimer: This is used to exactly replicate the sample runs provided
// in the assignment4 in which the user entered first and last name
// on the same line.
std::pair<std::string, std::string> getUserFullName()
{
     std::string userFullName;
     std::string userFirstName, userLastName;

     std::cout << "Please enter first and last name (separated by spaces): " << std::endl;
     std::getline(std::cin, userFullName);

     std::istringstream iss(userFullName); // creates an istringstream object from the userFullName string
     std::getline(iss, userFirstName, ' '); // used to obtain the characters entered by the user from 'iss' into
                                            // userFirstName

     iss >> std::ws; // skip any whitespace in the previous stream (A problem occured where it wasn't separating the first
                    // and last name so it had to be done.
     
     std::getline(iss, userLastName, ' '); // used to obtain the remaining characters entered by the user from 'iss' into
                                           // userLastName

     return std::make_pair(userFirstName, userLastName);
}


// Comment 13:
// This function recieves nothing but first creates
// 3 integer variables and 1 string variable used to store the user's date of birth. 
// This then prompts the user to provide values for
// these variables. This then 'tuples' the integers so that it can
// then be returned as a 'tuple data type' to later be accessed and
// used as arguments for declaring the integer values of the HeartRates object.
// 
// Disclaimer: This is used to exactly replicate the sample runs provided
// in the assignment4 in which the user entered their birth month, day, and year
// on the same line.
std::tuple<int, int, int> getUserDateOfBirth()
{
     std::string userDoB;
     int userMonth;
     int userDay;
     int userYear;

     std::cout << "Please enter month, day, and year of birth (separated by spaces): " << std::endl;
     std::getline(std::cin, userDoB);

     // Comment 14:
     // This is the logic for invalid input becuase it appeared that in the displayUserInfo
     // function, the value for date of birth was displaying memory addresses. However,
     // this guarantees that the string is properly taken.
     std::istringstream iss(userDoB);
     if (!(iss >> userMonth >> userDay >> userYear))
     {
          std::cerr << "Invalid input." << std::endl;
     }

     return std::make_tuple(userMonth, userDay, userYear);
}

// Comment 15:
// This function receives the HeartRates object by reference
// so that the public member functions from the object can be accessed.
// This also uses the integer values gathered in the tuple from the getUserDateOfBirth
// function to use in the getAge, getMaximumHeartRate, and targetHeartRate 
// public member functions.
void displayUserInfo(HeartRates& obj, std::tuple <int, int, int> dob)
{
     std::cout << "First Name: " << obj.getFirstName() << std::endl;
     std::cout << "Last Name: " << obj.getLastName() << std::endl;
     std::cout << "Date of Birth: "
          << obj.getBirthMonth()
          << "/" << obj.getBirthDay()
          << "/" << obj.getBirthYear()
          << std::endl;

     // Comment 16:
     // The calculatedAge integer variable is calculated by storing the returned result of the
     // getAge public member function to then be passed into the getMaximumHeartRate public
     // member function. That result is then stored into the maxHeartRate integer variable to then
     // be used in the targetHeartRate public member function.
     int calculatedAge = obj.getAge(std::get<0>(dob), std::get<1>(dob), std::get<2>(dob));
     int maxHeartRate = obj.getMaximumHeartRate(calculatedAge);

     // Comment 17:
     // As mentioned earlier, targetHeartRate is not used in any other cases for this specific 
     // program so it will return a string to later be converted if needed.
     std::string targetHeartRate = obj.getTargetHeartRate(maxHeartRate);
}