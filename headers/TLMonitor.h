#ifndef TLMONITOR_H
#define TLMONITOR_H

class TAux;

class TLMonitor
{
private:
int count; //inicializado no construtor

public:
double pxi;
double pxf;
int tam;
std::vector <TAux> line;//inicializado no construtor

 std::vector <double> outpxs();
 double lpx();
 void addTime(double);
 void clearTime();
 TLMonitor(double,double,int);
 TLMonitor(double,double,int,double);//potencia
~TLMonitor(){}

friend std::ostream& operator <<(std::ostream &os,const TLMonitor &obj);
};


class TAux
{
public:
  double px;
  double time;

TAux(double a,double b):px(a),time(b){}
~TAux(){}
};

#endif

