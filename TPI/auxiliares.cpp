#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

//IMPLEMENTACION PROBLEMA 1
int cantItemHogar = 12;
int cantItemInd= 11;

bool esValida(eph_h th, eph_i ti ) {
    bool resp = false;
    if( esMatriz(th) && esMatriz(ti) && th.size()>0 && ti.size()>=0 && th.size()==cantItemHogar && ti.size()==cantItemInd && sinRepetidosEnIndividuos(ti) && sinRepetidosEnHogares(th) && hogaresAsociadosIndividuos(th,ti) && mismoAnioYTrimestre(th,ti) && iv2MayorOIgualIi2(th) && rangosValidos(th,ti) ){
        resp=true;
    }
    return resp;
}
/* ? */
bool esMatriz(vector<vector<int>> m) {
    int i = 0,distintaLongitud=0;
    while(i < m.size()){
        if (m[0].size() != m[i].size()){
            distintaLongitud++;
        }
        i++;
    }
    return distintaLongitud == 0;
}
/* ? */

bool sinRepetidosEnIndividuos(eph_i ti){
    int i=0,j=0,repetidos=0;
    while ( i<ti.size() ){
        while(j< ti.size()){
            if((ti[i][INDCODUSU] == ti[j][INDCODUSU]) && i!= j){/* @hogcodusu ?*/
                repetidos++;
            }
            j++;
        }
        i++;
    }
    return repetidos==0;
}

bool sinRepetidosEnHogares (eph_h th){
    int i=0,j=0,k=0;
    while ( i<th.size() ){
        while(j< th.size()){
            if((th[i][HOGCODUSU] == th[j][HOGCODUSU]) && i!= j){
                k++;
            }
            j++;
        }
        i++;
     }
    return k==0;
}

bool hogaresAsociadosIndividuos(eph_h th, eph_i ti){
    int i=0,j=0,asociadosTh=0,asociadosTi=0;
    while (i<th.size()){
        while (j<ti.size()){
            if(th[i][HOGCODUSU]==ti[j][INDCODUSU]){
                asociadosTh++;
            }
            j++;
        }
        i++;
    }
    while (i<ti.size()){
        while (j<th.size()){
            if(ti[i][INDCODUSU]==th[j][HOGCODUSU]){
                asociadosTi++;
            }
            j++;
        }
        i++;
    }
    return (asociadosTh >= th.size() && asociadosTi == ti.size());
}

/*hace falta "i!= j" dentro de las a condiciones del if */
bool mismoAnioYTrimestre(eph_h th, eph_i ti){
    bool resp=false;
    if(mismoAnioHogares(th)&&mismoAnioIndividuos(ti)&&mismoTrimestreHogares(th)&&mismoTrimestreIndividuos(ti)){
        resp=true;
    }
    return resp;
}

bool mismoAnioHogares(eph_h th){
    int i=0,j=0,distintos=0;
    while(i<th.size()){
        while(j<th.size()){
            if(th[i][HOGANIO]!=th[j][HOGANIO]&& i!= j){
                distintos++;
            }
            j++;
        }
        i++;
    }
    return distintos==0;
}

bool mismoAnioIndividuos(eph_i ti){
    int i=0,j=0,distintos=0;
    while(i<ti.size()){
        while(j<ti.size()){
            if(ti[i][INDANIO]!=ti[j][INDANIO]&& i!= j){
                distintos++;
            }
            j++;
        }
        i++;
    }
    return distintos==0;
}

bool mismoTrimestreHogares(eph_h th){
    int i=0,j=0,distintos=0;
    while(i<th.size()){
        while(j<th.size()){
            if(th[i][HOGTRIMESTRE]!=th[j][HOGTRIMESTRE]&& i!= j){
                distintos++;
            }
            j++;
        }
        i++;
    }
    return distintos==0;

}

bool mismoTrimestreIndividuos(eph_i ti){
    int i=0,j=0,distintos=0;
    while(i<ti.size()){
        while(j<ti.size()){
            if(ti[i][HOGTRIMESTRE]!=ti[j][HOGTRIMESTRE]&& i!= j){
                distintos++;
            }
            j++;
        }
        i++;
    }
    return distintos==0;
}

