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

#ifndef __NODE_H
#define __NODE_H

#include <vector>
class Node {
  	    char key;
		// Denotes the valid word ends here.
		bool valid;
		std::vector<Node*> nodes;
	public:
		Node();
		~Node() {}
		char getKey();
		bool getValid();
		void setKey(char ch);
		void setValid();
		void appendChild(Node* child);
		std::vector<Node*> children();
		Node *findChild(char ch);
};
#endif
