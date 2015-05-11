rm -rf bin/*
g++ -I../convertidores -I../utiles -I/usr/include/python3.4m -O3 -Wall -c -fmessage-length=0 -std=c++11 -fPIC -MMD -MP -MFbin/wrapper_utiles_serie_historica.d -MTbin/wrapper_utiles_serie_historica.d -o bin/wrapper_utiles_serie_historica.o src/wrapper_utiles_serie_historica.cpp

g++ -L"../convertidores/bin" -L"../utiles/bin" -fPIC -shared -Wl,-soname=conversores.so -o "bin/wrapper_utiles_serie_historica.so"  bin/wrapper_utiles_serie_historica.o   -lconvertidores -lutiles -lboost_python-py34

cp bin/wrapper_utiles_serie_historica.so EjemploPython/

