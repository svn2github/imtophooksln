# Install script for directory: D:/Projects/ImPro/OtherLib/OpenCV2.1/OpenCV_SVN/include

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "D:/Projects/ImPro/OtherLib/GShow/OtherLib/OpenCV2.1/vs2008")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "main")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv" TYPE FILE FILES
    "D:/Projects/ImPro/OtherLib/OpenCV2.1/OpenCV_SVN/include/opencv/cv.h"
    "D:/Projects/ImPro/OtherLib/OpenCV2.1/OpenCV_SVN/include/opencv/cv.hpp"
    "D:/Projects/ImPro/OtherLib/OpenCV2.1/OpenCV_SVN/include/opencv/cvaux.h"
    "D:/Projects/ImPro/OtherLib/OpenCV2.1/OpenCV_SVN/include/opencv/cvaux.hpp"
    "D:/Projects/ImPro/OtherLib/OpenCV2.1/OpenCV_SVN/include/opencv/cvwimage.h"
    "D:/Projects/ImPro/OtherLib/OpenCV2.1/OpenCV_SVN/include/opencv/cxcore.h"
    "D:/Projects/ImPro/OtherLib/OpenCV2.1/OpenCV_SVN/include/opencv/cxcore.hpp"
    "D:/Projects/ImPro/OtherLib/OpenCV2.1/OpenCV_SVN/include/opencv/cxeigen.hpp"
    "D:/Projects/ImPro/OtherLib/OpenCV2.1/OpenCV_SVN/include/opencv/cxmisc.h"
    "D:/Projects/ImPro/OtherLib/OpenCV2.1/OpenCV_SVN/include/opencv/highgui.h"
    "D:/Projects/ImPro/OtherLib/OpenCV2.1/OpenCV_SVN/include/opencv/ml.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "main")

