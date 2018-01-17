# This is the Makefile

# json_demo:ReturnModel.o BBUserModel.o json_demo.cpp
# 	g++ ReturnModel.o BBUserModel.o json_demo.cpp -o json_demo
# ReturnModel.o:lib/model/ReturnModel.cpp
# 	g++ -c lib/model/ReturnModel.cpp -o ReturnModel.o
# BBUserModel.o:lib/model/BBUserModel.cpp
# 	g++ -c lib/model/BBUserModel.cpp -o BBUserModel.o

    # g++ -o index.cgi Bear-Biscuits.cpp -L /usr/local/lib/ -lfcgi
# index.cgi:BaseController.o HelloController.o Bear-Biscuits.cpp
# 	g++ -o index.cgi BaseController.o HelloController.o Bear-Biscuits.cpp -L /usr/local/lib/ -lfcgi

# BaseController.o:controller/lib/BaseController.cpp
# 	g++ -c controller/lib/BaseController.cpp -L /usr/local/lib/ -lfcgi
# HelloController.o:controller/lib/HelloController.cpp
# 	g++ -c controller/lib/HelloController.cpp -L /usr/local/lib/ -lfcgi

# index.cgi:Bear-Biscuits.cpp
# 	g++ -o index.cgi Bear-Biscuits.cpp -L /usr/local/lib/ -lfcgi

CFLAGS = -Wall -O -g
FCGILIB = -lfcgi

index.cgi:Bear-Biscuits.cpp libwebroute.a
	g++ -o index.cgi Bear-Biscuits.cpp libwebroute.a -L /usr/local/lib/ -lfcgi

libwebroute.a:BaseController.o Request.o env.o constant.o Factory.o urlcode.o Route.o
	ar crv libwebroute.a BaseController.o Request.o env.o constant.o Factory.o urlcode.o Route.o
BaseController.o:lib/WebRoute/lib/BaseController.cpp Request.o env.o constant.o urlcode.o
	g++ -c lib/WebRoute/lib/BaseController.cpp Request.o env.o constant.o urlcode.o -o BaseController.o
Request.o:lib/WebRoute/lib/Request.cpp env.o
	g++ -c lib/WebRoute/lib/Request.cpp env.o
Factory.o:lib/WebRoute/lib/Factory.cpp
	g++ -c lib/WebRoute/lib/Factory.cpp
env.o:lib/WebRoute/lib/env.cpp
	g++ $(CFLAGS) -c lib/WebRoute/lib/env.cpp $(FCGILIB)
urlcode.o:lib/WebRoute/lib/urlcode.cpp
	g++ -c lib/WebRoute/lib/urlcode.cpp
Route.o:lib/WebRoute/lib/Route.cpp
	g++ -c lib/WebRoute/lib/Route.cpp
constant.o:lib/WebRoute/lib/constant.cpp
	g++ -c lib/WebRoute/lib/constant.cpp

# constant.o:lib/WebRoute/lib/constant.cpp
# 	g++ -c lib/WebRoute/lib/constant.cpp

clean:
	rm -f *.o



# #include "lib/WebRoute/include/env.h"
# #include "lib/WebRoute/include/constant.h"
# #include <map>
# // 这些不要去include 库里面的内容，到时候提取出来
# #include "lib/WebRoute/include/Request.h"
# #include "lib/WebRoute/include/urlcode.h"
# #include "lib/WebRoute/include/htmlspecialchar.h"
# #include "lib/WebRoute/routes.h"