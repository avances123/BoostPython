#include "include/envoltorio_datetime.h"
#include "include/SerieHistorica.h"

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
			boost::posix_time::ptime const&fecha_inicio) :
			utiles::SerieHistorica(numpy2vector(ob), fecha_inicio) {
	}
};

}

//https://wiki.python.org/moin/boost.python
BOOST_PYTHON_MODULE(rc_clase_vector_datetime)
{

	python_boost_date_time::ConvertidoresDatetime();
	numeric::array::set_module_and_type("numpy", "ndarray");

	class_<rc_clase_vector_datetime::WrapeerSerieHistorica>("SerieHistorica","Clase Primera para probar el funcionamiento del wrapper",
			init<numeric::array const&, boost::posix_time::ptime const&>(),"Inicializacion de la clase")
			.def("UltimaFechaValida",&rc_clase_vector_datetime::WrapeerSerieHistorica::UltimaFechaValida)
			.def("__iter__",iterator<rc_clase_vector_datetime::WrapeerSerieHistorica>()) // Add a regular member function.
			;

}

