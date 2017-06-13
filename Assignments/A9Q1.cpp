#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

const int MAXBOOK= 50;

int BookNum(ifstream & fin,string SimData[], int Scores[][MAXBOOK], int Books)
{
	string BookName;
	int Scores;
	
	while(fin>> Books >> Book Names >> Scores)
	{
		SimData[] ;
		Scores[][Books];
		
	}
	
	return Books;
}

int main()
{
    ifstream fin("similar.txt");
    
    if (!fin)
    {
    	cout<<"Unable to open file"<<endl;
		system("PAUSE");
		return 0;	
    }
    
    fin.close();
    
    system("PAUSE");
	return 0;
}

