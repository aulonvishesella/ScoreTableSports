#include "stdafx.h"
#include "table.h"
#include "record.h"
#include <vector>
#include <map>
#include <algorithm>
#include "record.h"
using namespace std;

//a method to add a score to the table for the specific player. Given a name.
void table::add_score(const string &name, double score) {
	playersTable[name].add_score(score);
}

//method the number of players that has recorded a score.
int table::num_players() const {
	return playersTable.size();
}
//method used to return the average of the BEST scores entered for a specific player.
double table::average_best() const {
	//if an empty table
	if (playersTable.size() == 0)
		throw domain_error("average of an empty record of plays");

	//iterator to parse through the map of the table
	map<string, record>::const_iterator p = playersTable.cbegin();
	double best_score = p->second.best_score();
	double sumOfScores = 0;

	for (p; p != playersTable.cend(); ++p)

		//sum of scores added each increment.
		sumOfScores += (*p).second.best_score();
	//return the average of the best score from a player.
	return sumOfScores / playersTable.size();
}

//method used to return the name of the player with the best AVERAGE.
string table::best_overall() const {

	//if an empty table
	if (playersTable.size() == 0)
		throw domain_error("no score in record");
	map<string, record>::const_iterator p = playersTable.cbegin();
	//the best score is set to the value of the overall average to the value it is looking at
	//that uses the method (overall_average()) to determine the average of that particular item.
	double best_score = (*p).second.overall_average();
	string best_name = (*p).first;
	++p;

	while (p != playersTable.cend()) {

		//checks to see if the current overall average of the iterator is less then the value of
		//best_score
		if ((*p).second.overall_average() > best_score) {
			best_score = (*p).second.overall_average();
			best_name = (*p).first;
		}

		++p;

	}
	//return the best name that is at that specific index using the best_score to determine that index.
	return best_name;
}

