#include <iostream>
#include <vector>
#include <map>
#include <set>
#define PB push_back
#define MP make_pair
#define X first
#define Y second
using namespace std;
typedef pair<string, int> Pair;

inline void round(map<string, int> &scores, string name, int score) {
	scores[name] += score;
}

string getWinner(map<string, int> &scores, vector<Pair> &roundScores) {
	int maxScore = 0;
	set<string> winners;
	
	for (map<string, int>::iterator it = scores.begin(); it != scores.end(); ++it) {
		if (it->Y > maxScore) {
			maxScore = it->Y;
			winners.clear();
			winners.insert(it->X);
		} else if (it->second == maxScore) {
			winners.insert(it->X);
		}
	}
	
	if (winners.size() > 1) {
		scores.clear();

		for (vector<pair<string, int> >::iterator it = roundScores.begin(); it != roundScores.end(); ++it) {
			round(scores, (*it).X, (*it).Y);

			if (scores[(*it).X] >= maxScore && winners.count((*it).X) == 1) {
				winners.clear();
				winners.insert(it->X);
				break;
			}	
		}
	}

	return *winners.begin();
}

int main() {
	int n, score, i;
	string name;
	map<string, int> scores;
	vector<Pair> roundScores;

	cin >> n;

	for (i = 0; i < n; ++i) {
		cin >> name >> score;
		roundScores.PB(MP(name, score));
		scores[name] += score;
	}

	cout << getWinner(scores, roundScores) << "\n";
	return 0;
}
