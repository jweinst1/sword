
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(sword_csv_tests sword_csv_tests.c)
target_link_libraries(sword_csv_tests PRIVATE swordc)
add_test(sword_csv_tests sword_csv_tests)