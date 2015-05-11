/*
 * SerieHistorica.cpp
 *
 *  Created on: Feb 21, 2015
 *      Author: pedro
 */

#include "../include/SerieHistorica.h"

namespace utiles {

SerieHistorica::SerieHistorica(const std::vector<double> &serie,
		const boost::posix_time::ptime &fecha_inicio,std::string descripcion) :
		vector(serie), fecha_inicio(fecha_inicio), descripcion(descripcion) {

}

SerieHistorica::SerieHistorica() :
		fecha_inicio(boost::local_time::not_a_date_time) {

}

std::string SerieHistorica::GetDescripcion() {
	return this->descripcion;
}
void SerieHistorica::SetDescripcion(std::string descripcion) {
	this->descripcion=descripcion;
}

bool SerieHistorica::operator==(SerieHistorica const& otra_serie_historica) const{
	bool iguales=false;
	if (otra_serie_historica.UltimaFechaValida()==this->UltimaFechaValida() and otra_serie_historica.size()==this->size())
		iguales=true;
	return iguales;
}

SerieHistorica SerieHistorica::Copiar(){
	return SerieHistorica(*this);
}


/*
 void SerieHistorica::Redimensionar(
 const boost::local_time::local_time_period &periodo) {
 auto numero_de_elemetos = periodo.length().hours();
 auto fecha_inicio_periodo = periodo.begin();
 auto inicio_valores = (fecha_inicio_periodo - fecha_inicio).hours();
 this->erase(this->begin() + inicio_valores + numero_de_elemetos,
 this->end());

 this->erase(this->begin(), this->begin() + inicio_valores);
 }
 */
boost::posix_time::ptime SerieHistorica::UltimaFechaValida() const {
	auto ultima_fecha_valida = boost::posix_time::ptime(
			boost::local_time::not_a_date_time);
	auto it = std::find_if(this->rbegin(), this->rend(), [](double valor) {
		return !std::isnan(valor);
	});
	if (it != this->rend()) {
		auto distancia_horaria = std::distance(++it, this->rend());
		return fecha_inicio + boost::posix_time::hours(distancia_horaria);
	} else {
		std::cout << fecha_inicio << " disctaica" << this->size() << std::endl;
		return fecha_inicio + boost::posix_time::hours(this->size() - 1);
	}

	return ultima_fecha_valida;
}

} /* namespace serie_historica */
