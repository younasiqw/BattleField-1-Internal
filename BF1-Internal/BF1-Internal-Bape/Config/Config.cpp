#include "Config.hpp"

void Config::read() {

	// Variables

	/* vector for converting variable names into strings */
	std::vector<std::string> names = {};

	/* iterate over all variables*/
	for (bool var : vars) {
		/* push variable name into vector */
		names.push_back(GET_VARIABLE_NAME(var));
	}

	/* iterate over variable names */
	int iter = 0;
	for (std::string var : names) {
		iter++;
		/* read json via variable names*/
		vars.at(iter) = JSON[var];
	}

	// Colors

}

void Config::write() {

	// Variables
	
	/* vector for converting variable names into strings */
	std::vector<std::string> names = {};

	/* iterate over all variables*/
	for (bool var : vars) {
		/* push variable name into vector */
		names.push_back(GET_VARIABLE_NAME(var));
	}

	int iter = 0;
	for (std::string var : names) {
		iter++;
		/* read json via variable names*/
		JSON[var] = (bool)vars.at(iter);
	}

	// Colors
}