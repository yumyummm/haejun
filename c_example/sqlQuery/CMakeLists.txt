cmake_minimum_required(VERSION 3.00)
project(bookSql)
set(SOURCES
    src/bookSql.c
    src/main.c
    )

#set(CMAKE_C_COMPILER "/usr/bin/gcc")

#set(CMAKE_C_STANDARD 99)
#set(CMAKE_C_STANDARD_REQUIRED ON)

#add_executable(bookSql /home/yujin/kubig2025/sqlQuery/bookSql.c)
add_executable(bookSql ${SOURCES})
target_include_directories(bookSql PRIVATE include)
target_include_directories(bookSql PRIVATE /usr/include/mysql)
target_link_directories(bookSql PRIVATE /usr/include/mysql)
target_link_libraries(bookSql PRIVATE mysqlclient)