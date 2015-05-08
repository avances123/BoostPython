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

boost::python::object stdVecToNumpyArray(std::vector<double> const& vec) {
	//Se saca el segundo parametro
	npy_intp size = vec.size();

	/* const_cast is rather horrible but we need a writable pointer
	 in C++11, vec.data() will do the trick
	 but you will still need to const_cast
	 */

	/*Se saca el 4 paremtro, la primera direccion de memoria: Se tiene que utilizar
	 const_char<> para poder realizar el casting a un puntero no constante, asi puede aputnar
	 pero nunca podrá cambiar el valor a lo que apunta. Si no se consigue realizar el casting
	 se devuelve un putnero a NULL
	 */
	std::cout << "1p..." << std::endl;
	double * data =
			size ? const_cast<double *>(vec.data()) : static_cast<double *>(NULL);

	// create a PyObject * from pointer and data
	//Para mas informacion: http://docs.scipy.org/doc/numpy/user/c-info.how-to-extend.html
	std::cout << "2p..." << std::endl;
	if (data == NULL) {
		std::cout << "es nulo" << std::endl;
	}
	PyObject * pyObj = PyArray_SimpleNewFromData(1, &size, NPY_DOUBLE, data);
	std::cout << "2_1p..." << std::endl;
	// Se crear un smart pointer, para mas informacion: https://wiki.python.org/moin/boost.python/handle
	boost::python::handle<> handle(pyObj);
	//Conversion al tipo elegido
	std::cout << "2_2p..." << std::endl;
	boost::python::numeric::array arr(handle);

	/* The problem of returning arr is twofold: firstly the user can modify
	 the data which will betray the const-correctness
	 Secondly the lifetime of the data is managed by the C++ API and not the
	 lifetime of the numpy array whatsoever. But we have a simple solution..
	 */

	/* Para curarnos en salud, se realiza la copia para que se pueda realizar cambios
	 y no tener en cuenta la vida util
	 */
	std::cout << "3p..." << std::endl;
	return arr.copy(); // copy the object. numpy owns the copy now.
}

namespace py = boost::python;

char const* mi_hola_dese_cpp() {
	return "hello, world";
}

int cinco(int aux) {
	return aux * 5;
}

void nombre(py::str name) {
	py::object n2 = name.attr("upper")();   // NAME = name.upper()
	py::str NAME = name.upper();
	py::object msg = "%s is bigger than %s" % py::make_tuple(NAME, name);
}

void setArray(py::numeric::array data) {

	py::numeric::array a = data; //para poder entrar a las funciones sin attr
	std::cout << "First array item: " << py::extract<int>(a[0]) << std::endl;
}

py::numeric::array bucle_np(py::numeric::array const& ob,
		double const & factor) {
	//std::cout<<"Creando vector..."<<std::endl;
	py::stl_input_iterator<double> begin(ob), end;
	std::vector<double> mi_vector(begin, end);

	//std::cout<<"Ejecutando sentencias..."<<std::endl;
	std::transform(mi_vector.begin(), mi_vector.end(), mi_vector.begin(),
			[&factor](double a) {return (a*factor);});

	//std::cout<<"Guardo resultado..."<<std::endl;
	py::list a;
	for (auto const &i : mi_vector)
		a.append(std::move(i));

	return py::numeric::array(a);
}

/*//Asi va mas lento
 py::numeric::array bucle_np(py::numeric::array & ob,double const & factor)
 {
 for (auto i = 0; i < py::len(ob); ++i) {
 ob[i]*=factor;
 }
 return ob;
 }*/

template<typename T>
std::list<T> sequence_to_list(py::object const& ob) {
	py::stl_input_iterator<T> begin(ob), end;
	return std::list<T>(begin, end);
}

BOOST_PYTHON_MODULE(hello_ext)
{

	/**
	 * Para que salga este error
	 *
	 * Boost.Python.ArgumentError: Python argument types in
	 * hello_ext.setArray(numpy.ndarray)
	 * did not match C++ signature:
	 * setArray(boost::python::numeric::array)
	 *
	 */
	py::numeric::array::set_module_and_type("numpy", "ndarray");

	def("bucle_np", &bucle_np, "La ayuda para completar una funcion");

}
