#include <string>
#include <memory>
#include "Trie.h"


Trie::Trie() : mHead(std::make_shared<Node>())
{
}

Trie& Trie::Push(std::string& word)
{
	std::shared_ptr<Node> q = mHead;
	for (char l : word)
	{
		if (((int)l > 64) && ((int)l < 91))
			l = l + 32;
		if (((int)l > 96) && ((int)l < 123))
		{
			if (q->Pointer((int)l % 97) == nullptr)
				q->AddPtr((int)l % 97);
			q = q->Pointer((int)l % 97);
		}
	}
	q->SetEnd();
	return *this;
}

bool Trie::Contains(std::string& word) const
{
	std::shared_ptr<Node> q = mHead;
	for (char l : word)
	{
		if (((int)l > 64) && ((int)l < 91))
			l = l + 32;
		if (((int)l > 96) && ((int)l < 123))
		{
			if (q->Pointer((int)l % 97) != nullptr)
				q = q->Pointer((int)l % 97);
			else
				return false;
		}
	}
	if (q->IsEnd())
		return true;
	else
		return false;
}
