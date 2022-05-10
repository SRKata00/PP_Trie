#include <vector>
#include <memory>
#include "Node.h"

Node::Node()
	:mEnd(false), mLetters(26, nullptr)
{
}

bool Node::IsEnd() const
{
	return mEnd;
}

Node& Node::SetEnd()
{
	mEnd = true;
	return *this;
}

Node& Node::AddPtr(int index)
{
	mLetters[index] = std::make_shared<Node>();
	return *this;
}

std::shared_ptr<Node> Node::Pointer(int index) const
{
	return mLetters[index];
}