file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${PolishNotationLib} STATIC ${srcs} ${hdrs})


