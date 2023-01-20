#ifndef ROYAUME_H
#define ROYAUME_H
#include "carte.h" 

class royaume : public Carte
{
private:
    /* data */
public:
    royaume(std::string name, int cost, bool d):Carte(name,cost, TypeCarte::Action,d){};
};




#endif