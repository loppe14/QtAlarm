# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "source/CMakeFiles/alarm_autogen.dir/AutogenUsed.txt"
  "source/CMakeFiles/alarm_autogen.dir/ParseCache.txt"
  "source/alarm_autogen"
  )
endif()
