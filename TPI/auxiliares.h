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

bool rangoComponente(eph_h th,eph_i ti);

bool rangoCh6(eph_i ti);

bool rangoP47t(eph_i ti);

bool rangoIv1(eph_i ti);

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

//IMPLENTACION PROBLEMA 2


bool longitudIgualAMaximaCantidadHabitaciones(eph_h th,int  region,vector<int> resultado);

int cantHogaresCasaConNHabitaciones(eph_h th,int region,int  j);






#endif //SOLUCION_AUXILIARES_H
