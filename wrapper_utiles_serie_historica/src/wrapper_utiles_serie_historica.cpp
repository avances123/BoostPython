#include "include/envoltorio_datetime.h"
#include "include/envoltorio_objetos_iterables.h"
#include "include/SerieHistorica.h"
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/irange.hpp>
#include <boost/python/slice.hpp>
#include <boost/assign/std/vector.hpp>

using namespace boost::assign;
using namespace boost::python;

namespace rc_clase_vector_datetime {

// http://docs.scipy.org/doc/numpy/reference/c-api.html
std::vector<double> numpy2vector(numeric::array const& ob) {

	auto nuevo_ob = ob.copy();
	stl_input_iterator<double> begin(nuevo_ob), end;
	std::vector<double> mi_vector(begin, end);
	return mi_vector;
}

class WrapeerSerieHistorica: public utiles::SerieHistorica {
public:
	WrapeerSerieHistorica(numeric::array const& ob,
			boost::posix_time::ptime const&fecha_inicio,
			std::string descripcion) :
			utiles::SerieHistorica(numpy2vector(ob), fecha_inicio, descripcion) {
	}
	;
};

}

double GetItemSerieHistorica(const utiles::SerieHistorica& self, int index) {
	if (index < 0)
		index += static_cast<int>(self.size());

	if (index < 0 || static_cast<int>(self.size()) <= index)
		throw std::out_of_range("Fuera de rango");

	return self[index];
}

/// Para mas ayuda sobre Slice: http://www.boost.org/doc/libs/1_35_0/libs/python/doc/v2/slice.html
numeric::array GetItemSliceSerieHistorica(const utiles::SerieHistorica& self,
		boost::python::slice slice) {
	list resultado;
	boost::python::slice::range<std::vector<double>::const_iterator> rango;
	try {
		rango = slice.get_indices(self.begin(), self.end());
	} catch (std::invalid_argument&) {
		return numeric::array(resultado);
	}

	for (; rango.start != rango.stop; std::advance(rango.start, rango.step)) {
		resultado.append(*rango.start);
	}
	resultado.append(*rango.start); //Ultimo elemento
	return numeric::array(resultado);
}

int TamanoSerieHistorica(const utiles::SerieHistorica& self){
	return self.size();
}

utiles::SerieHistorica ComponemosSerieHistorica(utiles::SerieHistorica const&serie){
	std::vector<double> mis_datos;
		mis_datos+=0.0,0.0,0.0,0.0,0.0;

		utiles::SerieHistorica serie_historica(mis_datos,serie.UltimaFechaValida(),"Por Defecto");
		return serie_historica;
}

//https://wiki.python.org/moin/boost.python
//http://www.boost.org/doc/libs/1_53_0/libs/python/doc/v2/indexing.html
// ejemplos: https://github.com/TNG/boost-python-examples
BOOST_PYTHON_MODULE(wrapper_utiles_serie_historica)
{

	convertidores::ConvertidoresDatetime();
	convertidores::ConvertidoresVectorDouble();
	numeric::array::set_module_and_type("numpy", "ndarray");

	// Prueba de concepto, pero la buena es la siguiente que utiliza todos los conversores
	class_<rc_clase_vector_datetime::WrapeerSerieHistorica>("SerieHistorica",
			init<numeric::array const&, boost::posix_time::ptime const&,
					std::string>()).def("UltimaFechaValida",
			&rc_clase_vector_datetime::WrapeerSerieHistorica::UltimaFechaValida).def(
			"__iter__",
			iterator<rc_clase_vector_datetime::WrapeerSerieHistorica>()) // Add a regular member function.
			;

	// Esta es la buena
	class_<utiles::SerieHistorica>("SerieHistoricaPorConversores",
			init<std::vector<double>, boost::posix_time::ptime const&,std::string>())
			.def("UltimaFechaValida",&utiles::SerieHistorica::UltimaFechaValida)
			.def("__iter__",iterator<utiles::SerieHistorica>())
			.def("__getitem__",&GetItemSerieHistorica)
			.def("__getitem__",&GetItemSliceSerieHistorica)
			.def("__len__",&TamanoSerieHistorica)
			.add_property("Descripcion",&utiles::SerieHistorica::GetDescripcion,&utiles::SerieHistorica::SetDescripcion);

	// Ejemplo de como implementar un contenedor de tal objeto en un vector: http://www.boost.org/doc/libs/1_42_0/libs/python/test/vector_indexing_suite.cpp
	class_<std::vector<utiles::SerieHistorica> >("VectorSeriesHistoricas").def(
			vector_indexing_suite<std::vector<utiles::SerieHistorica> >());

	// Probamos que se realiza un wrapper automaticamente
	def("GenerarPorDefecto",&ComponemosSerieHistorica);

}

