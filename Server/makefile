.SUFFIXES: .cpp .o
CC = g++
CFLAGS = -std=c++11
OBJDIR = object_files
vpath %.cpp main Argument_Data Argument_Manager Circular_Buffer Date Preparator Query_Executor Query_Executor/Query_Handler/Disease_Frequency Query_Executor/Query_Handler/Num_Patient_Admissions Query_Executor/Query_Handler/Num_Patient_Discharges Query_Executor/Query_Handler/Search_Patient_Record Query_Executor/Query_Handler/Topk_Age Server_Thread Socket Socket_Handler Stats_Reader Socket_IO_Handler Thread_Manager Tokenizer Worker_Socket Worker_Socket_List
OUT = whoServer
OBJ = $(addprefix $(OBJDIR)/,Argument_Data.o Argument_Manager.o Circular_Buffer.o Date.o Preparator.o Query_Executor.o Disease_Frequency.o Num_Patient_Admissions.o Num_Patient_Discharges.o Search_Patient_Record.o Topk_Age.o Server_Thread.o Socket.o Socket_Handler.o Socket_IO_Handler.o Thread_Manager.o Tokenizer.o Worker_Socket.o Worker_Socket_List.o Stats_Reader.o main.o )

make: make_dir $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OUT) -pthread

$(OBJDIR)/%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -pthread

make_dir:
	mkdir $(OBJDIR)

clean:
	rm $(OBJDIR)/*.o
	rmdir $(OBJDIR)