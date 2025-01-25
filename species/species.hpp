#pragma once
#ifndef SPECIES_H
#define SPECIES_H

#include <iostream>
#include <string>
#include "../structs/coords.hpp"
#include "../random/random.hpp"

class Species{
	coords position;
	coords* avaliblePos;

	double hp;
	double thirsty = 100;
	char diet;
	char icon = diet;

public:
	Species ();
	Species(double,char);
	
	coords* getPos(){ return &position;};
	double* getHP() { return &hp;};
	char* getDiet() { return &diet;};
	
	void sendAvaPos(coords* _avaliblePos) { avaliblePos = _avaliblePos;};


	void move();
};


Species::Species(){
	position.x = 1;
	position.y = 1;

	hp = 1;
	diet = 'H';
}

Species::Species(double _hp, char _diet) : hp(_hp), diet(_diet){}; // Assing values for hp and diet;

void Species::move(){
	coords _move;
	int length = 0;

	if (avaliblePos[0].y == 0 && avaliblePos[0].x == 0){
		length = 1;
	}

	for (int i=0; i <= 4; i++){
		std::cout << "x: "<< avaliblePos[i].x  << " y: " << avaliblePos[i].y << '\n';
		if (avaliblePos[i].y != 0 && avaliblePos[i].x != 0){
			length++;
		}
	}

	int randomIndex = generateNumber(0,length -1);

	position = avaliblePos[randomIndex];
}



#endif





