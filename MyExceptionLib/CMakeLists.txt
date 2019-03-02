file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_library(${MyExceptionLib} STATIC ${srcs} ${hdrs})


