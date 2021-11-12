#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;
// Implementacion Problema 1
bool esEncuestaValida ( eph_h th, eph_i ti ) {
	bool resp = false;
    if( esValida(th,ti) ){
        resp=true;
    }
	// TODO
	return resp;
}

// Implementacion Problema 2
vector < int > histHabitacional ( eph_h th, eph_i ti, int region ) {
	vector < int > resultado; /*= {-1, -1, -1, -1, -1, -1};*/
    longitudIgualAMaximaCantidadHabitaciones(th,region,resultado);
    int j=0;
    while(j<th.size()){
        if(j<resultado.size()){
            resultado[j]=cantHogaresCasaConNHabitaciones(th, region, j + 1);
        }
        j++;
    }
	// TODO
	return resultado;
}

// Implementacion Problema 3
vector< pair < int, float > > laCasaEstaQuedandoChica ( eph_h th, eph_i ti ) {
    int uno = 1;
    vector<pair<int,float>> resp = {make_pair(1,-1.0),
                                        make_pair(40, -1.0),
                                        make_pair(41, -1.0),
                                        make_pair(42,-1.0),
                                        make_pair(43,-1.0),
                                        make_pair(44,-1.0)};

    for (int k=0;k<resp.size();k++){
        resp[k].second=proporcionDeCasasConHC(th,ti,resp[k].first);
    }
    // TODO
  return resp;
}

// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes ( eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i ) {
	bool resp = false;
    if(proporcionTeleworking(t2h,t2i)>proporcionTeleworking(t1h,t1i) ){
        resp=true;
    }
	// TODO
	
  return  resp;
}

// Implementacion Problema 5
int costoSubsidioMejora( eph_h th, eph_i ti, int monto ){
	int resp =0;

    for (int i=0;i<th.size();i++){
        if(th[i][II7]==1 && tieneCasaChica(th[i],ti)){
            resp+=monto;
        }
    }
	// TODO

  return  resp;
}

// Implementacion Problema 6
join_hi generarJoin( eph_h th, eph_i ti ){
    hogar h = {};
    individuo i = {};
	join_hi resp = {};
    for(int k=0;k<th.size();k++){
        for(int j=0;j<ti.size();j++){
            if (th[k][HOGCODUSU]==ti[j][INDCODUSU]){
                h = th[k];
                i = ti[j];
                resp.push_back(make_pair(h,i));
            }
        }
    }

	// TODO
	
  return  resp;
}

// Implementacion Problema 7
void ordenarRegionYCODUSU (eph_h & th, eph_i & ti) {
    insertionSortRegion(th);
    insertionSortCodusuEnRegion(th);

    insertionSortCodusu(th,ti);
    insertionSortComponenteEnCodusu(ti);


	// TODO
	
	return;
}

// Implementacion Problema 8
vector < hogar > muestraHomogenea( eph_h & th, eph_i & ti ){
    vector<pair<int,int>> ingresosDeHogares=ingresoTotalPorHogar( th, ti);
    ordenarPorIngresos( ingresosDeHogares );
    vector<pair<int,int>>  ingresosHomogeneos = mesetaDeIngresosMasLarga (ingresosDeHogares);
    vector < hogar > resp = {};
    for(int k=0;k<ingresosHomogeneos.size();k++){
        for(int i=0;i<th.size();i++){
            if(ingresosHomogeneos[k].first==th[i][HOGCODUSU]){
                resp.push_back(th[i]);
            }
        }
    }
    if (resp.size() < 3){
        resp = {};
    }
    // TODO

    return  resp;
}

// Implementacion Problema 9
void corregirRegion( eph_h & th, eph_i ti ) {
	int j=0;
    while(j<th.size()){
        if(th[j][REGION]==GBA){
            th[j][REGION]=PAMPEANA;
        }
        j++;
    }
	// TODO
	
	return;
}

// Implementacion Problema 10
pair < eph_h, eph_i > quitarIndividuos(eph_i & ti, eph_h & th, vector<pair<int,dato>>  busqueda ) {
    eph_h rth = {};
    eph_i rti = {};
    pair<eph_h, eph_i> resp = make_pair(rth, rti);
    int swapsti = 0, swapsth = 0;
    eph_h th0 = th;
    eph_i ti0 = ti;
    for (int i = 0; i < ti0.size(); i++) {
        if (individuoBuscado(ti[0], busqueda)) {
            rti.push_back(ti[0]);
            swap(ti, 0, ti.size() - 1);   //- swapsti
            ti.pop_back();
            swapsti++;
            for (int k = 0; k < (ti.size() - 1); k++) {
                swap(ti, k, k + 1);
            }
        }
    }
        for (int j = 0; j < th.size(); j++) {
            bool quiteTodos = true;
            for (int w = 0; w < ti.size(); w++) {
                if (th[j][HOGCODUSU] == ti[w][INDCODUSU]) {
                    quiteTodos = false;
                }
            }
            for (int w = 0; w < rti.size(); w++) {
                if (th[j][HOGCODUSU] == rti[w][INDCODUSU]) {
                    rth.push_back(th[j]);
                    if (quiteTodos) {
                        swap(th, j, th.size() - w - 1);
                        th.pop_back();
                        swapsth++;
                        for (int k = 0; (k + 1) < th.size(); k++) {
                            swap(th, j + k, j + k + 1);
                        }
                    }
                }
            }

        }


        // TODO
        resp = make_pair(rth, rti);

        return resp;

}

// Implementacion Problema 11
    vector<int> histogramaDeAnillosConcentricos(eph_h th, eph_i ti, pair<int, int> centro, vector<int> distancias) {
        vector<int> resp = {};
        resp = hogaresEnAnillosConcentricos(distancias, centro, th);

        // TODO

        return resp;
    }


