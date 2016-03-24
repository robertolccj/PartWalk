#ifndef TITEMPROB_H
#define TITEMPROB_H

class TItemProb
{
public:
 int id;
 double prob;

 TItemProb(int,double);
 ~TItemProb(){}
};

int Escolhe(std::vector<TItemProb>);

#endif

