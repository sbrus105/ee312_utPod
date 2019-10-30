final: utPodDriver.o utPod.o song.o
	g++ -o test UtPodDriver.o UtPod.o Song.o
driver: utPodDriver.cpp utPod.h song.h
	g++ -c UtPodDriver.cpp
UtPod.o: utPodDriver.cpp utPod.h song.h
	g++ -c UtPod.cpp
Song.o: song.cpp song.h
	g++ -c Song.cpp
