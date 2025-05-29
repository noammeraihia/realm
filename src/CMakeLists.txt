file(GLOB REALM_SOURCE
        "*.c"
        "*/*.c"
        "*.h"
        "*/*.h"
)

add_executable(realm ${REALM_SOURCE})
target_include_directories(realm PRIVATE ${CMAKE_SOURCE_DIR}/vendor/SDL/include ${CMAKE_SOURCE_DIR}/vendor/my-dear-logger/src)
target_link_libraries(realm PRIVATE my-dear-logger SDL3::SDL3)