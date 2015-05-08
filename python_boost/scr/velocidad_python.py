
import numpy as np
import hello_ext as h
import timeit
import pandas as pd


factor_multiplicacion = 2.1
numero_de_elementos = 10000000
n_veces=3

mi_vector_for_normal = np.arange(1.1,numero_de_elementos,factor_multiplicacion)
mi_vector_boost_cplusplus = np.arange(1.1,numero_de_elementos,factor_multiplicacion)
mi_vector_vectorizacion = np.arange(1.1,numero_de_elementos,factor_multiplicacion)
mi_vector_iterador = np.arange(1.1,numero_de_elementos,factor_multiplicacion)
mi_vector_map = np.arange(1.1,numero_de_elementos,factor_multiplicacion)
mi_vector_pandas = np.arange(1.1,numero_de_elementos,factor_multiplicacion)

def Vectorizacion():    
    g = np.vectorize(lambda x: x * factor_multiplicacion)
    aux=g(mi_vector_vectorizacion)


def ForNormal():
    for i, elemento in enumerate(mi_vector_for_normal):
        mi_vector_for_normal[i] = elemento * factor_multiplicacion
    
def BoostCplusPlus():
    aux=h.bucle_np(mi_vector_boost_cplusplus, factor_multiplicacion)

def IteradoresNumpy():
    for x in np.nditer(mi_vector_iterador, op_flags=['readwrite']):
        x[...] = factor_multiplicacion * x
        
def PorMaps():
    aux=map(lambda x: x * factor_multiplicacion,mi_vector_map)
 
def Pandas():
    a=pd.DataFrame(mi_vector_pandas)
    a=a*factor_multiplicacion
 
        
tiempo_vectorizacion = np.average(timeit.Timer(Vectorizacion).repeat(repeat=1, number=n_veces)) / n_veces;
tiempo_for = np.average(timeit.Timer(ForNormal).repeat(repeat=1, number=n_veces)) / n_veces;
tiempo_boost=np.average(timeit.Timer(BoostCplusPlus).repeat(repeat=1, number=n_veces))/n_veces;
tiempo_pandas = np.average(timeit.Timer(Pandas).repeat(repeat=1, number=n_veces)) / n_veces;
tiempo_maps = np.average(timeit.Timer(PorMaps).repeat(repeat=1, number=n_veces)) / n_veces;

      
print "Tiempo por vecto: {}\nTiempo por ForNo: {}\nTiempo por boost: {}\nTiempo por Pandas: {}\nTiempo por Mapss: {}" .format(tiempo_vectorizacion,
                                                                                                                                                tiempo_for,
                                                                                                                                                tiempo_boost,
                                                                                                                                                tiempo_pandas,
                                                                                                                                                tiempo_maps)
