#include <iostream>
#include "map/map.hpp"
#include "species/species.hpp"

using namespace std;

int main(){
	Species first;
	cout << first.getPos() -> x << '\n';
	coords oldPos = *first.getPos();

	spawnSpecie(first.getPos(), first.getDiet());
	actualizeMap();
	coords ava = {1,1};

	coords* grid;
	
	cout << "before it starts." << '\n';
	grid = avalibleGrids(ava);
	first.sendAvaPos(grid);
	first.move();
	

	coords newPos = *first.getPos();
	char* icon = first.getDiet();


	cout << "x: " << oldPos.x << " y: " << oldPos.y << '\n';
	cout << "x: " << newPos.x << " y: " << newPos.y << '\n';


	moveSpecie(oldPos, newPos, icon);
	actualizeMap();
	

	//cout << avalibleGrids(0,0) << '\n';
	return 0;
}
