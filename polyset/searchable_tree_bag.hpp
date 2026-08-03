#pragma once
#include "searchable_bag.hpp"
#include "tree_bag.hpp"

class searchable_tree_bag: public tree_bag , public searchable_bag{

public:
	virtual bool has(int value) const{

		node *curr = tree;
		while (curr)
		{
			if (curr->value == value)
				return true;
			else if (curr->value > value)
				curr = curr->l;
			else
				curr = curr->r;
		}
		return false;
	}
};