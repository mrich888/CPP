OBJ = circle.o point.o main.o #目标文件
TARGET = main #生成的文件名

$(TARGET):$(OBJ)  #如何生成可执行文件main
	g++ -g $^ -o $@  

%.o:%.c
	g++ -c $^ -o $@

#circle.o:circle.cpp
#	g++ -c $^ -o $@

#point.o:point.cpp
#	g++ -c $^ -o $@

#main.o:main.cpp
#	g++ -c $^ -o $@

clean:
	@rm -rf *.o TARGET