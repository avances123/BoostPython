#include "../include/envoltorio_datetime.h"


using namespace boost::python;

namespace python_boost_date_time {

PyObject* python_boost_date_time::ptime2datetime::convert(
		boost::posix_time::ptime const&t) {
	auto d = t.date();
	auto tod = t.time_of_day();
	auto usec = tod.total_microseconds() % 1000000;
	// Utlizamola api de datetime: https://docs.python.org/2/c-api/datetime.html
	return PyDateTime_FromDateAndTime(d.year(), d.month(), d.day(), tod.hours(),
			tod.minutes(), tod.seconds(), usec);
}

void* datetime2ptime::convertible(PyObject* obj) {

	return PyDateTime_Check( obj ) ? obj : nullptr;
	// Si queremos un conversor de string seria: return PyString_Check( obj ) ? obj : nullptr;
}

void datetime2ptime::construct(PyObject* obj,
		converter::rvalue_from_python_stage1_data* data) {

	// Obtain a handle to the memory block that the converter has allocated for the C++ type.
	auto storage = reinterpret_cast<converter::rvalue_from_python_storage<
			boost::posix_time::ptime>*>(data)->storage.bytes;

	// Se puede hacer a lo bruto o por medio de la api de cada objeto, en este ejemplo
	// uilizamos la api de datetime: https://docs.python.org/2/c-api/datetime.html
	boost::gregorian::date date_only(PyDateTime_GET_YEAR(obj),
			PyDateTime_GET_MONTH(obj), PyDateTime_GET_DAY(obj));

	boost::posix_time::time_duration time_of_day(PyDateTime_DATE_GET_HOUR(obj),
			PyDateTime_DATE_GET_MINUTE(obj), PyDateTime_DATE_GET_SECOND(obj));

	time_of_day += boost::posix_time::microsec(
			PyDateTime_DATE_GET_MICROSECOND(obj));

	// si no hubieramos tenido la api, lo tendriamos que realizar: http://stackoverflow.com/questions/15842126/feeding-a-python-list-into-a-function-taking-in-a-vector-with-boost-python/15940413#15940413
	new (storage) boost::posix_time::ptime(date_only, time_of_day);
	data->convertible = storage;
}

void ConvertidoresDatetime() {
	PyDateTime_IMPORT;

	datetime2ptime();
	to_python_converter<boost::posix_time::ptime,
			ptime2datetime>();
}
}

//BOOST_PYTHON_MODULE(rc_datetime)
//{
//
//	python_boost_date_time::ConvertidoresDatetime();
////	// metodos definimos por mi
////	def("tomorrow", python_boost_date_time::tomorrow);
////	//Con el metodo day_before hemos asegurado que los conversores funcion una vez definimos
////	def("day_before", python_boost_date_time::day_before, args("moment"));
//
//}

