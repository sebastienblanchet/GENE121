#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

double slope(double p1, double p2)
{
	return sqrt((0.5)*(0.5)+(p2-p1)*(p2-p1));
}

int main ()
{
	ifstream fin("columbia.dat");

	
	cout<<setprecision(1)<<fixed;
	if(!fin)
    {
	     cout << "Unable to open file";
	     cin.get ();
	     cin.get ();
	     return EXIT_FAILURE;
    }
	int a,b,i=0 ;
    double m, p[150];
    bool safe=true;
    
    
	while (fin>>p[i])
	{
		i++;
	}
	
	for(int a=1; a<10; a++)
	{
		cout<<"Point "<< setw(3)<<a << setw(3)<<"is"<<setw(6)<<p[a];
		m= slope(p[a],p[a+1]);
		cout<<" Slope : "<<m<< endl;
	
		if(m>10)
		{
			safe=false;	
		}
	
	}
	 
	for(int b= i-10; b<i ;b++)
	{
		cout<<"Point "<< setw(3)<<b << setw(3)<<"is"<<setw(6)<<p[b];
    	m= slope(p[b],p[b+1]);
		cout<<" Slope : "<<m<< endl;
		
		if(m>10)
		{
			safe=false;
		}
	}
	
	if(safe=true)
	{
		cout<<"Lake is UNSAFE"<<endl;
	}
	else
	{
		cout<<"Lake is SAFE"<<endl;
	}
	
	
	cin.get();
	cin.get();
	return 0;
}

/*
Point   1 is   0.0 Slope : 0.6
Point   2 is  -0.3 Slope : 0.5
Point   3 is  -0.4 Slope : 0.8
Point   4 is  -1.0 Slope : 4.0
Point   5 is  -5.0 Slope : 10.0
Point   6 is -15.0 Slope : 0.6
Point   7 is -15.3 Slope : 1.8
Point   8 is -17.0 Slope : 0.5
Point   9 is -17.1 Slope : 1.0
Point 103 is -15.0 Slope : 4.0
Point 104 is -11.0 Slope : 0.5
Point 105 is -10.9 Slope : 0.7
Point 106 is -10.4 Slope : 4.4
Point 107 is  -6.0 Slope : 0.6
Point 108 is  -5.7 Slope : 1.8
Point 109 is  -4.0 Slope : 2.1
Point 110 is  -2.0 Slope : 0.7
Point 111 is  -1.5 Slope : 1.6
Point 112 is   0.0 Slope : 0.5
Lake is UNSAFE
*/
