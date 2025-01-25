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



// y = -1    y = 0     y = 1      y = 0
// x =  0    x = -1    x = 0      x = 1



/*int avalibleGrids(int posX, int posY) {
	int direction = 1;
	int _avalibleGrids = 0;
	int x= posX;
	int y= posY - 1;



	for (int i=1; i <= 4; i++){


		//std::cout << i << ". x: " << x << '\n';
		//std::cout << i << ". y: " << y << '\n';
		
		if (map[y][x] == '.'){
			_avalibleGrids += direction; // Make an array with a permanent length of 4, and fill it with the coords you can move, but also the ones you cant move and since you are sending the length of the "array" with possible movements like even if it is 4 elements you give a length of 2 then it is gonna select between the first 2, and also the ones that you cant move you put them in the last part of the array, like -1, -2, -3.
		}


		direction *= 2;

		if (y < posY){
			x--;
			y++;
		} else if (y == posY) {
			x++;
			y++;
		} else {
			y--;
			x++;
		}
	



	}

	return _avalibleGrids;
}

*/



coords* avalibleGrids(coords speciePos){
	int index = 1;

	coords _speciePos = speciePos;
	_speciePos.y -= 1;

	static coords _avalibleGrids[5]; // Gotta find a solution for this problem this variable should be inside of the function bellow.
	_avalibleGrids[0] = speciePos;


	for (int i=1; i <= 4; i++){
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





void moveSpecie(coords oldPos, coords newPos){ // This is just provisional, i will save this and then ill try to use coords instead of powers of 2.
	map[oldPos.y][oldPos.x] = '.';
	map[newPos.y][newPos.x] = 'H';
}


#endif
