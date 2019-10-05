# SRC cmake #

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SWORD_CLIB_SOURCES
    sword_io.c
    sword_csv.c
)

add_library(swordc STATIC "${SWORD_CLIB_SOURCES}")
add_library(swordcsh SHARED "${SWORD_CLIB_SOURCES}")

if(WITH_testing MATCHES ON)
   add_subdirectory(tests)
endif(WITH_testing MATCHES ON)