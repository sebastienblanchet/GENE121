//Sebastien Blanchet (Partner A) & Richin George (Partner B)
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

double angle(int deg, int min)
{
	double ang=deg+min/60.0;
	return ang;
}


double ycoord(double lat, double lon)
{
	double y=lon*111.0*cos(lat*M_PI/180);
    return y;
}

double xcoord(double lat)
{
	double x=lat*111.0;
	return x;
}


int main ()
{	
	int degx, minx, degy, miny, msgs;
	ifstream fin ("message.txt");
	
	if(!fin)
    {
	     cout << "Unable to open file";
	     cin.get ();
	     cin.get ();
	     return EXIT_FAILURE;
    }
    
	fin>>degx >> minx>> degy>> miny>> msgs;
	
	double angx=angle(degx,minx);
	double angy=angle(degy,miny);
	
	double x1=xcoord(angx);
	double y1=ycoord(angx, angy);
	
	cout<<"Initial angle is "<< angx << " " << angy<< endl;
	cout<<"Intial coordinates "<< x1<< " , " << y1<< endl;
	cout<<"There are " << msgs<< " delivery sites"<< endl;

	for(int i=1; i <=msgs; ++i)
	{
		int a, b, c, d;
		while(fin>> a>> b>> c>> d)
		{
		double rx=angle(a,b);
		double ry=angle(c,d);
		double x=xcoord(rx);
		double y=ycoord(rx, ry);
		
		double distance=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
		double angc= ((atan2(y,x))*M_PI/180);
		cout<< distance << " "<<  angc<< endl;
		}
	
	}
	
	cin.get();
	cin.get();
	return 0;	
}
