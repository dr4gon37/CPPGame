#ifndef _PUSHITEMVISITOR_H_
#define _PUSHITEMVISITOR_H_

#include "ItemsVisitor.h"
#include "Inventory.h"

class PushItemVisitor : public virtual ItemsVisitor
{
    private:
    //std::shared_ptr<Items> pushItemPtr;
    Inventory & inventory;
	public:
	PushItemVisitor(Inventory &);
	~PushItemVisitor();
    void visit(Key *);
    void visit(Knife *);
    void visit(Rifle *, int);
    void visit(Cola *);
    void visit(ChocoBar *);
    void visit(Talisman *);
    void visit(Torch *);
};

#endif
