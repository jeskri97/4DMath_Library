#--------------------------------------------------------------------------
# Math_Library project
#--------------------------------------------------------------------------

PROJECT(Math_Library)
FILE(GLOB Math_Library_headers code/*.h)
FILE(GLOB Math_Library_sources code/*.cc)

SET(files_Math_Library ${Math_Library_headers} ${Math_Library_sources})
SOURCE_GROUP("Math_Library" FILES ${files_Math_Library})

ADD_EXECUTABLE(Math_Library ${files_Math_Library})