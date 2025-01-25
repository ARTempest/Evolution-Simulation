#include <iostream>
#include "map/map.hpp"
#include "species/species.hpp"

using namespace std;

int main(){
	actualizeMap();
	Species first;
	cout << first.getPos() -> x << '\n';

	cout << avalibleGrids(0,0) << '\n';
	return 0;
}
