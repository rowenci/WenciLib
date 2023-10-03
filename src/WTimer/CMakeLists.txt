aux_source_directory(. wtimer_src)
file(GLOB_RECURSE wtimer_include ../../include/WTimer/*.h)
add_library(WTimer STATIC ${wtimer_src} ${wtimer_include})
target_include_directories(WTimer PUBLIC ../../include/WTimer)