bool iv2MayorOIgualIi2(eph_h th){
    int i=0,menores=0;
    while(i<th.size()){
        if(th[i][II2]>th[i][IV2]){
            menores++;
        }
        i++;
    }
    return menores==0;
}
bool rangosValidos(eph_h th, eph_i ti){
     bool valido=false;
     if(rangoCodusu(th,ti)&&rangoTrimestre(th,ti) &&rangoIv2(th)&&rangoIi2(th)&&rangoComponente(th,ti)&&rangoCh6(ti)&&rangoP47t(ti)&&rangoIv1(ti)&&rangoIi3(ti)&&rangoIi7(th)&&rangoRegion(th)&&rangoMas500(th)&&rangoCh4(ti)&&rangoNivelEd(ti)&&rangoEstado(ti)&&rangoCatOcup(ti)&&rangoPp04g(ti)  ){
        valido=true;
     }
     return valido;
}
bool rangoCodusu(eph_h th, eph_i ti){
    int i=0,noEnRango=0;
    while(i<th.size()){
        if((th[i][HOGCODUSU]<0) ){
            noEnRango ++;
        }
        i++;
    }
    int j=0;
    while(i<ti.size()){
        if((ti[j][INDCODUSU]<0) ){
            noEnRango ++;
        }
        j++;
    }
    return noEnRango==0;
}
/*?*/

bool rangoTrimestre(eph_h th, eph_i ti){
    int i=0,j=0,noEnRango=0;
    while(i<th.size()){
        if((3<th[i][HOGTRIMESTRE]) || (th[i][HOGTRIMESTRE]<1)){
            noEnRango++;
        }
        i++;
    }
    while(j<ti.size()){
        if((3<ti[j][INDTRIMESTRE]) || (ti[j][INDTRIMESTRE]<1)){
            noEnRango++;
        }
        j++;
    }
    return noEnRango==0;
}

bool rangoIv2(eph_h th){
    int i=0,noEnRango=0;
    while(i<th.size()){
        if(th[i][IV2]<1){
            noEnRango ++;
        }
        i++;
    }
    return noEnRango==0;
}

bool rangoIi2(eph_h th){
    int i=0,noEnRango=0;
    while(i<th.size()){
        if(th[i][II2]>th[i][IV2]){
            noEnRango ++;
        }
        i++;
    }
    return noEnRango==0;
}
/*?*/
bool rangoComponente(eph_h th, eph_i ti){
    int i=0,noEnRango=0;
    while(i<th.size()){
        if(habitantesDeUnaCasa(th[i],ti)<0 || habitantesDeUnaCasa(th[i],ti)>20 ){
            noEnRango ++;
        }
        i++;
    }
    return noEnRango==0;
}

bool rangoCh6(eph_i ti){
    int i=0,noEnRango=0;
    while(i<ti.size()){
        if(ti[i][CH6]<0){
            noEnRango ++;
        }
        i++;
    }
    return noEnRango==0;
}

bool rangoP47t( eph_i ti){
    int i=0,noEnRango=0;
    while(i<ti.size()){
        if(ti[i][p47T]<-1){
            noEnRango ++;
        }
        i++;
    }
    return noEnRango==0;
}

bool rangoIv1( eph_i ti){
    int i=0,noEnRango=0;
    while(i<ti.size()){
        if(5<ti[i][IV1]<1){
            noEnRango ++;
        }
        i++;
    }
    return noEnRango==0;
}

bool rangoIi3( eph_i ti){
    int i=0,noEnRango=0;
    while(i<ti.size()){
        if(ti[i][II3]==1||ti[i][II3]==3){
            noEnRango ++;
        }
        i++;
    }
    return noEnRango==0;
}

bool rangoIi7( eph_h th){
    int i=0,noEnRango=0;
    while(i<th.size()){
        if(3<th[i][II7]<1){
            noEnRango ++;
        }
        i++;
    }
    return noEnRango==0;
}

