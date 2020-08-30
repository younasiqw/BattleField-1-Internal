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
	std::vector<std::string> namesColors = {};

	/* iterate over all variables*/
	for (bool var : vars) {
		/* push variable name into vector */
		names.push_back(GET_VARIABLE_NAME(var));
	}

	int iter = 0;
	for (std::string var : names) {
		iter++;
		/* write json via variable names*/
		JSON[var] = (bool)vars.at(iter);
	}

	// Colors
	for (ImColor var : colors ) {
		/* push variable name into vector */
		namesColors.push_back(GET_VARIABLE_NAME(var));
	}

	for (std::string var : namesColors) {
		iter++;

		double colorArray[4] = { colors.at(iter).Value.x, colors.at(iter).Value.y, colors.at(iter).Value.z, colors.at(iter).Value.w };

		/* write json via variable names*/
		JSON[var] = colorArray;
	}

	/* write json object to file */
	file << JSON;

	file.close();
}