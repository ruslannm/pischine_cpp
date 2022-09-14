#ifndef NODE_HPP
#define NODE_HPP

class AMateria;

class Node
{
public:
	Node(void);

	Node(AMateria * const);

	Node(const Node &);

	~Node(void);

	Node &operator=(const Node &);

	void setMateria(AMateria * const);

	AMateria *getMateria(void) const;

	void setNext(Node * const);

	Node *getNext(void) const;

private:
	AMateria *materia;
	Node *next;
};

#endif
