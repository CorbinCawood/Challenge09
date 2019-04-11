/*
 *Corbin Cawood
 *10th April 2019
 *Challenge 09 - Sequence Alignment
 *COSC 302
 *Dr. Scott Emrich
 *
 *Description: This program takes strings through cin and produces the final
 *sequence alignment score as defined in the challenge write up.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char *argv[]) {

	ifstream inFile;
	string seq1;
	string seq2;
	vector<int> scoreBoard;
	vector<int> mostVec;
	vector<int>::iterator vit;
	string temp;
	int i;
	int j;
	int rowLength;
	int colLength;
	int boardSize;

	//Read in the first sequence and push_back '!' for the gap character

	seq1 = "!";
	seq2 = "!";

	getline(cin, temp);
	seq1 += temp;
	getline(cin, temp);
	seq2 += temp;

	rowLength = seq1.length();
	colLength = seq2.length();


	for(i = 0; i < colLength; i++){
		for(j = 0; j < rowLength; j++){
			boardSize = scoreBoard.size();
			if(seq1.at(j) == seq2.at(i)){
				if(seq1.at(j) == '!'){
					scoreBoard.push_back(0);
				}
				else{
					scoreBoard.push_back(scoreBoard.at(boardSize - rowLength - 1) + 1);
				}
			}
			else{
				
				if(boardSize-rowLength >= 0){
					mostVec.push_back(scoreBoard.at(boardSize-rowLength));
				}
				if(j-1 >= 0){
					mostVec.push_back(scoreBoard.at(boardSize -1));
				}

				if(boardSize-rowLength >= 0 && j-1 >= 0){
					mostVec.push_back(scoreBoard.at(boardSize-rowLength-1));
				}

				sort(mostVec.begin(), mostVec.end());

				vit = mostVec.end();
				vit--;
				scoreBoard.push_back(*vit-1);
				mostVec.clear();
			}
		}
	}

	vit = scoreBoard.end();
	vit--;
	cout << *vit << endl;
}
