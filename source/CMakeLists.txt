cmake_minimum_required(VERSION 3.20)

# Enable modern policies when available
if(POLICY CMP0069) # Enable LTO
    cmake_policy(SET CMP0069 NEW)
endif()

if(POLICY CMP0079) # Allow target-based linking between subprojects
    cmake_policy(SET CMP0079 NEW)
endif()

project(SCrystalStoneRPG LANGUAGES C CXX)

# Compiler configuration
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE OFF)

# Enable Link-Time Optimization if supported
include(CheckIPOSupported)
check_ipo_supported(RESULT IPO_SUPPORTED OUTPUT IPO_OUTPUT)
if(IPO_SUPPORTED)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION ON)
else()
    message(WARNING "IPO (LTO) not supported: ${IPO_OUTPUT}")
endif()

# Compiler warnings and flags
if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# Header files
set(HEADERS
    "SCSRPG_Constants.h"
    "SCSRPG_Game.h"
    "SCSRPG_Scenes.h"
    "SCSRPG_Terminal.h"
    "SCSRPG_Texts.h"
)

# Source files
set(SOURCES
    "main.cpp"
    "SCSRPG_Constants.cpp"
    "SCSRPG_Game.cpp"
    "SCSRPG_Scenes.cpp"
    "SCSRPG_Terminal.cpp"
    "SCSRPG_Texts.cpp"
)

# Executable target
add_executable(SCrystalStoneRPG ${HEADERS} ${SOURCES})
