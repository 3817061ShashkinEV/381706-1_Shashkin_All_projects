file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${PolishNotationTest} ${srcs} ${hdrs})
target_link_libraries(${PolishNotationTest} ${PolishNotationLib} gtest)