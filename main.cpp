#include <iostream>
#include <string>
#include "structs/coords.hpp"
#include "map/map.hpp"
#include "species/species.hpp"
#include "system/system.hpp"

int main(){
	initializeSpecies();
	activateLoop();
	return 0;
}
