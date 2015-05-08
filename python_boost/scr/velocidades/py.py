
import numpy as np
import hello_ext as h
import timeit

factor_multiplicacion = 2
numero_de_elementos = 1000000
n_veces=3

mi_vector_for_normal = np.arange(numero_de_elementos)
mi_vector_boost_cplusplus = np.arange(numero_de_elementos)
mi_vector_vectorizacion = np.arange(numero_de_elementos)
mi_vector_iterador = np.arange(numero_de_elementos)
mi_vector_map = np.arange(numero_de_elementos)


def Vectorizacion(mi_vector_vectorizacion):    
    g = np.vectorize(lambda x: x * factor_multiplicacion)
    g(mi_vector_vectorizacion)


def ForNormal(mi_vector_for_normal):
    for i, elemento in enumerate(mi_vector_for_normal):
        mi_vector_for_normal[i] = elemento * factor_multiplicacion
    
def BoostCplusPlus(mi_vector_boost_cplusplus):
    mi_vector_boost_cplusplus=h.bucle_np(mi_vector_boost_cplusplus, factor_multiplicacion)

def IteradoresNumpy(mi_vector_iterador):
    for x in np.nditer(mi_vector_iterador, op_flags=['readwrite']):
        x[...] = 2 * x
        
def PorMaps(mi_vector_map):
    map(lambda x: x * factor_multiplicacion,mi_vector_map)
     
        
tiempo_vectorizacion = np.average(timeit.Timer(Vectorizacion).repeat(repeat=1, number=n_veces)) / n_veces;
tiempo_for = np.average(timeit.Timer(ForNormal).repeat(repeat=1, number=n_veces)) / n_veces;
tiempo_boost=np.average(timeit.Timer(BoostCplusPlus).repeat(repeat=1, number=n_veces))/n_veces;
tiempo_it = np.average(timeit.Timer(IteradoresNumpy).repeat(repeat=1, number=n_veces)) / n_veces;
tiempo_maps = np.average(timeit.Timer(PorMaps).repeat(repeat=1, number=n_veces)) / n_veces;
        
print "Tiempo por vectorizacion: {}, valor:{}\nTiempo por ForNormal: {}, valor:{}\nTiempo por la boost: {}, valor:{}\nTiempo por Iteradores: {}, valor:{}\nTiempo por Maps: {}, valor:{}" .format(
                                                                                                                                                                                                  tiempo_vectorizacion,
                                                                                                                                                                                                  mi_vector_vectorizacion[:20],
                                                                                                                                                                                                  tiempo_for,
                                                                                                                                                                                                  mi_vector_for_normal[:20],
                                                                                                                                                                                                  tiempo_boost,
                                                                                                                                                                                                  mi_vector_boost_cplusplus[:20],
                                                                                                                                                                                                  tiempo_it,
                                                                                                                                                                                                  mi_vector_iterador[:20],
                                                                                                                                                                                                  tiempo_maps,
                                                                                                                                                                                                  mi_vector_map[:20])
