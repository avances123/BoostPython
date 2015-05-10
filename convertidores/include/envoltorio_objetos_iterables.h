/*
 * envoltorio_objetos_iterables.h
 *
 *  Created on: May 10, 2015
 *      Author: pedro
 */

#ifndef SCR_ENVOLTORIO_OBJETOS_ITERABLES_H_
#define SCR_ENVOLTORIO_OBJETOS_ITERABLES_H_

#include <iostream>
#include <list>
#include <vector>
#include <boost/python.hpp>
#include <boost/python/stl_iterator.hpp>

/// Esta sacado de: http://stackoverflow.com/questions/15842126/feeding-a-python-list-into-a-function-taking-in-a-vector-with-boost-python/15940413#15940413

using namespace boost::python;

namespace convertidores {
struct iterador_convertible {
	/// @note Registers converter from a python interable type to the
	///       provided type.
	template<typename Container>
	iterador_convertible&
	from_python();

	/// @brief Check if PyObject is iterable.
	static void* convertible(PyObject* object);

	/// @brief Convert iterable PyObject to C++ container type.
	///
	/// Container Concept requirements:
	///
	///   * Container::value_type is CopyConstructable.
	///   * Container can be constructed and populated with two iterators.
	///     I.e. Container(begin, end)
	template<typename Container>
	static void construct(PyObject* object,
			boost::python::converter::rvalue_from_python_stage1_data* data);
};

void ConvertidoresVectorDouble();

} /* namespace conversores */

#endif /* SCR_ENVOLTORIO_OBJETOS_ITERABLES_H_ */
