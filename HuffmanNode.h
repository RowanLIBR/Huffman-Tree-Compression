#ifndef HUFFMANNODE
#define HUFFMANNODE
#include <string>
#include <vector>
#include <memory>


namespace rekt
{
	class HuffmanNode
	{
		private:
				
				
				
				


		public:
				char v;
				int frequency;
			
				std::shared_ptr<HuffmanNode> left; // "children" pointers to nodes
				
				std::shared_ptr<HuffmanNode> right;

				HuffmanNode(char val, int i);
				HuffmanNode(int freq, std::shared_ptr<HuffmanNode> l,std::shared_ptr<HuffmanNode> r);
				
				~HuffmanNode();
				HuffmanNode(const HuffmanNode &copy);
				HuffmanNode(HuffmanNode &&move);
				HuffmanNode();

				

				

				bool operator< (const HuffmanNode& a) const
				{

					return (frequency < a.frequency );
				}

				HuffmanNode operator= (const HuffmanNode& other) // copy operator method
				{
					if(this != &other)
					{
						left.reset();
						right.reset();
						v = other.v;
						frequency = other.frequency;
						left = other.left;
						right = other.right;
					}
					return *this;
				}
				HuffmanNode operator= (HuffmanNode&& other) // move operator method
				{
					if(this != &other)
					{
						left.reset();
						right.reset();
						v = other.v;
						frequency = other.frequency;
						left = other.left;
						right = other.right;
						other.v = '\0';
						other.frequency = 0;
						other.left.reset();
						other.right.reset();
					}
					return *this;
				}

			
				

				



	};

}
#endif