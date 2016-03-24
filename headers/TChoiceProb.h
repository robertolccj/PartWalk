#ifndef TCHOICEPROB_H
#define TCHOICEPROB_H

/* Esta classe defini um objeto que possui 3 atributos.
   Usada para criacao de vetor, para escolha do elemento id
   sorteado usando (rand) baseado na densidade de probabilidade
   deste elemento.*/

class TChoiceProb
{
private:
 double prob; //densidade de probabilidade do elemento
 double rand; //numero aleatorio sorteado
 double subtract; //subtraicao fasb(rand-prob)

public:
 int id;

 //Sobrecarga de Operado <
 friend bool operator < (const TChoiceProb& vec1, const TChoiceProb& vec2)
 { return (vec1.subtract < vec2.subtract); }
 
 //Construtor
 TChoiceProb(int,double,double);
 ~TChoiceProb(){}
};

#endif

