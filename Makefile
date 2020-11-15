#main: neuron.o layer.o connector.o testlayer testconnector
#	g++ -g -Wall connector.o layer.o neuron.o main.cpp -O0 -o main.exe

#testconnector: neuron.o layer.o connector.o testlayer
#	g++ -g -Wall connector.o layer.o neuron.o connectorTest.cpp -O0 -o connector.exe

testtube: tube.o
	g++ -g -Wall tubeTest.cpp tube.o -O0 -o tube.exe

#testlayer: neuron.o layer.o testneuron
#	g++ -g -Wall layerTest.cpp  neuron.o layer.o -O0 -o layer.exe

#connector: neuron.o layer.o connector.h connector.cpp
#	g++ -c -g neuron.o -Wall layer.o connector.cpp -O0

tube: tube.h tube.cpp 
	g++ -c -g -Wall tube.cpp -O0

#rack: tube.o testTubeRack.h testTubeRack.cpp
#	g++ -c -g -Wall tube.o testTubeRack.cpp -O0

clean:
	rm *.o
	rm *.exe

