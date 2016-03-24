#ifndef TSITIO_H
#define TSITIO_H

#include "TPosition.h"
#include "TVelocity.h"
#include "TVizinho.h"

/* Esta classe define o objeto TSitio, o qual possui 
   tres (4) atributos: id, posicao, velocidade, vizinhos[].
   Objeto usado na classe TMalha, para mapear um mesh. */

class TSitio: public TPosition, public TVelocity
{
  private:
  int id;
  
  public:
  std::vector<TVizinho> viz;
  bool iswall; //wall
  bool isperi; //CC Periodic

  void setId(int);
  int getId();

  //Funcao para adicionar um vizinho.
  void AddNeighbor(const TVizinho& _viz){viz.push_back(_viz);}

  //Retorna o 'fluxo de massa total' no sitio.
  double fmt();
    
  //Constructors and Desctructors
  
  TSitio(int,TPosition,TVelocity);
  ~TSitio(){}
};

#endif