bool rangoRegion(eph_h th) {
    int i = 0, noEnRango = 0;
    while (i < th.size()) {
        if (6 < th[i][REGION] < 1) {
            noEnRango++;
        }
        i++;
    }
    return noEnRango == 0;
}

bool rangoMas500(eph_h th){
    int i = 0, noEnRango = 0;
    while (i < th.size()) {
        if (th[i][MAS_500]==0|| th[i][MAS_500]==1)  {
            noEnRango++;
        }
        i++;
    }
    return noEnRango == 0;

}

bool rangoCh4(eph_i ti){
    int i = 0, noEnRango = 0;
    while (i < ti.size()) {
        if (ti[i][CH4]==1 || ti[i][CH4]==2)  {
            noEnRango++;
        }
        i++;
    }
    return noEnRango == 0;
}

bool rangoNivelEd(eph_i ti){
    int i = 0, noEnRango = 0;
    while (i < ti.size()) {
        if (ti[i][NIVEL_ED]==0 || ti[i][NIVEL_ED]==1)  {
            noEnRango++;
        }
        i++;
    }
    return noEnRango == 0;
}

bool rangoEstado(eph_i ti){
    int i = 0, noEnRango = 0;
    while (i < ti.size()) {
        if (1 < ti[i][ESTADO] <-1 ) {
            noEnRango++;
        }
        i++;
    }
    return noEnRango == 0;
}

bool rangoCatOcup(eph_i ti){
    int i = 0, noEnRango = 0;
    while (i < ti.size()) {
        if (4 < ti[i][CAT_OCUP] < 0) {
            noEnRango++;
        }
        i++;
    }
    return noEnRango == 0;
}

bool rangoPp04g(eph_i ti){
    int i=0,noEnRango=0;
    while (i < ti.size()){
        if (10<ti[i][PP04G]<1 ){
            noEnRango++;
        }
        i++;
    }
    return noEnRango == 0;
}

int habitantesDeUnaCasa(hogar hog, eph_i ti) {
    int i=0,habitantes=0;
    while (i<ti.size()){
        if (hog[HOGCODUSU] == ti[i][INDCODUSU]){
            habitantes++;
        }
        i++;
    }
    return habitantes;
}

/* año, rango trimestre, rango componente*/

/*####################################################################################################################*/

//IMPLEMENTACION PROBLEMA 2
/*
bool longitudIgualAMaximaCantidadHabitaciones(eph_h th, int region, vector<int> lista){
    int i=0,maximaCantHab=0;
    bool booleano=true;
    while(i<th.size()){
        if(th[i][REGION]==region ){
            if(lista.size()>=th[i][IV2]){
                if(maximaCantHab<th[i][IV2]) {
                    maximaCantHab = th[i][IV2];
                }
            }else{
                booleano=false;
            }
        }
    }

    return maximaCantHab==lista.size()&&booleano;
}
*/
/*acá corregir*/
bool longitudIgualAMaximaCantidadHabitaciones(eph_h th, int region, vector<int> lista){
    int i=0,maximaCantHab=0;
    bool booleano=true;
    while(i<th.size()){
        if(th[i][REGION]==region ){
            if(lista.size()>=th[i][IV2]) {
                if (maximaCantHab < th[i][IV2]) {
                    maximaCantHab = th[i][IV2];
                }
            }
        }
    i++;
    }
    return maximaCantHab==lista.size()&&booleano;
}

int cantHogaresCasaConNHabitaciones(eph_h th, int region, int habitaciones){
    int i=0, hogares=0;
    while(i<th.size()){
        if (th[i][IV1] == 1 && th[i][IV2] == habitaciones && th[i][REGION] == region){
            hogares++;
        }
        i++;
    }
    return hogares;
}


/*
 *
 * while (i < m.size()&&!m[i].empty()&&) {
        int j = 0;
        while (j < m.size()&&m[i].size() == m[j].size()) {
            resp = true;
            j++;
        }
        i++;
    }
    return resp;
    */


 /*
  *
  * int i = 0;e()
  * bool resp;
  * while(i < m.size() && (m[0].size() == m[i].size())){
  *      i++;
  * }
  * return i >= m.size();
  * */