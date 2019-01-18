g++ -g -pg  -fprofile-arcs -ftest-coverage  *.cpp -I ./include -c -fpermissive
ar rcs ../libtest.a *.o
