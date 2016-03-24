#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
//#include<ctime>

#include "Funcoes.h"

#include "TLine.h"
#include "TMalha.h"
#include "TTrajetoria.h"

using namespace std;

int main(int argc, char *argv[])
{
cout << "#......" << endl;

//Precisa carregar 2 arquivos de dados. Um para os dados
//do campo de velocidade (fluido), o outro com os id das
//celulas onde as particulas iniciam o percurso.
if (argc<3){
  cout << "Precisa de 2 argumentos!" << endl;
  cout << "Ex: ./a.out dados1.dat dados2.dat" << endl;
  exit(1);
}

//Armazenando os nomes dos arquivos de
//dados de entrada para posterior uso.
string file_data=argv[1];
string file_line=argv[2];
string file_id= GetBaseName(file_data);
cout << "#Dados:" << file_data << ", Lines:" << file_line << endl;
cout << "#File ID:" << file_id << endl;

//Objeto com mapa do mesh. Necessario colunas compativeis.
TMalha Web(file_data);

//Salvar estrutura da malha
Web.Salvar( "geo_mesh_" + file_id + ".dat" );
Web.SaveWall("geo_wall_" + file_id + ".dat");
Web.SavePeriodic("geo_periodic_" + file_id + ".dat");

//Gera serie de dados aleatorios a cada execucao do programa.
//srand(time(NULL)); //needs include ctime
srand(2);

//Objeto com os ids dos sitios de posicao inicial das particulas.
TLine line(file_line);

std::vector <TLMonitor> VecLMonitor;

TLMonitor teste(0,100,10);
teste.addTime(2.0);
std::cout<<"Tamanho: "<< teste.line[1].px <<std::endl;

//exit(0);
//Objeto com a trajetoria da particula sobre a malha passada no argumento.
TTrajetoria Trajeto(Web,teste);
//TTrajetoria Trajeto(Web,LMonLin(0,100,5));
//TTrajetoria Trajeto(Web,LMonLog(0,100,5));

for (int j=0; j<line.id.size(); j++) //Numero de pontos de lancamento.
{
  cout << "#id: " << line.id[j] << endl;

  for (int i=0; i<100; i++) //Numero de particulas lancadas de cada ponto.
  {

	Trajeto.start(line.id[j]); //clean trajeto and starts!

    while ( Trajeto.NPassos() < 2000 && Trajeto.LastPx() <= 100.0 )
    {
       Trajeto.Caminhar(); //Precisa ser inicializado - start()
       Trajeto.LMonChk(); //IMPLEMENTAR !!!
    }
	VecLMonitor.push_back(Trajeto.getLMon());
    cout << i << " " << j << " " << Trajeto.GetTime() << endl;

  //if ( (i==0 || i==10 || i==20) && (j==25 || j==125 || j==75) )
  if (i==10 && j==75)
    {
      char nome[20];
      sprintf(nome,"trajeto_%.3d_%.3d.dat",j,i);
      Trajeto.Salvar(nome);
    }

  }
}

//Salvar LMonitor Aqui!!!
//Em cada linha do file_output, os tempos em todas as linhas.
//Se houverem 10 line_monitor, o file_output tera 10 colunas.
std::ofstream myfile;
std::string file_ltimes= "lines_times_" + file_id + ".dat";
myfile.open(file_ltimes.c_str());
for (int i=0; i<VecLMonitor.size(); i++)
  {
  myfile << VecLMonitor[i] << std::endl;
  }
myfile.close();

return 0;
}
