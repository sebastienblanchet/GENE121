#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main ()
{
    ofstream fout("taxiResults.txt");
    ifstream fin ("taxiDir.txt");
    int stops; 
    double x2, y2,totalcost,totaldist;
    char x,y;
    
    if(!fin)
    {
	     cout << "Unable to open file";
	     cin.get ();
	     cin.get ();
	     return EXIT_FAILURE;
    }
    
	fout <<"# Stop " <<setw(10)<< "Distance" <<setw(8)<< "Cost" << 
    setw(12)<< "Total Dist" << setw(12)<< "Total Cost" << endl;
    int count=0;
     
    while(fin>>stops)
    {  
	     double x1=0, y1=0, d1=0;  
	     for(int i=1; i <=stops; ++i)
	     {
	         fin>> x2 >> x >> y2 >> y;
	        
	         if(x== 'W')
	         {
	          x2*=-1.0;
	         }
	         if(y== 'S')
	         {
	          y2*=-1.0;   
	         }
	         d1+=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	         x1=x2;
	         y1=y2;    
	     }
	     
		 double dist,d2, cost;
	     d2=sqrt((x2)*(x2)+(y2)*(y2)); 
	     dist=d1+d2;
		 cost=2.10*dist+15.0*stops;
	     totalcost += cost;
	     totaldist += dist;
	     count++;
	     
	     if(count<=4 || (count-4)%10 == 0)
	     {
	      fout<< setprecision (2) << fixed << setw(5)<< 
	      stops <<setw(10)<< dist <<setw(10)<<cost <<setw(10)<<totaldist << 
	      setw(12)<<totalcost<<endl;
	     }
	    
	     else
	     {
	      fout<< setprecision (2) << fixed << setw(5)<< 
	      stops <<setw(10)<< dist <<setw(10)<<endl;
	 	 }  
    }
    
    fout<< setw(35)<< totaldist << setw(12) << totalcost<< endl;
     
    cin.get ();
    cin.get ();
    return 0;
} 
    
/*
# Stop   Distance    Cost  Total Dist  Total Cost
    1     20.40     57.84     20.40       57.84
    2     12.00     55.20     32.40      113.04
    4     40.72    145.50     73.12      258.54
    3     25.83     99.25     98.95      357.79
    5     39.22
    7     51.39
    2     13.65
    1     20.20
    4     30.14
    5     33.71
    3     30.92
    2     25.23
    5     39.46
    4     26.46    115.56    409.31     1579.56
    3     30.39
    4     38.92
    5     41.91
    4     46.75
    3     30.47
    3     25.01
    4     35.76
    5     47.86
    1     20.18
    2     25.01     82.53    751.57     2808.30
    3     23.86
    2     28.96
    3     31.26
    4     34.79
    4     41.63
    2     28.30
    1     20.15
    4     32.92
    6     37.35
    3     21.75     90.68   1052.55     3920.36
    1     20.15
    3     29.42
    2     21.30
    1      9.21
    4     26.55
    4     34.92
    3     31.70
    2     32.54
    2     28.40
    2     19.87     71.73   1306.62     4813.91
    4     39.69
    5     38.93
    2     11.93
    4     38.34
    1     20.15
    1     20.00
    3     32.80
    2     21.08
    3     32.98
    5     33.90    146.19   1596.42     5872.49
    4     34.94
    3     38.30
    2     33.36
    1      9.84
    4     36.12
    3     25.67
    2     21.05
    4     33.77
    3     24.70
    2     19.57     71.10   1873.75     6874.88
    2     19.05
    3     33.58
    4     33.23
    2     18.40
    1     20.15
    2     24.84
    3     26.17
    3     37.00
    2     36.47
    2     13.53     58.41   2136.17     7785.96
    3     27.04
    2     32.14
    1     15.47
    3     27.28
                            2238.09     8135.00
*/
