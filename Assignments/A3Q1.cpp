#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    int cyear, vyear;
    ifstream inFile("etest.txt");
    ofstream outFile ("DriveCleanExam.txt");
   
    while (inFile >> cyear >> vyear)
    {
     if (!inFile)
     {
      cout << "Unable to open file";
      system ("PAUSE");
      return EXIT_FAILURE;
      }
     
     if (vyear>=1987 && (cyear-vyear)>=7)
     {
     if (cyear%2==0 && vyear%2==0) 
     outFile <<"You do not need a Drive Clean Exam this year (" << cyear << ")."
     "You will need one next year because your vehicle is an even year vehicle"
     "(" << vyear << ")." << endl;
     
     else if (cyear%2==0 && vyear%2!=0)
     outFile << "You need a Drive Clean Exam this year (" << cyear << ") " 
     "because your car is an odd year vehicle (" << vyear << ")." << endl;
     
     else if (cyear%2!=0 && vyear%2!=0)
     outFile <<"You do not need a Drive Clean Exam this year (" << cyear << ")."
     "You will need one next year because your vehicle is an odd year vehicle "
     "(" << vyear << ")." << endl;
     
     else 
     outFile << "You need a Drive Clean Exam this year (" << cyear << ") "
     "because your car is an even year vehicle (" << vyear << ")." << endl;
    }
    
    else if (vyear <1987)
    outFile <<"You do not need a Drive Clean Exam because your car is older "
    "than 1987";
   
    else
    outFile <<"You do not need a Drive Clean Exam this year (" << cyear << 
    ") because your car is newer than 7 years old (" << vyear << ")." << endl; 
    }
    inFile.close();
    
    system("PAUSE");
    return 0;
}
