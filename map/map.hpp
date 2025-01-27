#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include "../structs/coords.hpp"

const int mapSizeY = 10;
const int mapSizeX = 20;

std::string map[mapSizeY] = {
"####################", // 1
"#..................#", // 2
"#..................#", // 3
"#..................#", // 4
"#..................#", // 5
"#..................#", // 6
"#..................#", // 7
"#..................#", // 8
"#..................#", // 9
"####################" // 10
};

void actualizeMap(){

	for (int y=0; y < mapSizeY; y++){
		std::cout << map[y] << '\n';
	}
}

void spawnSpecie(coords speciePos, char icon){
	if (map[speciePos.y][speciePos.x] == '.'){
		map[speciePos.y][speciePos.x] = icon;
	}
}

coords* avalibleGrids(coords speciePos){
	int index = 1;
	const coords nullCord = {0,0};

	coords _speciePos = speciePos;
	_speciePos.y -= 1;
	

	static coords _avalibleGrids[5]; // Gotta find a solution for this problem this variable should be inside of the function bellow.
	_avalibleGrids[0] = speciePos;

	for (int i=1; i <= 4; i++){
		_avalibleGrids[i] = nullCord;

		if (map[_speciePos.y][_speciePos.x] == '.'){
			_avalibleGrids[index] = _speciePos;
			index ++;
			
		}

		if (_speciePos.y < speciePos.y) { 
			_speciePos.x --;
			_speciePos.y ++;
		} 
		else if (_speciePos.y == speciePos.y){
			_speciePos.x ++;
			_speciePos.y ++;
		} 
		else {
			_speciePos.y --;
			_speciePos.x ++;
		}
	}
	
	return _avalibleGrids;
}


void moveSpecie(coords oldPos, coords newPos, char icon){ // This is just provisional, i will save this and then ill try to use coords instead of powers of 2.
	map[oldPos.y][oldPos.x] = '.';
	map[newPos.y][newPos.x] = icon;
}


#endif
