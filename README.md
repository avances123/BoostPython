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
