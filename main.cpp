#include <iostream>
#include "map/map.hpp"
#include "species/species.hpp"

using namespace std;

int main(){
	actualizeMap();
	Species first;
	cout << first.getPos() -> x << '\n';
	coords ava;
	ava.x = 1;
	ava.y = 1;
	coords* grid;
	cout << "before it starts." << '\n';
	grid = avalibleGrids(ava);
	cout << grid -> x << '\n';
	cout << grid -> y << '\n';
	grid++;
	cout << grid -> x << '\n';
	cout << grid -> y << '\n';
	grid++;
	cout << grid -> x << '\n';
	cout << grid -> y << '\n';



	//cout << avalibleGrids(0,0) << '\n';
	return 0;
}
