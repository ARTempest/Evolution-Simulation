#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H


Species specieArr[10];
int specieAmount = 2;

void initializeSpecies(){

	Species specie1({1,1}, 1, 'a'), specie2({7,7}, 1, 'b');
	
	specieArr[0] = specie1;
	specieArr[1] = specie2;

	for (int i=0; i < specieAmount; i++){
		spawnSpecie(specieArr[i].getPos(), specieArr[i].getDiet());
	}

	actualizeMap();
}

void activateLoop(){
	std::string line;

	getline(std::cin, line);
	
	while (line != "stop"){
		getline(std::cin, line);
		
		for (int i=0; i < specieAmount; i++) {
			coords speciePosBefore = specieArr[i].getPos();
			coords* specieAvaPos = avalibleGrids(speciePosBefore);

			specieArr[i].sendAvaPos(specieAvaPos);
			
			specieArr[i].move();
			moveSpecie(speciePosBefore, specieArr[i].getPos(), specieArr[i].getDiet());
		}
		
		actualizeMap();

	}
}

#endif

