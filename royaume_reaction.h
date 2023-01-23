#ifndef ROYAUMEREACTION_H
#define ROYAUMEREACTION_H
#include "royaume.h"
#include "royaume_effet.h"

class royaume_reaction : public royaume, public royaume_effet
{
private:
    /* data */
public:
    royaume_reaction(/* args */);
    ~royaume_reaction()=default;
};



#endif