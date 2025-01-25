#pragma once
#ifndef RANDOM_H
#define RANDOM_H

#include <iostream>
#include <random>

int generateNumber(int minimum, int maximum){
	int number;

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(minimum, maximum);

	number = dist(rng);

	return number;

}


#endif
