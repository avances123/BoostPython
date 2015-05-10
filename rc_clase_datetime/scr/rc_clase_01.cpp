#include "include/envoltorio_datetime.h"

using namespace boost::python;

namespace rc_clase_01 {

boost::posix_time::ptime tomorrow() {
	std::cout<<"Esto va saliendo SII"<<std::endl;
	return boost::posix_time::microsec_clock::local_time()
			+ boost::gregorian::days(1);
}

boost::posix_time::ptime day_before(boost::posix_time::ptime const&that) {
	return that - boost::gregorian::days(1);
}


}

BOOST_PYTHON_MODULE(rc_clase_01)
{

	python_boost_date_time::ConvertidoresDatetime();
	// metodos definimos por mi
	def("tomorrow", rc_clase_01::tomorrow);
	//Con el metodo day_before hemos asegurado que los conversores funcion una vez definimos
	def("day_before", rc_clase_01::day_before, args("moment"));



}

