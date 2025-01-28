#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H


Species specieArr[10];
int specieAmount = 1;

void initializeSpecies(){

	Species specie1({1,1}, 1, 'a', 100, 5), specie2({7,7}, 1, 'b', 100, 5);
	
	specieArr[0] = specie1;
	//specieArr[1] = specie2;

	for (int i=0; i < specieAmount; i++){
		spawnSpecie(specieArr[i].getPos(), specieArr[i].getDiet());
	}

	actualizeMap();
}

void activateLoop(){
	std::string line;

	getline(std::cin, line);
	
	while (line != "stop"){
		
		for (int i=0; i < specieAmount; i++) {
			coords speciePosBefore = specieArr[i].getPos();
			coords* specieAvaPos = avalibleGrids(speciePosBefore);

			specieArr[i].sendAvaPos(specieAvaPos);
			
			specieArr[i].actions();
			std::cout << specieArr[i].getHungry() << '\n';
			moveSpecie(speciePosBefore, specieArr[i].getPos(), specieArr[i].getDiet());
		}
		
		actualizeMap();

		getline(std::cin, line);
	}
}

#endif

