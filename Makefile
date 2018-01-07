# This is the Makefile

json_demo:ReturnModel.o BBUserModel.o json_demo.cpp
	g++ ReturnModel.o BBUserModel.o json_demo.cpp -o json_demo
ReturnModel.o:lib/model/ReturnModel.cpp
	g++ -c lib/model/ReturnModel.cpp -o ReturnModel.o
BBUserModel.o:lib/model/BBUserModel.cpp
	g++ -c lib/model/BBUserModel.cpp -o BBUserModel.o
