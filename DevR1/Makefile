CXX = g++ -g -pg  -fprofile-arcs -ftest-coverage -fpermissive
CFLAGS = -fPIC -fpermissive
MYFLAGS = -DTIME_INFO -Wno-deprecated  -fpermissive
INC =  -I  . 

CXXFLAGS = $(INC)
LDFLAGS =

SOURCES = \
    ./3DS.cpp \
    ./main.cpp 

OBJ = \
    ./3DS.o \
    ./main.o 

Decoder: $(OBJ) main.o
	$(CXX) $(CXXFLAGS) -o Draw3D $(OBJ) $(LDFLAGS)  -ldl -lpthread

clean:
	-rm Draw3D *.gc* *.gc*  *.o 

# $(OBJ)
