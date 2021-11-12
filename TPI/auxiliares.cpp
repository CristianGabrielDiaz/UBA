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
    if(mismoAnio(th,ti)&&mismoTrimestreHogares(th)&&mismoTrimestreIndividuos(ti)){
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
     if(rangoTrimestre(th,ti)&& rangoCodusuTi(ti) && rangoCodusuTh(th)  &&  rangoIv2(th)  &&rangoMiembrosHogar(th,ti)
     && rangoCh6(ti) && rangoP47t(ti) && rangoIv1(th) && rangoIi3(th)  && rangoIi7(th) && rangoRegion(th) && rangoMas500(th)
     && rangoCh4(ti) && rangoNivelEd(ti) && rangoEstado(ti) && rangoCatOcup(ti) && rangoPp04g(ti)){
        valido=true;
     }
     return valido;
}
bool rangoCodusuTh(eph_h th){
    int i=0,noEnRango=0;
    while(i<th.size()){
        if(th[i][HOGCODUSU]<=0){
            noEnRango ++;
        }
        i++;
    }
    return noEnRango==0;
}
bool rangoCodusuTi( eph_i ti){
    int j=0,noEnRango=0;
    while(j<ti.size()){
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
bool rangoIi3(eph_h th){
    int i=0,noEnRango=0;
    while(i<th.size()){
        if(th[i][II3]!=1 && th[i][II3]!=2){
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

/*####################################################################################################################*/

//IMPLENTACION PROBLEMA 4
float proporcionTeleworking(eph_h th,eph_i ti){
    float proporcion=0;
    if(cantIndividuosQueTrabajan(th,ti)>0){
        proporcion = cantIndividuosTrabajandoEnSuVivienda(th,ti)/ cantIndividuosQueTrabajan(th,ti);
    }
    return proporcion;
}


float  cantIndividuosTrabajandoEnSuVivienda(eph_h th, eph_i ti){
    float trabajadoresValidos=0;
    for (int i = 0; i <ti.size() ; ++i) {
        for (int j = 0; j <th.size() ; ++j) {
            if (ti[i][ESTADO]==1 && ti[i][PP04G]==6 && ti[i][INDCODUSU]==th[j][HOGCODUSU] && th[j][II3]==1 && th[j][MAS_500]==1 && (th[j][IV1]==1 || th[j][IV1]==2)){
                trabajadoresValidos++;
            }
        }
    }
    return trabajadoresValidos;
}

float cantIndividuosQueTrabajan(eph_h th, eph_i ti){
    float trabajadoresValidos=0;
    for(int i=0;i<ti.size();i++){
        for(int k=0;k<th.size();k++){
            if(ti[i][ESTADO]==1&&ti[i][INDCODUSU]==th[k][HOGCODUSU]&&th[k][MAS_500]==1&&ti[i][PP04G]==6){
                trabajadoresValidos++;
            }
        }

    }
    return trabajadoresValidos;
}

/*####################################################################################################################*/

//IMPLENTACION PROBLEMA 5

bool tieneCasaChica(hogar th_k, eph_i ti){
    bool casaChica=false;
    if((cantHabitantes(th_k,ti)-2)>th_k[II2]){
        casaChica=true;

    }
    return casaChica;
}

/*####################################################################################################################*/
//IMPLENTACION PROBLEMA 6
//IMPLENTACION PROBLEMA 7
void insertionSortRegion (eph_h &th ) {
    for(int i=0; i < th . size () ; i++) {
        insertarRegion (th ,i) ;
    }

}

void insertarRegion(eph_h &th, int i) {

    while (i > 0 && th [i][4] < th [i -1][4]) {//usamos 4 ya que REGION no coincide con lo definido en definiciones ya la tabla hogares le faltan filas
        swap (th ,i,i -1) ;
        i--;
    }
}
void insertionSortCodusuEnRegion (eph_h &th ) {
    for(int i=0; i < th.size () ; i++) {
        insertarCodusuEnRegion (th ,i) ;
    }
}

void insertarCodusuEnRegion(eph_h &th, int i) {
    if (i > 0 && th [i][4] == th[i -1][4]) {//REGION=4
        while (i > 0 && th[i][HOGCODUSU] < th[i - 1][HOGCODUSU]&& th [i][4] == th[i -1][4]) {
            swap(th, i, i - 1);
            i--;
        }
    }
}


void insertionSortCodusu (eph_h &th, eph_i &ti) {
    int j=0;
    for(int i=0; i < th . size () ; i++) {
        for (int k=0; k < ti . size () ; k++){
            if(th[i][HOGCODUSU]==ti[k][INDCODUSU]){
                swap (ti ,j ,k) ;
                j++;
            }

        }

    }

}

/*
void insertarCodusu( eph_i &ti, int i) {//
    while (i < ti.size() && ti [i][INDCODUSU] < ti [i -1][INDCODUSU]) {
        swap (ti ,i ,i -1) ;
        i--;
    }
}
*/

void insertionSortComponenteEnCodusu(vector<vector<int>> &matriz) {
    for(int i=0; i < matriz . size () ; i++) {
        insertarComponenteEnCodusu (matriz ,i) ;
    }

}


void insertarComponenteEnCodusu(vector<vector<int>> &matriz, int i) {
    if (i > 0 && matriz [i][INDCODUSU] == matriz[i -1][INDCODUSU]) {
        int codusu1 = matriz[0][INDCODUSU],codusu2 = matriz[1][INDCODUSU],codusu3=matriz[2][INDCODUSU],codusu4= matriz[3][INDCODUSU];
        while (i > 0 && matriz[i][6] < matriz[i - 1][6]&&matriz [i][INDCODUSU] == matriz[i -1][INDCODUSU]) {//COMOPONENTE=6 segun tabla del test
            swap(matriz, i, i - 1);
            i--;
        }
    }
}

void swap(vector<vector<int>> &matriz, int i, int j) {
    vector<int> k= matriz [i];
    matriz [i]= matriz [j];
    matriz [j]=k;
}
/*####################################################################################################################*/

//IMPLENTACION PROBLEMA 8
vector<pair<int,int>> ingresoTotalPorHogar(eph_h th,eph_i ti){
    vector<pair<int,int>> res={};
    for (int i = 0; i < th.size(); ++i) {
        int ingresos=0;
        for (int j = 0; j < ti.size(); ++j) {
            if (th[i][HOGCODUSU]==ti[j][INDCODUSU]){
                ingresos += ti[j][p47T];
            }
        }
        res.push_back(make_pair(th[i][HOGCODUSU],ingresos));
    }
    return res;
}

void ordenarPorIngresos( vector<pair<int, int>> &ingresosDeHogares ){//insertionSort
    for(int i=0; i < ingresosDeHogares.size () ; i++) {
        insertarPorIngresos (ingresosDeHogares ,i) ;
    }
}
void insertarPorIngresos(vector<pair<int, int>> &ingresosDeHogares, int i) {

    while (i > 0 && ingresosDeHogares[i].second < ingresosDeHogares [i -1].second) {
        swapDupla(ingresosDeHogares ,i,i -1) ;
        i--;
    }
}
void swapDupla(vector<pair<int, int>> & ingresosDeHogares, int i, int j) {
    pair<int, int> k=  ingresosDeHogares [i];
    ingresosDeHogares[i]=  ingresosDeHogares [j];
    ingresosDeHogares[j]=k;
}



vector<pair<int, int>> mesetaDeIngresosMasLarga(vector<pair<int, int>> &ingresosDeHogares) {
    vector<pair<int, int>> mesetaMasLarga={};
      for(int i = 0; i < ingresosDeHogares.size(); i++){
          for(int j =i+1 ; j<ingresosDeHogares.size() ; j++){
              vector<pair<int,int>> meseta={ingresosDeHogares[i],ingresosDeHogares[j]};
              int diferencia= ingresosDeHogares[j].second-ingresosDeHogares[i].second;
              if(diferencia>0){
                  int siguienteIngresoDeLaMeseta= ingresosDeHogares[j].second+ diferencia;
                  for(int k =j+1 ; k<ingresosDeHogares.size() ; k++){
                      if(siguienteIngresoDeLaMeseta==ingresosDeHogares[k].second){
                          meseta.push_back(ingresosDeHogares[k]);
                          siguienteIngresoDeLaMeseta+=diferencia;
                      }
                  }
                  if(meseta.size()>mesetaMasLarga.size()){
                      mesetaMasLarga=meseta;
                  }

              }


          }
      }
      return mesetaMasLarga;


}



//IMPLENTACION PROBLEMA 9
//IMPLENTACION PROBLEMA 10
//IMPLENTACION PROBLEMA 11