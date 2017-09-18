#include <iostream>

#include "pid.hpp"
#include <cmath>
#include <iostream>
#include <unistd.h>

int main()
{
    double desiredHeight;
    std::cout << "Desired Height: ";
    std::cin >> desiredHeight;


    double dt = .0001; //can be changed for precision
    double lastError = 0;
    while(desiredHeight != getHeight()) {
    	double sum = 0;
    	double error = desiredHeight - getHeight();
    	double PError = 0;
    	double IError = 0;
    	double DError = 0;

    	//proportional
    	PError = error;
    	sum += KP * PError;

    	//integral
    	IError = error*dt;
    	sum += KI * IError;

    	//derivative
    	DError = (error - lastError)/dt;
    	sum += KD * DError;

    	//set
    	setThrust(sum);

    	lastError = error;

    	sleep(dt);
    }

    std::cout << "Done";
}
