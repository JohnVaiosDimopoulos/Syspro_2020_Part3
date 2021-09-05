cmake_minimum_required(VERSION 3.16)
project(Client)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(Client main/main.cpp Argument_Manager/Argument_Manager.h Argument_Manager/Argument_Manager.cpp Argument_Data/Argument_Data.h Argument_Data/Argument_Data.cpp Socket_IO_Handler/Socket_IO_Handler.h Socket_IO_Handler/Socket_IO_Handler.cpp Thread_Data/Thread_Data.cpp Thread_Data/Shared_Data.h Thread_Data/Thread_Data.h Thread_Manager/Thread_Manager.cpp Thread_Manager/Thread_Manager.h Thread_Wrapper/Thread_Wrapper.h Client_Thread/Client_Thread.cpp Client_Thread/Client_Thread.h Generic_List/Generic_List.h Client_Socket/Client_Socket.cpp Client_Socket/Client_Socket.h)