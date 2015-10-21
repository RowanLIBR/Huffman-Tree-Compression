#include <unordered_map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "HuffmanNode.h"
#include "HuffmanTree.h"


using namespace std;
using namespace rekt;
int main(int argc, char *argv[]){ // driver class which inializes methods


	HuffmanTree t(argv[1]);
	t.constructNode();
	t.buildTree();
	t.produceOutput(argv[1],argv[2]);
	
}
