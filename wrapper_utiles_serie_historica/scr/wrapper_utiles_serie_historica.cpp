#include "include/envoltorio_datetime.h"
#include "include/envoltorio_objetos_iterables.h"
#include "include/SerieHistorica.h"
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

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
			boost::posix_time::ptime const&fecha_inicio,std::string descripcion) :
			utiles::SerieHistorica(numpy2vector(ob), fecha_inicio,descripcion) {
	}
	;
};

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
				init<numeric::array const&,boost::posix_time::ptime const&,std::string>())
		.def("UltimaFechaValida",&rc_clase_vector_datetime::WrapeerSerieHistorica::UltimaFechaValida)
		.def("__iter__", iterator<rc_clase_vector_datetime::WrapeerSerieHistorica >())// Add a regular member function.
				;


	// Esta es la buena
	class_<utiles::SerieHistorica>("SerieHistoricaPorConversores",
					init<std::vector<double>,boost::posix_time::ptime const&,std::string>())
			.def("UltimaFechaValida",&utiles::SerieHistorica::UltimaFechaValida)
			.def("__iter__", iterator<utiles::SerieHistorica >())
			.add_property("Descripcion", &utiles::SerieHistorica::GetDescripcion, &utiles::SerieHistorica::SetDescripcion)
					;

	// Ejemplo de como implementar un contenedor de tal objeto en un vector: http://www.boost.org/doc/libs/1_42_0/libs/python/test/vector_indexing_suite.cpp
	class_<std::vector<utiles::SerieHistorica> >("VectorSeriesHistoricas")
	        .def(vector_indexing_suite<std::vector<utiles::SerieHistorica> >())
	    ;

}

