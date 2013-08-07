/*
 * This file implements a Trie.
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
#include "trie.h"
#include "node.h"

using namespace std;
Trie::Trie()
{
  root = new Node();
	nwords = 0;
}

Trie::~Trie()
{
}

void Trie::addWord(std::string s)
{
	Node *curr = root;
	if (s.length() == 0) {
		curr->setValid();
		return;
	}

	for (unsigned i = 0; i < s.length(); i++) {
		Node *child = curr->findChild(s[i]);
		if (child != NULL) {
			curr = child;
			curr->getValid();
		}
		else {
			Node *temp = new Node();
			temp->setKey(s[i]);
			curr->appendChild(temp);
			curr = temp;
		}

		if (i == s.length() - 1) {
			curr->setValid();
			nwords++;
		}
	}
}

bool Trie::searchWord(std::string s)
{
	Node *curr = root;

	while (curr != NULL) {
		for (unsigned i = 0; i < s.length(); i++) {
			Node *temp = curr->findChild(s[i]);
			if (temp == NULL)
				return false;
			curr = temp;
		}

		if (curr->getValid())
			return true;
		else
			return false;
	}

	return false;
}

void Trie::getPrefixes(std::vector<std::string> *strvec, std::string s)
{
	unsigned i = 0;
	std::string prefix;
	Node *curr = root;

	for (i = 0; i < s.length(); i++) {
		Node *temp = curr->findChild(s[i]);
		if (!temp)
			return;
		curr = temp;
		prefix += curr->getKey();
		if (curr->getValid()) {
			std::string temp;
			temp = s.substr(prefix.length());
			strvec->push_back(temp);
		}
	}
}
