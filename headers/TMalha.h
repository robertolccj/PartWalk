#ifndef TMALHA_H
#define TMALHA_H

#include "TSitio.h"

class TMalha
{
  private:
  void Check();
  void AddSitio(int,TPosition,TVelocity);
  void AddNeighLastSite(int,double,double,double,double);

  public:
  std::vector<TSitio> sitio;

  int Tamanho();
  void Salvar(std::string);
  void SaveWall(std::string);
  void SavePeriodic(std::string);

  TMalha(std::string);
  ~TMalha(){/* Destrutor */}
};

#endif

