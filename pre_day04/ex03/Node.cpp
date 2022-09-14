#include "Node.hpp"

Node::Node(void) : materia(0), next(0) {};

Node::Node(AMateria * const materia)
{
	this->materia = materia;
	this->next = 0;
};

Node::Node(const Node &src) : materia(src.materia), next(src.next) {};

Node::~Node(void) {};

Node &Node::operator=(const Node &rhs)
{
	if (this != &rhs)
	{
		this->materia = rhs.materia;
	}
	return *this;
};

void Node::setMateria(AMateria *const materia)
{
	if (this->materia != materia)
	{
		this->materia = materia;
	}
	return;
};

AMateria * Node::getMateria() const
{
	return materia;
};

void Node::setNext(Node * const node)
{
	if (this->next != node)
	{
		this->next = node;
	}
	return;
};

Node *Node::getNext(void) const
{
	return next;
};
