#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

//IMPLEMENTACION PROBLEMA 1

bool esValida(eph_h th, eph_i ti ) {
    bool resp = false;
    if( esMatriz(th) && esMatriz(ti) && th.size()>0 && ti.size()>0 && th[0].size()==cantItemHogar && ti[0].size()==cantItemInd
         && sinRepetidosEnIndividuos(ti)  && sinRepetidosEnHogares(th)&& hogaresAsociadosIndividuos(th,ti)
        && mismoAnioYTrimestre(th,ti) && iv2MayorOIgualIi2(th) && rangosValidos(th,ti)){
        resp=true;
    }
    return resp;
}
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
bool sinRepetidosEnIndividuos(eph_i ti){
    int i=0,repetidos=0;
    while ( i<ti.size() ){
        int j=0;
        while(j< ti.size()){
            if(ti[i][COMPONENTE]==ti[j][COMPONENTE] && i!=j && ti[i][INDCODUSU]==ti[j][INDCODUSU]){
                repetidos++;
            }
            j++;
        }
        i++;
    }
    return repetidos==0;
}
bool sinRepetidosEnHogares (eph_h th){
    int i=0,repetidos=0;
    while ( i<th.size() ){
        int j=0;
        while(j< th.size()){
            if(th[i][HOGCODUSU]==th[j][HOGCODUSU] && i!= j){
                repetidos++;
            }
            j++;
        }
        i++;
     }
    return repetidos==0;
}
bool hogaresAsociadosIndividuos(eph_h th, eph_i ti){
    int i=0,asociadosTh=0,asociadosTi=0;
    while (i<th.size()){
        int j=0;
        while (j<ti.size()){
            if(th[i][HOGCODUSU]==ti[j][INDCODUSU]){
                asociadosTh++;
            }
            j++;
        }
        i++;
    }
    int k=0;
    while (k<ti.size()){
        int r=0;
        while (r<th.size()){
            if(ti[k][INDCODUSU]==th[r][HOGCODUSU]){
                asociadosTi++;
            }
            r++;
        }if( asociadosTi==0){
            return false;
        } else{
            asociadosTi=0;
        }

        k++;
    }
    return asociadosTh >= th.size()  ;
}
//Un individuo pude tener mas de una casa?

