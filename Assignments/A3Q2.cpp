#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main ()
{
	ofstream fout("Values.txt");
	ifstream fin("Stones.txt");
	double length, width, angle, TOL1=0.1, TOL2=0.5;
	int sum=0, cnt=0, value=0;
	
	
	if(!fin)
	{
		cout<< "Unable to open file";
		cin.get();
		cin.get();
		return EXIT_FAILURE;
	}
	
	while(fin >> value)
	{
		sum +=value;
		cnt+=1;
	}
	
	if(cnt ==0)
	{
		cout<< "No Values in file";
	}
	else
	{
		do
		{	
			cout<< "Enter length and width (cm) and containing angle (degrees)"<< endl;
			fin>> length >> width >> angle ;
			if((0.0<length && width)&&(0.0<=angle<=180.0))
			{
				if((length== width) && (angle==90.0))
				{	
					cout<<"Square ";
					fout<<length<<" "<<width <<" "<<angle << " Square ";
				}	
				else if((length!= width) && (angle==90.0))
				{
					cout<<"Rectangle ";
					fout<<length<<" "<<width <<" "<<angle << " Rectangle ";
				}
				else if((length== width) && (angle!=90.0))
				{
					cout<<"Rhombus ";
					fout<<length<<" "<<width <<" "<<angle << " Rhombus ";
            	}	
				else
				{
					cout<<"Parallelogram ";
					fout<<length<<" "<<width <<" "<<angle << " Parrallelogram "; 
				}	
			}
			else
			{
			cout<<"Invalid values";
			}
		
		}while((fabs(length-width)<TOL1)&&(fabs(angle)<TOL2));
	}
	fin.close();
	cin.get();
	cin.get();
	return 0;
}

