/*
 * recubrimiento_clases.h
 *
 *  Created on: May 9, 2015
 *      Author: pedro
 */

#ifndef INCLUDE_RECUBRIMIENTO_CLASES_H_
#define INCLUDE_RECUBRIMIENTO_CLASES_H_

//  Copyright Joel de Guzman 2002-2004. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//  Hello World Example from the tutorial
//  [Joel de Guzman 10/9/2002]

//Se necesita instalar python-devel
//Tambien decir que debemos incrustar en el linker -shared : no queremos el main
//Aparte, para construir libreris: -fpic, significa que nos da igual el orden
//Importantisimo: añadir la libreria dinamica boost_python

/*Lo mejor es sin eclipse para sacar la libreria:
 * g++ -I/usr/local/include -I/usr/include/python2.7 -fpic -c -o hello_ext.o hello_ext.cpp
 * g++ -shared -Wl,-soname,"hello_ext.so" -L/usr/local/lib hello_ext.o -lboost_python -fpic -o hello_ext.so
 *
 * */

#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/python.hpp>
#include "boost/python/extract.hpp"
#include "boost/python/numeric.hpp"
#include "boost/python/stl_iterator.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <numpy/ndarrayobject.h>
#include <boost/assign/std/vector.hpp>
#include "include/SerieHistorica.h"
#include "include/matematicas/constantes.h"
#include "include/fechas/fechas.h"
#include <boost/uuid/uuid.hpp>
#include <boost/date_time.hpp>
#include "datetime.h"
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::python;

//http://sysmagazine.com/posts/168827/
//https://github.com/jktjkt/deska/blob/master/src/deska/LowLevelPyDeska/DateTimeConversions.cpp
//


namespace python_boost_date_time {

template<typename T>
/**
 * Clase Publica Conversor de un objeto c++ to python
 * 		- convert, obligatorio, se especifica la conversrion
 *
 * Para mas ayuda: http://www.boost.org/doc/libs/1_37_0/libs/python/doc/v2/to_python_converter.html
 */
struct ptime2datetime {
	/**
	 * Se tiene que crear en cualquier conversor de c++ to python, el metodo convert que devuelve un miembro estatico boost::python::PyObject
	 *
	 * @param
	 * @return
	 */
	static PyObject* convert(T const&);
};

/**
 * Metodo para probar el conversor c++2py
 *
 * @return
 */
boost::posix_time::ptime tomorrow();
/**
 * Metodo para probar el conversor py2c++
 *
 * @param that
 * @return
 */
boost::posix_time::ptime day_before(boost::posix_time::ptime const&that);


template<typename T>
/**
 * Conversor de py2c++, tiene que tener 3 metodos:
 * 		- Constructor de la clase que unicamente añade el registro del conversor
 * 		- convertible: Es la clave, asi la boost sabe que convsersor se utiliza para cada tipo python: PyDateTime_Check, PyString_Check, ...
 * 		- construct:
 *
 * Para mas ayuda:
 * 		- http://stackoverflow.com/questions/16105539/boost-python-custom-converter
 * 		- https://misspent.wordpress.com/2009/09/27/how-to-write-boost-python-converters/
 * 		- http://stackoverflow.com/questions/15842126/feeding-a-python-list-into-a-function-taking-in-a-vector-with-boost-python/15940413#15940413
 */
struct datetime2ptime {
	/**
	 * Registro del conversor
	 */
	datetime2ptime() {
		converter::registry::push_back(convertible, construct, type_id<T>());
	}

	/**
	 * Decide si la clase encargada de convertir el tipo
	 *
	 * @param
	 */
	static void* convertible(PyObject*);

	/**
	 * Directivas de como realizarlo
	 *
	 * @param
	 * @param
	 */
	static void construct(PyObject*,
			converter::rvalue_from_python_stage1_data*);
};
}

#endif /* INCLUDE_RECUBRIMIENTO_CLASES_H_ */
