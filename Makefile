# This is the Makefile

json_demo:ReturnModel.o json_demo.cpp
	g++ ReturnModel.o json_demo.cpp -o json_demo
ReturnModel.o:lib/model/ReturnModel.cpp
	g++ -c lib/model/ReturnModel.cpp -o ReturnModel.o
