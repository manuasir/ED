SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11

all:$(BIN)/prueba_sp

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(BIN)/pruebaVector: $(OBJ)/pruebaVector.o
	$(CXX) -o $(BIN)/pruebaVector $(OBJ)/pruebaVector.o 
	
$(OBJ)/pruebaVector.o: $(SRC)/pruebaVector.cpp $(INC)/vd.h 
	$(CXX) $(CPPFLAGS)  $(SRC)/pruebaVector.cpp -o  $(OBJ)/pruebaVector.o 

$(BIN)/prueba: $(OBJ)/prueba.o
	$(CXX) -o $(BIN)/prueba $(OBJ)/prueba.o 
	
$(OBJ)/prueba.o: $(SRC)/prueba.cpp $(INC)/matriz_dispersa.h 
	$(CXX) $(CPPFLAGS)  $(SRC)/prueba.cpp -o  $(OBJ)/prueba.o 

$(BIN)/prueba_sp: $(OBJ)/prueba_sp.o
	$(CXX) -o $(BIN)/prueba_sp $(OBJ)/prueba_sp.o 
	
$(OBJ)/prueba_sp.o: $(SRC)/prueba_sp.cpp $(INC)/matriz_dispersa.h 
	$(CXX) $(CPPFLAGS)  $(SRC)/prueba_sp.cpp -o  $(OBJ)/prueba_sp.o 
		

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
