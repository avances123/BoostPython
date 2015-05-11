rm -rf bin/*
g++  -I/usr/include/python3.4m -O3 -Wall -c -fmessage-length=0 -std=c++11 -fPIC -MMD -MP -MF"bin/envoltorio_datetime.d" -MT"bin/envoltorio_datetime.d" -o "bin/envoltorio_datetime.o" "src/envoltorio_datetime.cpp"
g++ -I/usr/include/python3.4m -O3 -Wall -c -fmessage-length=0 -std=c++11 -fPIC -MMD -MP -MFbin/envoltorio_objetos_iterables.d -MTbin/envoltorio_objetos_iterables.d -o bin/envoltorio_objetos_iterables.o src/envoltorio_objetos_iterables.cpp
ar -r bin/libconvertidores.a ./bin/envoltorio_datetime.o ./bin/envoltorio_objetos_iterables.o
