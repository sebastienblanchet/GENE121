void routeColour(int distX, int distY, int distCup)// Darren Lau
{
	int x1, Xencoder;
  	nMotorEncoder[motorA]=0;

	if (SensorValue[S1] == 2)
  	{
		x1 = distX;
		do
     	{	
      		motor[motorA]=50;
      		motor[motorC]=50;
     	}while(nMotorEncoder[motorA] < 120*x1/PI);
	}

	else if (SensorValue[S1]== 3)
	{
		x1 = distX + distCup;
		do
		{
			motor[motorA]=50;
			motor[motorC]=50;
      	}while(nMotorEncoder[motorA] < 120*x1/PI);
	}

	else if (SensorValue[S1]== 4)
   	{
		x1 = distX + 2*distCup;
		do
      	{
			motor[motorA]=50;
            motor[motorC]=50;
       	} while(nMotorEncoder[motorA] < 120*x1/PI);
	}

   else if (SensorValue[S1] == 5)
	{
		x1 = distX + 3*distCup;
		do
      	{	
			motor[motorA]=50;
            motor[motorC]=50;
      	} while(nMotorEncoder[motorA] < 120*x1/PI);
	}

	motor[motorA] = 50;
    motor[motorC] = -50;
    wait10Msec(105);

    Xencoder = nMotorEncoder[motorA];

    while ((nMotorEncoder[motorA] - Xencoder) < 120*(distY-16)/PI  )
    {
		motor[motorA] = 50;
        motor[motorC] = 50;
    }

    motor[motorA] = 0;
    motor[motorC] = 0;

    motor[motorB] = -10;
    wait10Msec(70);
    motor[motorB] = 0;
  	wait10Msec(80);
  	motor[motorB] = 10;
  	wait10Msec(80);
  	motor[motorB] = 0;
  	wait10Msec(100);

    while ((nMotorEncoder[motorA] - Xencoder) > 0 )
   	{
		motor[motorA] = -50;
        motor[motorC] = -50;
     }

    motor[motorA] = -50;
    motor[motorC] = 50;
    wait10Msec(106 );

	while (nMotorEncoder[motorA] > 0)
    {
    	motor[motorA] = -50;
        motor[motorC] = -50;
    }

    motor[motorA] = 0;
    motor[motorC] = 0;
}


int inputCount(int time, int button)// Ian Bernas
{
	int a;

  	if(button==1)
  		a = time+5;

  	else if(button==2)
  		a = time-5;

 	if(a < 0)
  		a = 0;

	return a;
}

float totaldist(int xdist, int ydist, int cupdist, int blue, int green, int yellow, int red)// Sebastien Blanchet
{
	float totalx, totaly, total;
  	int bluex,greenx, yellowx,redx, size;

  	size=blue+green+yellow+red;

  	totaly= 2.0*ydist*size;

	bluex=cupdist*0;
	greenx=cupdist*1;
	yellowx=cupdist*2;
	redx=cupdist*3;

	totalx=2.0*((size*xdist)+(bluex*blue)+(redx*red)+(greenx*green)+(yellowx*yellow));

	total= totaly+totalx;

    return total;
}

void display(int dist,int blue, int green, int yellow, int red, float time)// Sebastien Blanchet and Ian Bernas
{
    nxtDisplayString(1,"Tot dist = %.1f",dist);
  	nxtDisplayString(2,"Tot blue = %d",blue);
  	nxtDisplayString(3,"Tot green = %d",green);
  	nxtDisplayString(4,"Tot yellow = %d",yellow);
  	nxtDisplayString(5,"Tot red  = %d",red);
  	nxtDisplayString(6, "Tot time = %.1f", time);
}
void ColorDisplay( int Colorval )// Ian Bernas
{
	string Colors[4] =
	{
		"Blue",
		"Green",
		"Yellow",
		"Red",
	};
  	
	nxtDisplayString(1, "Your Color Is");
  	nxtDisplayString(2, " %s ", Colors[Colorval - 2]);
}




