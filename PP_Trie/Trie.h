#pragma once

#include <string>
#include <memory>
#include "Node.h"

class Trie
{
public:
	Trie();
	Trie& Push(std::string& word);
	bool Contains(std::string& word) const;
private:
	std::shared_ptr<Node> mHead;
};