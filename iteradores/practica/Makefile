
SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c -std=c++11


all: $(BIN)/sp2
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
$(BIN)/prueba_sopa_letras: $(OBJ)/prueba_sopa_letras.o
	$(CXX) -o $(BIN)/prueba_sopa_letras $(OBJ)/prueba_sopa_letras.o

$(OBJ)/prueba_sopa_letras.o: $(SRC)/prueba_sopa_letras.cpp $(INC)/matriz_dispersa.h
	$(CXX) $(CPPFLAGS)  $(SRC)/prueba_sopa_letras.cpp -o  $(OBJ)/prueba_sopa_letras.o

$(BIN)/sp2: $(OBJ)/sp2.o
	$(CXX) -o $(BIN)/sp2 $(OBJ)/sp2.o

$(OBJ)/sp2.o: $(SRC)/sp2.cpp $(INC)/matriz_dispersa.h $(INC)/diccionario.h
	$(CXX) $(CPPFLAGS)  $(SRC)/sp2.cpp -o  $(OBJ)/sp2.o

$(BIN)/prueba_matriz_dispersa: $(OBJ)/prueba_matriz_dispersa.o
	$(CXX) -o $(BIN)/prueba_matriz_dispersa $(OBJ)/prueba_matriz_dispersa.o

$(OBJ)/prueba_matriz_dispersa.o: $(SRC)/prueba_matriz_dispersa.cpp $(INC)/matriz_dispersa.h
	$(CXX) $(CPPFLAGS)  $(SRC)/prueba_matriz_dispersa.cpp -o  $(OBJ)/prueba_matriz_dispersa.o

$(BIN)/pruebadiccionario: $(OBJ)/pruebadiccionario.o  $(OBJ)/diccionario.o
	$(CXX) -o $(BIN)/pruebadiccionario $(OBJ)/pruebadiccionario.o $(OBJ)/diccionario.o

$(OBJ)/pruebadiccionario.o:$(SRC)/pruebadiccionario.cpp $(INC)/diccionario.h
	$(CXX) $(CPPFLAGS) $(SRC)/pruebadiccionario.cpp -o $(OBJ)/pruebadiccionario.o

$(OBJ)/diccionario.o:$(SRC)/diccionario.cpp $(INC)/diccionario.h
	$(CXX) $(CPPFLAGS) $(SRC)/diccionario.cpp -o $(OBJ)/diccionario.o


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
