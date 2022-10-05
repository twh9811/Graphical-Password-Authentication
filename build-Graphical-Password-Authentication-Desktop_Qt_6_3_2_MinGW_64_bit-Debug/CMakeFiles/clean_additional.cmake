# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Graphical-Password-Authentication_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Graphical-Password-Authentication_autogen.dir\\ParseCache.txt"
  "Graphical-Password-Authentication_autogen"
  )
endif()
