/* Tyler Nathan Smith */

#include <iostream>
#include <stdlib.h> 
#include <ctime>

#define RACE_LENGTH 50

void advanceRacerA(int* ptrRacerA);
void advanceRacerB(int* ptrRacerB);
void printPosition(int* ptrRacerA, int* ptrRacerB);

int main()
{
	//Variable declaration
	bool endRace = false;
	int racerA = 0;
	int racerB = 0;
	srand((int)time(0)); //Seed for random number
	
	//Print beginning simulation of race
	std::cout << std::endl;
	std::cout << "Welcome to the Spartan Race!" << std::endl;
	std::cout << "READY...SET...GO!" << std::endl;
	std::cout << std::endl;
	
	//Loop through the race until a user gets to end
	while( endRace == false )
	{
	    //Advance racer A (call function)
		advanceRacerA(&racerA);
		if( racerA < 0 )
		{
			racerA = 0;
		}
		
		if(racerA > RACE_LENGTH)
			racerA = RACE_LENGTH;
		
		//Check if racerA has reached the end
		if( racerA == RACE_LENGTH)
		{
			//Change condition variable to leave loop
			endRace = true;
		}
		
		if( racerA != RACE_LENGTH )
		{
			//Advance racer B (call function)
			advanceRacerB(&racerB);
			if( racerB < 0 )
			{
				racerB = 0;
			}
		
			if(racerB > RACE_LENGTH)
				racerB = RACE_LENGTH;
		
			if(racerA == racerB)
			{
				racerA = racerA - 1;	
			}
				
			//Check if racerB has reached the end
			if( racerB == RACE_LENGTH )
			{
				//Change condition variable to leave loop
				endRace = true;
			}
		}
		
		//Print location(call function)
	    printPosition(&racerA, &racerB);
	}
	//end loop
	
	//Print result of race
	std::cout << std::endl;
	if( racerA == RACE_LENGTH )
	{	
		std::cout << "You won the race - Your friend must train harder!" << std::endl;
	}
	else if( racerB == RACE_LENGTH )
	{	
		std::cout << "Your friend won the race - You must train harder!" << std::endl;
	}
}

void advanceRacerA(int* ptrRacerA)
{
	int nextObstacle = 0;
	
	//Generate random number from 1 - 10
	nextObstacle = rand()%10 + 1;
	
	//If number is 1, 2 or 3, run (move 4 spaces right)
	if(nextObstacle == 1 || nextObstacle == 2 || nextObstacle == 3)
	{
		*ptrRacerA = *ptrRacerA + 4; //Change location of racer A
	}
	//If number is 4, sprint (move 5 spaces right)
	else if( nextObstacle == 4) 
	{
		*ptrRacerA = *ptrRacerA + 5;
    }
	//If number is 5, 6 or 7, fall in mud (move 2 spaces left)
	else if( nextObstacle == 5 || nextObstacle == 6 || nextObstacle == 7) 
	{
		*ptrRacerA = *ptrRacerA - 2;
    }
	//If number is 8 or 9, fall off rope (move 3 spaces left)
	else if( nextObstacle == 8 || nextObstacle == 9) 
	{
		*ptrRacerA = *ptrRacerA - 3;
    }
	//If number is 10, fall off monkey bars (move 4 spaces left)
	else if( nextObstacle == 10)
	{
		*ptrRacerA = *ptrRacerA - 4;
	}	
}

void advanceRacerB(int* ptrRacerB)
{
	int nextObstacle = 0;
	
	//Generate random number from 1 - 10
	nextObstacle = rand()%10 + 1;

	//If number is 1, 2, 3, or 4 run (move 4 spaces right)
	if( nextObstacle == 1 || nextObstacle == 2 || 
	    nextObstacle == 3 || nextObstacle == 4 )
	{		
		*ptrRacerB = *ptrRacerB + 4; //Change location of racer B
	}
	//If number is 5, sprint (move 5 spaces right)
	else if( nextObstacle == 5 ) 
	{
		*ptrRacerB = *ptrRacerB + 5; //Change location of racer B
	}	
	//If number is 6 or 7, fall in mud (move 2 spaces left)
	else if( nextObstacle == 6 || nextObstacle == 7 ) 
	{
		*ptrRacerB = *ptrRacerB - 2; //Change location of racer B
	}
	//If number is 8 or 9, fall off rope (move 3 spaces left)
	else if( nextObstacle == 8 || nextObstacle == 9 ) 
	{
		*ptrRacerB = *ptrRacerB - 3; //Change location of racer B
	}
	//If number is 10, fall off monkey bars (move 4 spaces left)
	else if( nextObstacle == 10 ) 
	{
		*ptrRacerB = *ptrRacerB - 4; //Change location of racer B
	}
}

void printPosition(int* ptrRacerA, int* ptrRacerB)
{
	int posCount = -1;
	int racerA = *ptrRacerA;
	int racerB = *ptrRacerB;
	
	while( posCount < (RACE_LENGTH) )
	{
		posCount++; //Increment counter to print entire race
		
		if( racerA == posCount )
		{
			//Print racer A location
			std::cout << "A";
		}
		else if( racerB == posCount )
		{
			//Print racer B location
			std::cout << "B";
		}
		else
		{
			//Print blank position
			std::cout << ' ';
		}
	}
	
	//Print the finish line
	std::cout << "|" << std::endl;
}


