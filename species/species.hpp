#pragma once
#ifndef SPECIES_H
#define SPECIES_H

#include <iostream>
#include <string>
#include "../structs/coords.hpp"
#include "../random/random.hpp"

class Species{
	coords position;
	int avaliblePos = 0;

	double hp;
	double thirsty = 100;
	char diet;
	char icon = diet;

public:
	Species ();
	Species(double,char);
	
	coords* getPos()   { return &position;};
	double* getHP() { return &hp;};
	char* getDiet() { return &diet;};
	
	void sendAvaPos(int _avaliblePos) { avaliblePos = _avaliblePos;};	
	//int move();
};


Species::Species(){
	position.x = 0;
	position.y = 0;

	hp = 1;
	diet = 'H';
}

Species::Species(double _hp, char _diet) : hp(_hp), diet(_diet){}; // Assing values for hp and diet;


// (0,-1) = 1
// (-1,0) = 2
// (0,1)  = 4
// (1,0)  = 8     


/*
int Species::move(){ // CHange all of this and the one in map for an array of coords, and getting as argument the array of coords, and its length.
	int _avaliblePos = avaliblePos;
	int direction = 8;
	std::string values;
	coords _move;

	for (int i=0; i < 4; i++){
		if (_avaliblePos - direction >= 0){
			values += std::to_string(direction);
			_avaliblePos -= direction;
		}	

		direction /= 2; 
	}


	values = values[generateNumber(0,values.length() -1)];

	return stoi(values);


	// return pos as a power of 2 so 1 2 4 8;
}
*/

#endif





