file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${PolishNotation} ${srcs} ${hdrs})
target_link_libraries(${PolishNotation} ${PolishNotationLib})