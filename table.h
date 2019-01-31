#ifndef table_h
#define table_h

#include <vector>
#include <map>
#include "record.h"
class table
{


	//map to store the name of the player with the amount of scores recorded.
	std::map<std::string, record> playersTable;
	
public:
	//adds a new score for the named player
	void add_score(const std::string &name, double score);
	
	//returns the total number of players for whom a score has been recorded
	int num_players() const;

	// returns the average of the best scores of all players
	double average_best() const;
   
	//returns the name of the player with the highest overall average.
	std::string best_overall() const;
    
	//returns the names of the 'n' players with the highest recent averages, in order with the highest first.
	std::vector<std::string> print_best_recent(int n) const;
	
	//returns the number of novice players.
	int novice_count() const;
	
};

#endif