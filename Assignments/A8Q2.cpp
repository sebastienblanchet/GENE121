#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

const int MAX=10, SPACES=50;

void allnames(ifstream &fin, int status[], string  allnames[])
{	
   string name;
   int type, parknum;
   while(fin>>type>>name>>parknum)
    {
        allnames[parknum] = name;
        status[parknum] = type;
                 	
}

int addremove(ifstream &fin, bool tof[], string name[])
{
    int a=0;
    while(fin>>tof[a]>>name[a])
         a++;
    return a; 
}

int main()
{   
    string allnames[SPACES], removename[MAX], addname[MAX];
	bool status [SPACES], removed[MAX], added[MAX];
    int numspace [SPACES];
	
	ifstream fin ("parkingF13.txt");
    ifstream fin2("removeW14.txt");
    ifstream fin3("assignW14.txt");
    ofstream fout("parkingW14.txt");
    
    if (!fin||!fin2||!fin3)
    {
    	cout<<"Unable to open files"<<endl;
		system("PAUSE");
		return EXIT_FAILURE;	
	}
    
    fin.close();
    fout.close();
    
    system("PAUSE");
    return 0;
}

