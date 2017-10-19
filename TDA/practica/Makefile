SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11

all:$(BIN)/pruebaVector

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(BIN)/pruebaVector: $(OBJ)/pruebaVector.o $(OBJ)/vd.o
	$(CXX) -o $(BIN)/pruebaVector $(OBJ)/pruebaVector.o $(OBJ)/vd.o
	
	
$(OBJ)/pruebaVector.o: $(SRC)/pruebaVector.cpp $(INC)/vd.h 
	$(CXX) $(CPPFLAGS)  $(SRC)/pruebaVector.cpp -o  $(OBJ)/pruebaVector.o 
		
	
$(OBJ)/vd.o: $(SRC)/vd.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/vd.cpp -o  $(OBJ)/vd.o 	

			
# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
