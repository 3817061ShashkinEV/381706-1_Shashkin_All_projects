file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${ArrList} ${srcs} ${hdrs})
target_link_libraries(${ArrList} ${ArrListLib})