/*
 * envoltorio_objetos_iterables.cpp
 *
 *  Created on: May 10, 2015
 *      Author: pedro
 */

#include "../include/envoltorio_objetos_iterables.h"

namespace convertidores {

template<typename Container>
iterador_convertible&
iterador_convertible::from_python() {
	boost::python::converter::registry::push_back(
			&iterador_convertible::convertible,
			&iterador_convertible::construct<Container>,
			boost::python::type_id<Container>());

	// Support chaining.
	return *this;
}

/// @brief Check if PyObject is iterable.
void* iterador_convertible::convertible(PyObject* object) {
	return PyObject_GetIter(object) ? object : NULL;
}

/// @brief Convert iterable PyObject to C++ container type.
///
/// Container Concept requirements:
///
///   * Container::value_type is CopyConstructable.
///   * Container can be constructed and populated with two iterators.
///     I.e. Container(begin, end)
template<typename Container>
void iterador_convertible::construct(PyObject* object,
		converter::rvalue_from_python_stage1_data* data) {
	namespace python = boost::python;
	// Object is a borrowed reference, so create a handle indicting it is
	// borrowed for proper reference counting.
	python::handle<> handle(python::borrowed(object));

	// Obtain a handle to the memory block that the converter has allocated
	// for the C++ type.
	typedef converter::rvalue_from_python_storage<Container> storage_type;
	void* storage = reinterpret_cast<storage_type*>(data)->storage.bytes;

	typedef python::stl_input_iterator<typename Container::value_type> iterator;

	// Allocate the C++ type into the converter's memory block, and assign
	// its handle to the converter's convertible variable.  The C++
	// container is populated by passing the begin and end iterators of
	// the python object to the container's constructor.
	new (storage) Container(iterator(boost::python::object(handle)), // begin
	iterator());                      // end
	data->convertible = storage;
}

void ConvertidoresVectorDouble(){
	iterador_convertible().from_python<std::vector<double>>();
}

} /* namespace conversores */
