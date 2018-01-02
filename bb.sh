#!/bin/bash
# Bear-Biscuits.cpp
# 把bb.sh加上x权限: chmod a+x bb.sh
# 使用方法: ./bb.sh [start|stop|restart] 
# 测试的时候使用，仅开一个进程

if [ $1 = "start" ]; then
    echo "正在打开..."
    g++ -o index.cgi Bear-Biscuits.cpp -L /usr/local/lib/ -lfcgi
    spawn-fcgi -a 127.0.0.1 -p 8081 -u www -f ./index.cgi -F 1 -P /tmp/fcgi.pid
elif [ $1 = "stop" ]; then
    if [ -f "/tmp/fcgi.pid" -a -s "/tmp/fcgi.pid" ]; then
        # 是文件且有值
        echo "正在关闭..."
        kill -9 `cat /tmp/fcgi.pid`
    else
        echo "不存在fcgi.pid或fcgi.pid没有存储进程id"
    fi
elif [ $1 = "restart" ]; then
    echo "正在关闭..."
    kill -9 `cat /tmp/fcgi.pid`
    echo "正在打开..."
    g++ -o index.cgi Bear-Biscuits.cpp -L /usr/local/lib/ -lfcgi
    spawn-fcgi -a 127.0.0.1 -p 8081 -u www -f ./index.cgi -F 1 -P /tmp/fcgi.pid
else
    echo "暂不支持的操作，目前仅支持: ./bb.sh [start|stop|restart]"
fi
