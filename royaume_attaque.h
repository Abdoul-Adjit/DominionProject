#ifndef ROYAUMEATTAQUE_H
#define ROYAUMEATTAQUE_H
#include "royaume.h"
#include "royaume_effet.h"
class royaume_attaque : public royaume, public royaume_effet
{
private:
    /* data */
public:
    royaume_attaque(/* args */);
    ~royaume_attaque();
};



#endif