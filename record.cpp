#include "stdafx.h"
#include "record.h"
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

//the  method for an empty record
record::record() {

}

//when record is called in main with a score parameterized, it is added to the deque 'scores'
record::record(double s) :score(s) {
	scores.push_back(score);

}

//returns the size of the deque 'scores'
int record::size() {
	return scores.size();
}

//if the score that is being inputted is negative, error occurs "no negative score".
//Else it is stored in the deque 'stores'
void record::add_score(double score) {
	if (score < 0)
		throw domain_error("no negative score");
	scores.push_back(score);
}
//method for the best score inputted
double record::best_score() const {
	//if the deque size is empty= error
	if (scores.size() == 0)
		throw domain_error("no score in record");
	//declare iterator 'p' to start at the beggining of the deque 'scores'
	deque<double>::const_iterator p = scores.cbegin();
	//set variable 'best_score' to the index of the iterator 'p'
	double best_score = *p;
	//incremenet iterator 
	++p;
	//while iterator is not at the end of the deque 'scores'
	while (p != scores.cend()) {
		//if the current value of the iterator is greater the the best_score that was set
		if (*p > best_score)
			//best_score becomes the value of that current iterator
			best_score = *p;
		//increment the iterator
		++p;
	}
	//when at the end of the record, return the best score set.
	return best_score;
}
//method for the average of all the scores inputted
double record::overall_average() const {
	//if deque size 'scores' is empty, produce an error
	if (scores.size() == 0)
		throw domain_error("average of an empty record");
	//set the variable 'sumOfScores' to equal zero
	double sumOfScores = 0;
	//declaring an iterator for 'p' to iterate from the start of 'scores' deque until it reaches the end 
	typedef deque<double>::const_iterator iter;
	for (iter p = scores.cbegin(); p != scores.cend(); ++p)
		//each iteration, current value of sumOfScores is added to the value of the current iterator value 'p'
		sumOfScores += *p;
	//when reached at the end of deque score, return the sum of all scores added together
	//divided by the total size of the vector 'score'
	return sumOfScores / scores.size();

}
//method for the average of recent values added to the score
double record::recent_average() const {
	//if the deque 'scores' is empty, produce an error.
	if (scores.size() == 0)
		throw domain_error("average of an empty record");
	//declaring and initliasing variables
	double sumOfScores = 0;
	double numberOfTimesIterated = 0;

	//setting REVERSE iterator to 'p' to iterate through the vector 'scores' from the start(which becomes the last) 
	//to the end(which becomes first)
	typedef deque<double>::const_reverse_iterator iter;
	for (iter p = scores.crbegin(); p != scores.crend(); ++p) {
		//current value of sum of scores added to the current value of the value of the iterator 'p'
		sumOfScores += *p;
		//each time iterated, the variable 'numberOfTimesIterated' is increased by 1
		numberOfTimesIterated += 1;
		//if the number of increments has reached 10 times
		if (numberOfTimesIterated == 10) {
			//return the sum of the last 10 added scores divided by the number of times deque 'scores' iterated 
			//in other words; divide by 10
			return sumOfScores / numberOfTimesIterated;
		}
	}
	//else you return so far what has been added by the number of times the deque 'scores' has been iterated
	return sumOfScores / numberOfTimesIterated;
}

//method that will return  if the scores recorded is less than 10.
bool record::novice() const {
	return scores.size() < 10;
}



