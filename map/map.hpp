#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>

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


// Think about pros and cons of changing the map array for various strings to don't have to print so many times something and use the map as something that will actualize only the cells that are needed and will print only when all animals/species have finish their turn/action,

void actualizeMap(){

	for (int y=0; y < mapSizeY; y++){
		std::cout << map[y] << '\n';
	}
}



// y = -1    y = 0     y = 1      y = 0
// x =  0    x = -1    x = 0      x = 1


int avalibleGrids(int posX, int posY) {
	int direction = 1;
	int _avalibleGrids = 0;
	int x= posX;
	int y= posY - 1;



	for (int i=1; i <= 4; i++){


		std::cout << i << ". x: " << x << '\n';
		std::cout << i << ". y: " << y << '\n';
		
		if (map[y][x] == '.'){
			_avalibleGrids += direction;
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


#endif
