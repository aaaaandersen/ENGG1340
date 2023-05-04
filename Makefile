makefile
# 目标文件
TARGET = game 
OBJS = main.o battle.o enemy.o player.o save.o map.o

# 编译器和选项
CC = g++
CFLAGS = -std=c++11

# 依赖关系
$(TARGET): $(OBJS)
    $(CC) $(OBJS) -o $(TARGET)

main.o: main.cpp
    $(CC) $(CFLAGS) -c main.cpp   

battle.o: battle.cpp battle.h 
    $(CC) $(CFLAGS) -c battle.cpp   

enemy.o: enemy.cpp enemy.h
    $(CC) $(CFLAGS) -c enemy.cpp
      
player.o: player.cpp player.h
    $(CC) $(CFLAGS) -c player.cpp  
    
save.o: save.cpp save.h
    $(CC) $(CFLAGS) -c save.cpp     

map.o: map.cpp map.h
    $(CC) $(CFLAGS) -c map.cpp

# 清理目标文件和输出文件
clean:  
    rm -f $(OBJS) $(TARGET) *~
    
# 编译并运行 
run: 
    ./$(TARGET) 
