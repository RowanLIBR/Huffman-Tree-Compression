
#include "HuffmanTree.h"
#include <unordered_map>
#include <queue>
#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <string.h>


namespace rekt
{

	// bool HuffmanTree::compare(HuffmanNode &a, HuffmanNode &b)
	// {

	// 	return a<b;

	// }

	HuffmanTree::HuffmanTree(std::string filename) // takes in a filename provided as an argument and generates a un-ordered map
	{
		
		;
		std::ifstream text(filename) ;
		char temp;
 
	while(text.get(temp))
	{
	
	 	auto search = medMep.find(temp); // iterator
    	if(search != medMep.end()) {
        (search->second)++; // increment frequency if found in map
       
    }
    else
    {
    	medMep.emplace(temp,1); // otherwise place in the unordered map
    	
    }

	
	}
	text.close();


				
}



	void HuffmanTree::constructNode() // constructs nodes based on the contents of un_ordered map, then inserts them into prio queue
	{
		auto iterator = medMep.begin();
		int pos = 0;
		
		while(pos != medMep.size())
		{
			
			
			HuffmanNode node(iterator->first,iterator->second);
		
			iterator++;
			
			
			pos++;
			
			pQueue.push(node);
			
			
		}

		
}


	void HuffmanTree::buildTree()
	{
			
			 while(pQueue.size()>=2) // if there is one left then that is the head of tree
			 {
				std::shared_ptr<HuffmanNode> left = std::make_shared<HuffmanNode>(pQueue.top()); // pop of the first two nodes
				pQueue.pop();
			 std::shared_ptr<HuffmanNode> right = std::make_shared<HuffmanNode>(pQueue.top());;
			 pQueue.pop();
			 int newFrequency = (*left).frequency+(*right).frequency; // add their frequencies together to create head node
			 std::shared_ptr<HuffmanNode> head (new HuffmanNode(newFrequency,left,right)); 
			pQueue.push(*head);	
				
			}
			top = std::make_shared<HuffmanNode>(pQueue.top());
			
			pQueue.pop();
			Traverse(top,"");

			
	}

	void HuffmanTree::Traverse(std::shared_ptr<HuffmanNode> top,std::string code)
	{
		
		if(top->left == NULL && top->right == NULL) // then we have reached leaf
		{
			mymap.insert(std::pair<char, std::string>(top->v,code));
			

		}
		if(top->left != NULL)
    	{
        	
        	Traverse(top->left, code+"0"); //concatonate and recurse always left first
    	}
    	 if(top->right != NULL)
    	{
    		
        	Traverse(top->right,code+"1");//concatonate and recurse
    	}
}
	

	void HuffmanTree::produceOutput(std::string file,std::string file2)
	{
		std::string buffer = "";
		char temp;
		std::ifstream text(file) ;
		while(text.get(temp))
		{
			buffer+=mymap.find(temp)->second; // create buffer string of "bytes"
		}
		char * cstr = new char [buffer.length()+1];
  		std::strcpy (cstr, buffer.c_str());
  		std::ofstream makeDatShit(file2+".txt"); 
  		std::ofstream headerStuff(file2+".hdr");
  		makeDatShit.write(cstr,std::strlen(cstr));

  		for(auto i = medMep.begin(); i!=medMep.end();i++)
  		{
  			headerStuff<<i->first<<" "<<i->second<<std::endl;
  		}
  		
  		
  		for(auto i = mymap.begin(); i!=mymap.end();i++)
  		{
  			headerStuff<<i->first<<" "<<i->second<<std::endl;
  		}
  		headerStuff.close();
  		makeDatShit.close();




  		  // COMPRESSION
		std::ofstream outf(file2+".rekt",std::ofstream::binary);
		
    	int i = 0;
		for (i = 0; i < buffer.length(); i+=8)
		{
    		unsigned char byte = 0;
    		std::string str8 = "";
    		
    		if (i + 8 < buffer.length())
        	str8 = buffer.substr(i, i + 8);
    	else
        str8 = buffer.substr(i, buffer.length());
    for (unsigned b = 0; b != 8; ++b)
    {
        if (b < str8.length())
            byte |= (str8[b] & 1) << b; 
        else
            byte |= 1 << b;
    }
   		 outf.put(byte);
}
		
		outf.close();


}
	}


