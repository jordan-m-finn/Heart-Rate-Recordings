#include "Jordan_Finn_HeartRates.h"
#include <iostream>
#include <string>

// Comment 3:
// This is a constructor that takes the user's first and last name via strings
// and the user's date of birth, separating the month, day, and year via integers
// This then proceeds to initialize the private member variables with the user provided
// data
HeartRates::HeartRates(std::string fN, std::string lN, int m, int d, int y)
{
     firstName = fN;
     lastName = lN;
     birthMonth = m;
     birthDay = d;
     birthYear = y;
}

// set functions for each attribute
void HeartRates::setFirstName(std::string fN) {firstName = fN;}

void HeartRates::setLastName(std::string lN) {lastName = lN;}

void HeartRates::setBirthMonth(int m) {birthMonth = m;}

void HeartRates::setBirthDay(int d) {birthDay = d;}

void HeartRates::setBirthYear(int y) {birthYear = y;}

// get functions for each attribute
std::string HeartRates::getFirstName() const {return firstName;}

std::string HeartRates::getLastName() const {return lastName;}

int HeartRates::getBirthMonth() const {return birthMonth;}

int HeartRates::getBirthDay() const {return birthDay;}

int HeartRates::getBirthYear() const {return birthYear;}

// Comment 4:
// This public member function is passed the user's date of birth,
// separated by month, day, and year via integers.
// It also declares local variables for storing the user provided current
// date. The following logic takes both the arguments for the user's date of birth
// and the user's current date stored in the local variables to calculate
// the user's age. This then display's the user's age.
int HeartRates::getAge(int userMonth, int userDay, int userYear)
{
     int currentMonth;
     int currentDay;
     int currentYear; 
     
     std::cout << "Please enter the current month, day, and year (separated by spaces): " << std::endl;
     std::cin >> currentMonth >> currentDay >> currentYear;

     // Comment 5:
     // This is logic first initializes and calculates the age variable by subtracting
     // the current year and the user's birth year and then
     // further manipulates the value of that variable according to the differences
     // of the month and day to provide a further accurate age.
     int age = (currentYear - userYear);
     if (currentMonth < userMonth || (currentMonth == userMonth && currentDay < userDay))
     {
          age--;
     }
     std::cout << "Age: " << age << std::endl;

     return age;
}

// Comment 6:
// This public member function recieves the age calculated by the previous member function
// and further calculates the user's maximum heart rate by intializing a local variable
// to store the calculated result. This then displays the user's maximum heart rate.
int HeartRates::getMaximumHeartRate(int age)
{
     int maximumHeartRate = (220 - age);

     std::cout << "Maximum Heart Rate: " << maximumHeartRate << std::endl;

     return maximumHeartRate;
}

// Comment 7:
// This public member function recieves the maximum heart rate calculated by the previous function
// and further calculates the target heart rate the user should have. It does so by initializing 
// two local variables, one for the lower end of the range and the other for the higher end.
// This then displays the user's target heart rate and returns a string for later conversions
// by other possible applications.
std::string HeartRates::getTargetHeartRate(int maxRate)
{
     int targetRate50 = (maxRate * 0.85);
     int targetRate85 = (maxRate * 0.50);

     std::cout << "Target Heart Rate: " << targetRate85 << "-" << targetRate50 << std::endl;

     std::string ratesCombined = std::to_string(targetRate50) + "-" + std::to_string(targetRate85);

     return ratesCombined;
}