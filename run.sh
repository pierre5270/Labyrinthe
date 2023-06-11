g++ -Wall -pedantic main.cpp $(pkg-config gtkmm-3.0 --cflags --libs)
export LD_PRELOAD=/lib/x86_64-linux-gnu/libpthread.so.0
./a.out