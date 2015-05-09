//============================================================================
// Name        : PruebaLibreriaUtiles.cpp
// Author      : Pedro
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <boost/assign/std/vector.hpp>
#include "include/SerieHistorica.h"
#include "include/matematicas/constantes.h"
#include "include/fechas/fechas.h"

using namespace std;
using namespace utiles;
using namespace boost::assign;

int main() {

	// muy buena pagina para las fechas de boost:http://en.highscore.de/cpp/boost/datetime.html
	cout << "Pruebas" << endl; // prints !!!Hello World!!!
	std::vector<double> mis_datos;
	mis_datos+=0,1,2,3,4,5,6,7,8,matematicas::INVALIDO,matematicas::INVALIDO;

	//boost::local_time::local_date_time fecha=utiles::fechas::ConstruirFecha(2014,1,5);

	auto fecha=utiles::fechas::ConstruirFechaSinZOnaHoraria(2014,1,5);

	SerieHistorica serie_historica(mis_datos,fecha);


	for(auto x:serie_historica){
		std::cout<<x<<",";
	}
	std::cout<<std::endl;


	std::cout<<serie_historica.UltimaFechaValida()<<std::endl;



	return 0;
}
