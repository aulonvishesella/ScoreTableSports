#ifndef record_h
#define record_h

#include <vector>
#include <deque>
class record
{   //deque of doubles called 'scores'. This will store all the score values entered.
	std::deque<double> scores;
	std::string name;
public:
	//method of an empty score
	record();
	//method of a record to enter a single value score to the vector 'scores'
	record(double score);
	//method to add a score to the vector 'scores'
	void add_score(double score);
	//method to retrieve the best score from the vector 'scores'
	double best_score() const;
	//method to achieve the overall averagre from all the scores entered in the 'scores' record.
	double overall_average() const;
	//method to achieve the average from the last 10 scores entered in the 'scores' record.
	double recent_average() const;
	//method that used if only the size of the vector 'scores' is less than 10.
	bool novice() const;
	
	int size();
	
	//added getters and setters that will be needed for the table 
	const std::string &get_name() const { 
		return name; 
	};
	void set_name(std::string name) {
		record::name = name
	; }

private:
	double score;
};


#endif