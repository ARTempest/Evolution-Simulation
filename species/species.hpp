#pragma once
#ifndef SPECIES_H
#define SPECIES_H

#include <iostream>
#include "../structs/coords.hpp"


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
//	int move();
};


Species::Species(){
	position.x = 0;
	position.y = 0;

	hp = 1;
	diet = 'H';
}

Species::Species(double _hp, char _diet) : hp(_hp), diet(_diet){}; // Assing values for hp and diet;

/*
int Species::move(){
	int _avaliblePos = avaliblePos;
	int direction = 8;
	string values;

	for (int i=0; i < 4; i++){
		if (_avaliblePos - direction > 0){
			values += std::to_string(direction);
			_avaliblePos -= direction;
		}	

		direction /= 2; 
	}

	return 1234;

	//direction = stoi(values[generateRandom(0, length(values))])

	// return pos as a power of 2 so 1 2 4 8;
}
*/

#endif