/*hace falta "i!= j" dentro de las a condiciones del if */
bool mismoAnioYTrimestre(eph_h th, eph_i ti){
    bool resp=false;
    if(mismoAnio(ti,th)&&mismoTrimestreHogares(th)&&mismoTrimestreIndividuos(ti)){
        resp=true;
    }
    return resp;
}
bool mismoAnioHogares(eph_h th){
    int i=0,distintos=0;
    while(i<th.size()){
        int j=0;
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
    int i=0,distintos=0;
    while(i<ti.size()){
        int j=0;
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
bool mismoAnio(eph_h th, eph_i ti) {
    if( mismoAnioIndividuos(ti)&&mismoAnioHogares(th)){
        return  ti[0][INDANIO]==th[0][HOGANIO];
    }else{
        return false;
    }
}
bool mismoTrimestreHogares(eph_h th){
    int i=0,distintos=0;
    while(i<th.size()){
        int j=0;
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
    int i=0,distintos=0;
    while(i<ti.size()){
        int j=0;
        while(j<ti.size()){
            if(ti[i][INDTRIMESTRE]!=ti[j][INDTRIMESTRE]&& i!= j){
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
     if(rangoTrimestre(th,ti) && /*rangoCodusu(th,ti) && */ rangoIv2(th) && rangoIi2(th) && rangoMiembrosHogar(th,ti)
     && rangoCh6(ti) && rangoP47t(ti) && rangoIv1(th) && rangoIi3(ti) && rangoIi7(th) && rangoRegion(th) && rangoMas500(th)
     && rangoCh4(ti) && rangoNivelEd(ti) && rangoEstado(ti) && rangoCatOcup(ti) && rangoPp04g(ti)){
        valido=true;
     }
     return valido;
}
//es necesario?
bool rangoCodusu(eph_h th, eph_i ti){
    int i=0,noEnRango=0;
    while(i<th.size()){
        if(th[i][HOGCODUSU]<=0){
            noEnRango ++;
        }
        i++;
    }
    int j=0;
    while(i<ti.size()){
        if(ti[j][INDCODUSU]<=0){
            noEnRango ++;
        }
        j++;
    }
    return noEnRango==0;
}
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
bool rangoMiembrosHogar(eph_h th, eph_i ti){
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
bool rangoP47t(eph_i ti){
    int i=0,noEnRango=0;
    while(i<ti.size()){
        if(ti[i][p47T]<-1){
            noEnRango ++;
        }
        i++;
    }
    return noEnRango==0;
}
bool rangoIv1(eph_h th){
    int i=0,noEnRango=0;
    while(i<th.size()){
        if((5<th[i][IV1]) || (th[i][IV1]<1)){
            noEnRango ++;
        }
        i++;
    }
    return noEnRango==0;
}
bool rangoIi3(eph_i ti){
    int i=0,noEnRango=0;
    while(i<ti.size()){
        if(ti[i][II3]==1||ti[i][II3]==3){
            noEnRango ++;
        }
        i++;
    }
    return noEnRango==0;
}
bool rangoIi7(eph_h th){
    int i=0,noEnRango=0;
    while(i<th.size()){
        if(3<th[i][II7] || th[i][II7]<1){
            noEnRango ++;
        }
        i++;
    }
    return noEnRango==0;
}
bool rangoRegion(eph_h th) {
    int i = 0, noEnRango = 0;
    while (i < th.size()) {
        if (th[i][REGION]!=GBA && th[i][REGION]!=NOA && th[i][REGION]!=NEA && th[i][REGION]!=CUYO && th[i][REGION]!=PAMPEANA && th[i][REGION]!=PATAGONIA) {
            noEnRango++;
        }
        i++;
    }
    return noEnRango == 0;
}
bool rangoMas500(eph_h th){
    int i = 0, noEnRango = 0;
    while (i < th.size()) {
        if (th[i][MAS_500]!=0 && th[i][MAS_500]!=1)  {
            noEnRango++;
        }
        i++;
    }
    return noEnRango == 0;

}
bool rangoCh4(eph_i ti){
    int i = 0, noEnRango = 0;
    while (i < ti.size()) {
        if (ti[i][CH4]!=1 && ti[i][CH4]!=2)  {
            noEnRango++;
        }
        i++;
    }
    return noEnRango == 0;
}
bool rangoNivelEd(eph_i ti){
    int i = 0, noEnRango = 0;
    while (i < ti.size()) {
        if (ti[i][NIVEL_ED]!=0 && ti[i][NIVEL_ED]!=1)  {
            noEnRango++;
        }
        i++;
    }
    return noEnRango == 0;
}

bool rangoEstado(eph_i ti){
    int i = 0, noEnRango = 0;
    while (i < ti.size()) {
        if (1 < ti[i][ESTADO] || ti[i][ESTADO] <-1 ) {
            noEnRango++;
        }
        i++;
    }
    return noEnRango == 0;
}
bool rangoCatOcup(eph_i ti){
    int i = 0, noEnRango = 0;
    while (i < ti.size()) {
        if (4 < ti[i][CAT_OCUP] || ti[i][CAT_OCUP] < 0) {
            noEnRango++;
        }
        i++;
    }
    return noEnRango == 0;
}
bool rangoPp04g(eph_i ti){
    int i=0,noEnRango=0;
    while (i < ti.size()){
        if (10<ti[i][PP04G] || ti[i][PP04G]<0 ){
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

/*####################################################################################################################*/

//IMPLEMENTACION PROBLEMA 2
void longitudIgualAMaximaCantidadHabitaciones(eph_h th, int region, vector<int> &lista){
    int i=0,maximaCantHab=0;
    while(i<th.size()){
        if(th[i][REGION]==region && th[i][IV1]==1){
                if (maximaCantHab < th[i][IV2]) {
                    maximaCantHab = th[i][IV2];
                }
        }
    i++;
    }
    for(int k=0;k<maximaCantHab;k++){
        lista.push_back(0);
    }
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

/*####################################################################################################################*/

//IMPLEMENTACION PROBLEMA 3
float proporcionDeCasasConHC(eph_h th,eph_i ti, int region){
    if( cantHogaresValidos(th,region)>0){
        return  cantHogaresValidosConHC(th,ti,region)/cantHogaresValidos(th,region);
    } else{
        return  0;
    }
}
float cantHogaresValidosConHC(eph_h th, eph_i ti, int region){
    float hogaresValidosConHC=0;
    for(int k=0;k<th.size();k++){
        if(esHogarValido(th[k],region)&& hogarConHC(th[k],ti)){
            hogaresValidosConHC++;
        }

    }
    return hogaresValidosConHC;
}
float cantHogaresValidos(eph_h th, int region){
    float hogaresValidos=0;
    for(int k=0;k<th.size();k++){
        if(esHogarValido (th[k], region)){
            hogaresValidos++;
        }
    }
    return hogaresValidos;
}
bool esHogarValido (hogar th_k,int region){
    if(th_k[IV1]==1 && th_k[REGION]==region && th_k[MAS_500]==0){
        return true;
    }else{
        return false;
    }
}
bool hogarConHC(hogar th_k, eph_i ti){
    if(cantHabitantes(th_k,ti) > 3*th_k[II2]){
        return true;
    }else{
        return false;
    }
}
int cantHabitantes(hogar th_k,eph_i ti){
    int habitantes=0;
    for(int j=0;j<ti.size();j++){
        if(th_k[HOGCODUSU]==ti[j][INDCODUSU]){
           habitantes++;
        }
    }
    return habitantes;
}
//IMPLENTACION PROBLEMA 4

//IMPLENTACION PROBLEMA 5
//IMPLENTACION PROBLEMA 6
//IMPLENTACION PROBLEMA 7
//IMPLENTACION PROBLEMA 8
//IMPLENTACION PROBLEMA 9
//IMPLENTACION PROBLEMA 10
//IMPLENTACION PROBLEMA 11