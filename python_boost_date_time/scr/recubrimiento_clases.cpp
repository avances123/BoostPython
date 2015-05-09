#include "../include/recubrimiento_clases.h"

using namespace boost::python;

namespace python_boost_date_time {

template<> PyObject* python_boost_date_time::ptime2datetime<
		boost::posix_time::ptime>::convert(boost::posix_time::ptime const&t) {
	auto d = t.date();
	auto tod = t.time_of_day();
	auto usec = tod.total_microseconds() % 1000000;
	// Utlizamola api de datetime: https://docs.python.org/2/c-api/datetime.html
	return PyDateTime_FromDateAndTime(d.year(), d.month(), d.day(), tod.hours(),
			tod.minutes(), tod.seconds(), usec);
}

boost::posix_time::ptime tomorrow() {
	return boost::posix_time::microsec_clock::local_time()
			+ boost::gregorian::days(1);
}

boost::posix_time::ptime day_before(boost::posix_time::ptime const&that) {
	return that - boost::gregorian::days(1);
}

template<> void* datetime2ptime<boost::posix_time::ptime>::convertible(
		PyObject* obj) {

	return PyDateTime_Check( obj ) ? obj : nullptr;
	// Si queremos un conversor de string seria: return PyString_Check( obj ) ? obj : nullptr;
}

template<> void datetime2ptime<boost::posix_time::ptime>::construct(
		PyObject* obj, converter::rvalue_from_python_stage1_data* data) {

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
}

BOOST_PYTHON_MODULE(recubrimiento_clases)
{
	PyDateTime_IMPORT;

	python_boost_date_time::datetime2ptime<boost::posix_time::ptime>();
	to_python_converter<boost::posix_time::ptime,
			python_boost_date_time::ptime2datetime<boost::posix_time::ptime> >();
	// metodos definimos por mi
	def("tomorrow", python_boost_date_time::tomorrow);
	//Con el metodo day_before hemos asegurado que los conversores funcion una vez definimos
	def("day_before", python_boost_date_time::day_before, args("moment"));

}

