# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\NS_conv_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\NS_conv_autogen.dir\\ParseCache.txt"
  "NS_conv_autogen"
  )
endif()
