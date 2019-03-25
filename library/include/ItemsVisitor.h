#ifndef _ITEMSVISITOR_H_
#define _ITEMSVISITOR_H_

#include "Key.h"
#include "Knife.h"
#include "Rifle.h"
#include "Cola.h"
#include "ChocoBar.h"
#include "Talisman.h"
#include "Torch.h"

class ItemsVisitor
{
    public:
    virtual void visit(Key *)  = 0;
    virtual void visit(Knife *)  = 0;
    virtual void visit(Rifle *, int)  = 0;
    virtual void visit(Cola *)  = 0;
    virtual void visit(ChocoBar *)  = 0;
    virtual void visit(Talisman *)  = 0;
    virtual void visit(Torch *)  = 0;
};

#endif