task main()
{
  	SensorType[S1] = sensorCOLORFULL;
  	SensorType[S2] = sensorTouch;
  	SensorType[S3] = sensorTouch;

  	int time = 0;
	nxtDisplayString(1, "Choose runtime(s)");
  	nxtDisplayString(2, "Time = %d",time);

  	while(nNxtButtonPressed!=3)
  	{
		while(nNxtButtonPressed == -1)
    	{}
    	time = inputCount(time, nNxtButtonPressed);
		
		if(nNxtButtonPressed == 1 || nNxtButtonPressed == 2)
			while(nNxtButtonPressed!=-1)
			{}
			nxtDisplayString(2, "Time = %d", time);
  	}
	eraseDisplay();
	while(nNxtButtonPressed != -1)
	{}

  	int distX = 0;

	nxtDisplayString(1, "X dist. to 1st cup");
    nxtDisplayString(2, "Distance X = %d",distX);

	while(nNxtButtonPressed!=3)
  	{
    	while(nNxtButtonPressed == -1)
    	{}
    	distX = inputCount(distX, nNxtButtonPressed);
		if(nNxtButtonPressed == 1 || nNxtButtonPressed == 2)
			while(nNxtButtonPressed!=-1)
    		{}
		  	nxtDisplayString(2, "Distance X = %d", distX);
  	}

  	eraseDisplay();
    while(nNxtButtonPressed != -1)
	{}

	int distY = 0;

  	nxtDisplayString(1, "Y dist. to 1st cup");
	nxtDisplayString(2, "Distance Y = %d",distY);

  	while(nNxtButtonPressed!=3)
  	{
    	while(nNxtButtonPressed == -1)
    	{}
    	distY = inputCount(distY, nNxtButtonPressed);
		if(nNxtButtonPressed == 1 || nNxtButtonPressed == 2)
			while(nNxtButtonPressed!=-1)
    		{}
			nxtDisplayString(2, "Distance Y = %d", distY);
  	}
	  
	eraseDisplay();
    while(nNxtButtonPressed != -1)
	{}
  	
	int distCup = 0;

	nxtDisplayString(1, "Dist. between cups");
  	nxtDisplayString(2, "Distance = %d",distCup);

	while(nNxtButtonPressed!=3)
  	{
    	while(nNxtButtonPressed == -1)
    	{}
    	distCup = inputCount(distCup, nNxtButtonPressed);
		if(nNxtButtonPressed == 1 || nNxtButtonPressed == 2)
		while(nNxtButtonPressed!=-1)
    	{}

		nxtDisplayString(2, "Distance = %d", distCup);
      	nxtDisplayString(5, "Left sensor cont.");
  	}
    
	while(nNxtButtonPressed!=-1)
	{}
  	
	eraseDisplay();

  	int ColorCount[7] =
  	{
		0,
  	  	0,
  	  	0,
  	  	0,
  	  	0,
  	  	0,
  	  	0,
  	};

  	nxtDisplayString(3, "Ball in pocket");
  	nxtDisplayString(4, "Left sensor start.");

	while(SensorValue[S2] == 0)
  	{}

  	eraseDisplay();

  	time1[T1] = 0;
  	while(time100[T1] < (time*10.0) && SensorValue[S3] == 0)
  	{
		if(SensorValue[S2] == 1)
  		{
  			while(SensorValue[S2] == 0)
  		  	{}
  		 	eraseDisplay();
	    	ColorCount[SensorValue[S1]]++;
	    	ColorDisplay(SensorValue[S1]);
	    	routeColour(distX, distY, distCup);
	    	nxtDisplayString(3, "Ball in pocket");
	      	nxtDisplayString(4, "Left sensor start.");
	      }
	    else{}
    }

  	float disttotal;
	eraseDisplay();
  	
	disttotal=totaldist(distX, distY, distCup, ColorCount[2], ColorCount[3], ColorCount[4], ColorCount[5]);
    display(disttotal,ColorCount[2], ColorCount[3], ColorCount[4], ColorCount[5], (time100[T1])/10.0);
    
	while(nNxtButtonPressed !=3)
  	{}
  	
 }
