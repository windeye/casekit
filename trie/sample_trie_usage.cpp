/*
 * This software uses a Trie to return the longest word that is formed
 * using other words within a given list of words.
 * Copyright (C) 2013 Gagan Mac
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * Please visit http://www.gnu.org/licenses/ for a copy of the
 * GNU General Public License.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include "trie.h"

using namespace std;

string getLongestWord(ifstream *file)
{
  Trie *trie = new Trie();
	string x;
	typedef vector<string> STRVEC;
	std::queue<STRVEC> wordqueue;
	unsigned stat = 0;

	while(*file>>x) {
		vector<string> prefixvec;
		trie->getPrefixes(&prefixvec, x);
		vector<string>::const_iterator pi;
		for (pi = prefixvec.begin(); pi != prefixvec.end(); pi++) {
			vector<string> prefixWordPair;
			prefixWordPair.push_back(*pi);
			prefixWordPair.push_back(x);
			wordqueue.push(prefixWordPair);
		}

		trie->addWord(x);
	}
	file->close();

	/* Check the queue for prefixes missed out due to
	 * adding words later.
	 */
	string longestword[2];
	unsigned longest[2] = {0, 0};
	while(wordqueue.size() > 0) {
		string word, suffix;
		STRVEC strvec;
		strvec = wordqueue.front();
		wordqueue.pop();
		word = strvec.back();
		strvec.pop_back();
		suffix = strvec.back();
		strvec.pop_back();
		if (trie->searchWord(suffix)) {
			stat++;
			if (word.length() > longest[0]) {
				longestword[0] = word;
				longest[0] = word.length();
			} else if (word.length() >= longest[1]) {
				longestword[1] = word;
				longest[1] = word.length();
			}
		} else {
			STRVEC prefixvec;
			trie->getPrefixes(&prefixvec, suffix);
			vector<string>::const_iterator pi;
			for (pi = prefixvec.begin(); pi != prefixvec.end(); pi++) {
				vector<string> prefixWordPair;
				prefixWordPair.push_back(*pi);
				prefixWordPair.push_back(word);
				wordqueue.push(prefixWordPair);
			}
		}
	}

	cout<<"\n\nStats: ";
	cout<<"\nTotal number of words: \t"<<trie->getNumWords();
	cout<<"\nNumber of words formed from other words: \t"<<stat<<endl;
	cout<<"\nThe longest word: \t\t"<<longestword[0]<<"\t"<<longest[0]<<" letters";
	cout<<"\nSecond longest word: \t\t"<<longestword[1]<<"\t"<<longest[1]<<" letters"<<endl<<endl;
	return longestword[0];
}

void displayHelp()
{
	cout<<endl<<endl<<"HELP"<<endl;
	cout<<"Usage:\n";
	cout<<"wordstat <input-file-name>\n"
		<<"Note: If input file is not in the same directory"
		" as the tool, please provide complete path\n\n";
}

int main(int argc, const char *argv[])
{
	const char* filename = argv[1];

	if (!filename) {
		cerr<<"\n\nERROR running wordstat. No filename";
		displayHelp();
		return 0;
	}

	ifstream file(filename);
	if (file) {
		getLongestWord(&file);
	} else {
		cerr<<"\n\nERROR running wordstat. Couldn't open file named: "<<filename;
		displayHelp();
	}

	return 0;
}
