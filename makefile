all:
	g++ -c lib/system.cpp -o lib/bin/system.o 
	g++ -c main.cpp -o main.o 
	g++ lib/bin/*.o main.o -o main -lwiringPi -lpthread
clean:
	rm main.o lib/bin/*.o
run:
	sudo ./main
