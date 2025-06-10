file(GLOB REALM_SOURCE
        "*.c"
        "*/*.c"
        "*.h"
        "*/*.h"
)

add_library(realm-engine ${REALM_SOURCE})
target_include_directories(realm-engine PRIVATE ${CMAKE_SOURCE_DIR}/engine ${CMAKE_SOURCE_DIR}/vendor/SDL/include ${CMAKE_SOURCE_DIR}/vendor/my-dear-logger/src)
target_link_libraries(realm-engine PRIVATE my-dear-logger SDL3::SDL3)