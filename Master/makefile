.SUFFIXES: .cpp .o
CC = g++
CFLAGS = -std=c++11
OBJDIR = object_files
vpath %.cpp main Argument_Data Argument_Manager AVL_Tree Date Hash_Table Hash_Bucket_Node Initializer Pipe_IO_Handler Max_Heap Max_heap_node Named_Pipe Patients_List Patient_Record System_Data Tokenizer Worker Worker/Worker_Command_Reader Worker/Worker_Command_Handler/Worker_Disease_Frequency Worker/Worker_Command_Handler/Worker_Num_Patient_Admissions Worker/Worker_Command_Handler/Worker_Num_Patient_Discharges Worker/Worker_Command_Handler/Worker_Search_Patient_Record Worker/Worker_Command_Handler/Worker_TopK_Age Worker_Data Worker_Stats Worker_Stats_List Parent Preparator Socket_IO_Handler Query_Socket Stats_Socket
OUT = Master
OBJ = $(addprefix $(OBJDIR)/,Argument_Data.o Argument_Manager.o AVL_Tree.o AVL_Tree_Node.o Date.o Hash_Table.o Hash_Bucket_Node.o Initializer.o Pipe_IO_Handler.o Max_Heap.o Max_heap_node.o Named_Pipe.o Patients_List.o Patient_Record.o System_Data.o Tokenizer.o Parent.o Preparator.o Worker.o Worker_Command_Reader.o Worker_Disease_Frequency.o Worker_Num_Patient_Admissions.o Worker_Num_Patient_Discharges.o Worker_Search_Patient_Record.o Worker_TopK_Age.o Worker_Data.o Worker_Stats.o Worker_Stats_List.o main.o Socket_IO_Handler.o Query_Socket.o Stats_Socket.o)

make: make_dir $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OUT)

$(OBJDIR)/%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ 

make_dir:
	mkdir $(OBJDIR)

clean:
	rm $(OBJDIR)/*.o
	rmdir $(OBJDIR)