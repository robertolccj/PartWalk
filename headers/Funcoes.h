#ifndef _FUNCOES_H
#define _FUNCOES_H

//-------------------------------------------------------------------
// MANIPULA STRING
// Funcao: retira identificador do arquivo, ou melhor, retira a
// string entre o ultimo '_' e o primeiro '.' apos.
// Ex: file_name_s01.txt.gz -> s01

std::string GetBaseName(const std::string &_str)
 {
  int p1= _str.find_last_of('_')+1;
  int p2= _str.size();
  std::string str1= _str.substr(p1,p2);

  int p3= str1.find_first_of('.');
  std::string str2= str1.substr(0,p3);

  return str2;
 }
//-------------------------------------------------------------------

// Fazer Classe que recebe uma string (linha) que contem
// dados dispostos em colunas, e pode entao retornar:
// TObjeto Objeto(string) //construtor
// Objeto.NumOfCols();
// Objeto.Col(1);

#endif

