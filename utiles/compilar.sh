g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -fPIC -MMD -MP -MFbin/SerieHistorica.d -MTbin/SerieHistorica.d -o bin/SerieHistorica.o src/SerieHistorica.cpp
ar -r bin/libutiles.a bin/SerieHistorica.o
