#ifndef HUFFMANTREE
#define HUFFMANTREE
#include "HuffmanNode.h"
#include <unordered_map>
#include <queue>
#include <memory>
#include <iostream>
#include <string>
#include <map>

namespace rekt
{
	class Comparator // comparator class that is provided to priority queue
	{
	public:
			bool operator() (const HuffmanNode& lhs, const HuffmanNode& rhs) const
			{
				

				return !(lhs<rhs);
			}
			

	};

	class HuffmanTree 
	{
		private:
				 
				 
				 
		public:
				std::priority_queue<HuffmanNode,std::vector<HuffmanNode>,Comparator> pQueue;
				 std::shared_ptr<HuffmanNode> top;
				 std::string fileOut;
				 std::map<char,std::string> mymap;
				
				std::unordered_map<char,int> medMep;
				HuffmanTree(std::string file);

				bool compare(HuffmanNode &a, HuffmanNode &b);

				void constructNode();

				void buildTree();

				void Traverse(std::shared_ptr<HuffmanNode> top, std::string code);

				void produceOutput(std::string file,std::string file2);




		
			
		

	};


}
#endif
