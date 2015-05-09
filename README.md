# BoostPython
Extender el funcionamiento de python a traves de clases ya creadas en c++

## Que es?
Se va a añadir proyectos de eclipse relacionados entre si para poder realizar las pruebas facilmente, con su configuracion.

## Proyectos
  - **python_boost:** La principal, es la que crea la libreria de prueba y con la que vamos a empezar, si queremos hacer otras bilbiotecas con la misma cconfiguracion, unicamente decirle que me cree un proyecto con estas propiedades o sino, es excluyendo cpp ydejando solamente uno(ahora está asi). Aparte hay un script de python que mide las velocidad para probar la implementacion
  -  **utiles:** Libreria que queremos embeber en python. Por ahora unicamente tiene la clase SeriHistorica que tenemos que hay que embber, no unacemnte sus metodos creados sino tambien lso heredados, por ejemplo el iterador de la std::vector
  -  **PruebaLibreriaUtiles:** Son pruebas para probar la funcionalidad de la libreria utiles

## Que puede faltar u objetivos...
  - Para empezar, una clase que utilice la la clase SerieHistorica(por ejemplo,una libreria de utiles matematicas) y poder embeberla,claro...
  - Una SerieHistoricaSuperior que herede de la primera SerieHistorica y poder embeberla...

## Donde está?
El codigo está integro en: https://github.com/pvalienteverde/BoostPython

Los pasos a seguir:
  1. Ejectuar en el directorio dodne tengas los workspace de eclipse
      `git clone https://github.com/pvalienteverde/BoostPython.git`
  2. Crear un proyecto eclipse en la carpeta **BoostPython**
  3. Por ultimo: 
      4.1 File ->Import
      4.2 Git-> Proyects from git
      4.3 Seleccionamos la misma carpeta dodne está los proyectos y automaticamente tendremos toda la configuracion preparada para trabajar

  
  
