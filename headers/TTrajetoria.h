#ifndef _TTRAJETORIA_H
#define _TTRAJETORIA_H

// Objeto com a trajetoria de uma partícula, que caminha no objeto
// definido no primeiro parametro, e cuja posicao inicial esta
// definida no argumento da funcao start().

#include "TPasso.h"
#include "TLMonitor.h"

class TTrajetoria
{
private:
  const TMalha malha;
  std::vector<TPasso> passo;
  double tempo;
  TLMonitor lmon;

public:
  double CalculaTempo(int, int);
  void start(int);
  double LastPx();
  void LMonChk();
  TLMonitor getLMon();
  double GetTime();
  void Caminhar();
  bool CheckPossibleViz(const TVizinho&);
  int NPassos();
  void Salvar(std::string);//Salvar no arquivo com nome: 'string'

  TTrajetoria(TMalha,TLMonitor);
  ~TTrajetoria(){}
};

#endif

