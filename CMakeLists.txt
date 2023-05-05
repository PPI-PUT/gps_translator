cmake_minimum_required(VERSION 3.14)
project(gps_translator)

# require that dependencies from package.xml be available
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies(REQUIRED
  ${${PROJECT_NAME}_BUILD_DEPENDS}
  ${${PROJECT_NAME}_BUILDTOOL_DEPENDS}
)
add_compile_options(-Wall -Wextra -pedantic -Werror)

set(GPS_TRANSLATOR_NODE_SRC
  src/gps_translator_node.cpp
)

set(GPS_TRANSLATOR_NODE_HEADERS
  include/gps_translator/visibility_control.hpp
  include/gps_translator/gps_translator_node.hpp
)

# generate component node library
ament_auto_add_library(${PROJECT_NAME}_node SHARED
  ${GPS_TRANSLATOR_NODE_HEADERS}
  ${GPS_TRANSLATOR_NODE_SRC}
)
rclcpp_components_register_node(${PROJECT_NAME}_node
  PLUGIN "gps_translator::GpsTranslatorNode"
  EXECUTABLE ${PROJECT_NAME}_node_exe
)

# ament package generation and installing
ament_auto_package(INSTALL_TO_SHARE
  launch
  param
)
