#pragma once

#include <memory>
#include <vector>

class Node
{
public:
	Node();
	bool IsEnd() const;
	Node& SetEnd();
	Node& AddPtr(int index);
	std::shared_ptr<Node> Pointer(int index) const;
private:
	bool mEnd;
	std::vector<std::shared_ptr<Node>> mLetters;
};