#include <iostream>

#ifndef HEARTRATES_H
#define HEARTRATES_H

// Comment 1:
// This is a class intended to store personal information from the user
// and then use this personal info to calculate the user's age,
// maximum heart rate, and target heart rate.
class HeartRates
{
public:

     HeartRates(std::string, std::string, int, int, int);
     
     void setFirstName(std::string);
     void setLastName(std::string);
     void setBirthMonth(int);
     void setBirthDay(int);
     void setBirthYear(int);

     std::string getFirstName() const;
     std::string getLastName() const;
     int getBirthMonth() const;
     int getBirthDay() const;
     int getBirthYear() const;
     
     int getAge(int, int, int); 
     int getMaximumHeartRate(int); 
     std::string getTargetHeartRate(int); // Comment 2: This returns a string because it calculates a range of integers
                                          // which is then converted to a string which can then be converted by others
                                          // who want to use this class for other applications.

private:
     std::string firstName;
     std::string lastName;
     int birthMonth;
     int birthDay;
     int birthYear;
};

#endif

