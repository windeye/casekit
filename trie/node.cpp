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

#include "node.h"

Node::Node()
{
  key = '\0';
	valid = false;
}

char Node::getKey()
{
	return key;
}

bool Node::getValid()
{
	return valid;
}

void Node::setKey(char ch)
{
	key = ch;
}

void Node::setValid()
{
	valid = true;
}

void Node::appendChild(Node* child)
{
	nodes.push_back(child);
}

std::vector<Node*> Node::children()
{
	return nodes;
}

Node* Node::findChild(char ch)
{
	for (unsigned i = 0; i < nodes.size(); i++) {
		Node *temp = nodes.at(i);
		if (ch == temp->getKey())
			return temp;
	}

	return NULL;
}
