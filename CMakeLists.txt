CMAKE_MINIMUM_REQUIRED ( VERSION 2.8.3 )


project (mycrc32)

SET(
    CMAKE_BUILD_TYPE
    Release
)
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES(SYSTEM ${Boost_INCLUDE_DIR} )

#Bring the headers into the project
include_directories(include)

file(
    GLOB_RECURSE
    SOURCES
    src/*.cpp
)

ADD_LIBRARY (
     ${PROJECT_NAME}
     SHARED
     ${SOURCES}
     ${HEADERS}
)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

SET_TARGET_PROPERTIES (${PROJECT_NAME} PROPERTIES SUFFIX ".so")

ADD_EXECUTABLE (crc32exe ${SOURCES})

TARGET_LINK_LIBRARIES(
    crc32exe
    ${PROJECT_NAME}
    ${Boost_LIBRARIES}
)
