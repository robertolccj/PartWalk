#ifndef TVIZINHO_H
#define TVIZINHO_H

/* O objeto definido por esta classe possui tres
   atributos: id, ds e fm. Ele eh usado na classe
   TSitio para definir um vizinho. */

class TVizinho
{
  public:
  int id;    //Id
  double ds; //Distancia (modulo)
  double esx; //Vetor unitario na direcao x
  double esy; //Vetor unitario na direcao y
  double fm; //Fluxo de massa para o vizinho
  TVizinho(int,double,double,double,double);
  ~TVizinho(){}
};



#endif

