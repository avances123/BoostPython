/*
 * SerieHistorica.h
 *
 *  Created on: Feb 21, 2015
 *      Author: pedro
 */

#ifndef SERIEHISTORICA_H_
#define SERIEHISTORICA_H_

#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/time_zone_base.hpp"
#include "boost/date_time/local_time/local_time.hpp"
#include "boost/iterator/filter_iterator.hpp"

#include "matematicas/constantes.h"

namespace utiles {


class SerieHistorica: private std::vector<double> {
	typedef std::vector<double> vector;
public:
	SerieHistorica();

	SerieHistorica(const std::vector<double> &serie,
			const boost::posix_time::ptime &fecha_inicio,std::string descripcion="");

	//void Redimensionar(const boost::local_time::local_time_period &periodo);

	boost::posix_time::ptime UltimaFechaValida() const;

	std::string GetDescripcion();
	void SetDescripcion(std::string descripcion);
	using vector::operator[];
	using vector::begin;
	using vector::end;
	using vector::empty;
	using vector::size;
	using vector::back;
	using vector::iterator;
	using vector::reverse_iterator;
	using vector::const_iterator;
	using vector::const_reverse_iterator;

	bool operator==(SerieHistorica const& otra_serie_historica) const;

//	typedef boost::filter_iterator<utiles::matematicas::EsInvalido(), double> FiltradoDatosInvalidosIterador;

//	SerieHistorica operator*(const SerieHistorica &) const;
//	SerieHistorica operator+(const SerieHistorica &) const;
private:
	boost::posix_time::ptime fecha_inicio;
	std::string descripcion;

};

} /* namespace serie_historica */

#endif /* SERIEHISTORICA_H_ */
