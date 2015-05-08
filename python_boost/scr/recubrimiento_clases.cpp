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

using namespace boost::python;

//http://sysmagazine.com/posts/168827/


//BOOST_PYTHON_MODULE(serie)
//{
//    class_<utiles::SerieHistorica>("SerieHistorica", init<std::vector<double>,boost::local_time::local_date_time>())
//        .def("UltimaFechaValida", &utiles::SerieHistorica::UltimaFechaValida);
//}
BOOST_PYTHON_MODULE(mymodule)
{
    class_<boost::gregorian::date>("Date")
        .add_property("year", &boost::gregorian::date::year)
        .add_property("month", &boost::gregorian::date::month)
    ;
}
