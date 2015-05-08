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
			const boost::local_time::local_date_time &fecha_inicio);

	//void Redimensionar(const boost::local_time::local_time_period &periodo);

	boost::local_time::local_date_time UltimaFechaValida() const;

	using vector::operator[];
	using vector::begin;
	using vector::end;
	using vector::empty;
	using vector::size;
	using vector::back;

//	typedef boost::filter_iterator<utiles::matematicas::EsInvalido(), double> FiltradoDatosInvalidosIterador;

//	SerieHistorica operator*(const SerieHistorica &) const;
//	SerieHistorica operator+(const SerieHistorica &) const;
private:
	boost::local_time::local_date_time fecha_inicio;

};

} /* namespace serie_historica */

#endif /* SERIEHISTORICA_H_ */
