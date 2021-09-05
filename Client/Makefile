.SUFFIXES: .cpp .o
CC = g++
CFLAGS = -std=c++11 
OBJDIR = object_files
vpath %.cpp main Argument_Data Argument_Manager Client_Socket Client_Thread Socket_IO_Handler Thread_Data Thread_Manager
OUT = whoClient
OBJ = $(addprefix $(OBJDIR)/,Argument_Data.o Argument_Manager.o Client_Socket.o Client_Thread.o Socket_IO_Handler.o Thread_Data.o Thread_Manager.o main.o)

make: make_dir $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OUT) -pthread

$(OBJDIR)/%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -pthread

make_dir:
	mkdir $(OBJDIR)

clean:
	rm $(OBJDIR)/*.o
	rmdir $(OBJDIR)
