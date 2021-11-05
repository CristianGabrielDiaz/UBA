#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

//IMPLENTACION PROBLEMA 1
bool esValida(eph_h th, eph_i ti);

bool esMatriz(vector<vector<int>> m);
/*
int cantItemHogar;

int cantItemInd;
*/

bool sinRepetidosEnIndividuos(eph_i ti);

bool sinRepetidosEnHogares(eph_h th);

bool hogaresAsociadosIndividuos(eph_h th, eph_i ti);

bool mismoAnioYTrimestre(eph_h th,eph_i ti);

bool mismoAnioHogares(eph_h th);

bool mismoAnioIndividuos(eph_i ti);

bool mismoTrimestreHogares(eph_h th);

bool mismoTrimestreIndividuos(eph_i ti);

bool iv2MayorOIgualIi2(eph_h th);

bool rangosValidos(eph_h th, eph_i ti);

bool rangoCodusu(eph_h th, eph_i ti);

bool rangoTrimestre(eph_h th, eph_h ti);

bool rangoIv2(eph_h th);

bool rangoIi2(eph_h th);

bool rangoMiembrosHogar(eph_h th,eph_i ti);

bool rangoCh6(eph_i ti);

bool rangoP47t(eph_i ti);

bool rangoIv1(eph_h th);

bool rangoIi3(eph_i ti);

bool rangoIi7(eph_h th);

bool rangoRegion(eph_h th);

bool rangoMas500(eph_h th);

bool rangoCh4(eph_i ti);

bool rangoNivelEd(eph_i ti);

bool rangoEstado(eph_i ti);

bool rangoCatOcup(eph_i ti);

bool rangoPp04g(eph_i ti);

int habitantesDeUnaCasa(hogar hog, eph_i ti);

bool mismoAnio (eph_h th,eph_i ti);

//IMPLENTACION PROBLEMA 2


void longitudIgualAMaximaCantidadHabitaciones(eph_h th,int  region,vector<int> &lista);

int cantHogaresCasaConNHabitaciones(eph_h th,int region,int  j);

//IMPLENTACION PROBLEMA 3

float proporcionDeCasasConHC(eph_h th,eph_i ti, int region);

float cantHogaresValidos(eph_h th,int region);

float cantHogaresValidosConHC(eph_h th,eph_i ti,int region);

bool esHogarValido (hogar th_k,int region);

bool hogarConHC(hogar th_k, eph_i ti);

int cantHabitantes(hogar th_k,eph_i ti);



//IMPLENTACION PROBLEMA 4
//IMPLENTACION PROBLEMA 5
//IMPLENTACION PROBLEMA 6
//IMPLENTACION PROBLEMA 7
//IMPLENTACION PROBLEMA 8
//IMPLENTACION PROBLEMA 9
//IMPLENTACION PROBLEMA 10
//IMPLENTACION PROBLEMA 11
#endif //SOLUCION_AUXILIARES_H
