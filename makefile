final: utPodDriver.o utPod.o song.o
	g++ -o test utPodDriver.o utPod.o song.o
driver: utPodDriver.cpp utPod.h song.h
	g++ -c utPodDriver.cpp
UtPod.o: utPod.cpp utPod.h song.h
	g++ -c utPod.cpp
Song.o: song.cpp song.h
	g++ -c song.cpp
