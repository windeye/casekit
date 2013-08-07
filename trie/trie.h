/*
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

#ifndef __TRIE_H
#define __TRIE_H
#include<string>
#include<vector>
#include "node.h"

class Trie {
  Node *root;
	unsigned long nwords;

	public:
		Trie();
		~Trie();
		void addWord(std::string s);
		bool searchWord(std::string s);
		void delWord(std::string s);
		void getPrefixes(std::vector<std::string> *strvec,
			std::string s);
		unsigned long getNumWords()
		{
			return nwords;
		}
};
#endif
