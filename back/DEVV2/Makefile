CXX = g++ -g -pg  -fprofile-arcs -ftest-coverage -fpermissive
CFLAGS = -fPIC -fpermissive
MYFLAGS = -DTIME_INFO -Wno-deprecated  -fpermissive
INC =  -I  . 

CXXFLAGS = $(INC)
LDFLAGS =

SOURCES = \
    ./api.cpp \
    ./3DS.cpp \
    ./kh_project.cpp \
    ./clip.cpp \
    ./image_util.cpp \
    ./init.cpp \
    ./main.cpp 

OBJ = \
    ./api.o \
    ./3DS.o \
    ./kh_project.o \
    ./clip.o \
    ./image_util.o \
    ./init.o \
    ./main.o 

Decoder: $(OBJ) main.o
	$(CXX) $(CXXFLAGS) -o Draw3D $(OBJ) $(LDFLAGS)  -ldl -lpthread

clean:
	-rm Draw3D *.gc* *.gc*  *.o 

# $(OBJ)
