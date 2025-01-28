#pragma once
#ifndef SPECIES_H
#define SPECIES_H

#include <iostream>
#include <string>
#include "../structs/coords.hpp"
#include "../random/random.hpp"

class Species{
	coords position;
	coords *avaliblePos;

	double hp;
	double thirsty;

//Diet
	char diet;
	int hungry;
	int caloricEx; // Stands for caloric Expenditure

	char icon = diet;


public:
//Constructors
	Species ();
	Species(coords, double, char, int, int);
	
//Get Functions
	coords getPos() { return  position;};
	double  getHP() { return hp;};
	char  getDiet() { return diet;};
	int getHungry() { return hungry;};

//SendFunctions
	void sendAvaPos(coords *_avaliblePos) { avaliblePos = _avaliblePos;};

//ActionFunctions
	bool move();
	void caloricConsumption(bool);
	void actions();

};


Species::Species(){
	position.x = 1;
	position.y = 1;

	hp = 1;
	thirsty = 100;
	diet = 'H';
	hungry = 100;
	caloricEx = 2;
}

Species::Species(coords _position,double _hp, char _diet, int _hungry, int _caloricEx) : position(_position), hp(_hp), diet(_diet), hungry(_hungry), caloricEx(_caloricEx){};

bool Species::move(){
	coords _move;
	int length = 0;

	if (avaliblePos[0].y == 0 && avaliblePos[0].x == 0){
		length = 1;
	}

	for (int i=0; i <= 4; i++){
		//std::cout << "x: "<< avaliblePos[i].x  << " y: " << avaliblePos[i].y << '\n';
		if (avaliblePos[i].y != 0 && avaliblePos[i].x != 0){
			length++;
		}
	}

	int randomIndex = generateNumber(0,length -1);

	position = avaliblePos[randomIndex];

	if (randomIndex == 0){
		return false;
	} 
	else{
		return true;
	}
}

void Species::caloricConsumption(bool _moveStatus){
	if (_moveStatus == true) {
		hungry -= caloricEx;
	} 
	else{
		hungry -= caloricEx / 2;
	}
}

void Species::actions(){
	bool moveStatus = move();
	caloricConsumption(moveStatus);
}


// TODO add a check status to check if the specie's thirsty level is below 50 or not, also for hungry. And add a different movement for when they're hungry or thirst.

#endif





