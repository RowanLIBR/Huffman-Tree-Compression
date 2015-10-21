#include "HuffmanNode.h"
#include <vector>
#include <iostream>


namespace rekt{

	HuffmanNode::HuffmanNode(char val, int i)
	{
		
		
		v = val;
		frequency = i;
		

	}

	
	HuffmanNode::~HuffmanNode()
	{

	}
	HuffmanNode::HuffmanNode(int freq, std::shared_ptr<HuffmanNode> l,std::shared_ptr<HuffmanNode> r) // constructor
	{
		frequency = freq;
		left = l;
		right = r;
	}

	HuffmanNode::HuffmanNode()
	{
		
	}

	HuffmanNode::HuffmanNode(const HuffmanNode &copy) // definition for copy constructor
	{
		
			right.reset();
			left.reset();
			v = copy.v;
			frequency = copy.frequency;
			left = copy.left;
			right = copy.right;
		

	}

	HuffmanNode::HuffmanNode(HuffmanNode &&move) //definition for move constructor
	{
		left.reset();
						right.reset();
						v = move.v;
						frequency = move.frequency;
						left = move.left;
						right = move.right;
						move.v = '\0';
						move.frequency = 0;
						move.left.reset();
						move.right.reset();
	}


	

	


}

