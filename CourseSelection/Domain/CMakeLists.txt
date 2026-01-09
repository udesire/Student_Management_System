cmake_minimum_required(VERSION 4.1.1)

#https://github.com/Kitware/CMake/blob/v4.1.1/Help/dev/experimental.rst

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_MODULE_STD ON)

project(domain LANGUAGES CXX)

# set(MODULE_LIB_DIR1 /opt/utils/modules)  # 模块库的目录的设置
add_executable(domain
    #math.cpp                              # 模块实现单元
    main.cpp

)

set(MODULE_INTERFACE_FILES
    #${MODULE_LIB_DIR1}/utils.cppm         #添加模块库的模块接口单元
    #math.cppm                             # 模块接口单元
    Role.cppm
    SecretaryRole.cppm
    StudentRole.cppm
    TeacherRole.cppm
    TeachingTask.cppm
    Course.cppm
)

source_group("Modules" FILES ${MODULE_INTERFACE_FILES})
target_sources(domain  PRIVATE FILE_SET cxx_modules TYPE CXX_MODULES
    BASE_DIRS                              # 配置BASE_DIRS，用于组织构建输出目录，以便构建不同目录中(同名的)模块文件.
        #${MODULE_LIB_DIR1}
        ${CMAKE_CURRENT_SOURCE_DIR}
    FILES ${MODULE_INTERFACE_FILES}
)
target_compile_features(domain PRIVATE cxx_std_23)

# 然后就是创建动态库了
add_library(
    Domain
    SHARED
)

target_sources(Domain
PUBLIC
    FILE_SET CXX_MODULES
    BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
    FILES Course.cppm Role.cppm SecretaryRole.cppm
        StudentRole.cppm TeacherRole.cppm
        TeachingTask.cppm
)

target_include_directories(Domain
PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# 设置目标属性，仅对Linux生效
# todo: 跨平台设置
set_target_properties(
    Domain PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib
    VERSION 1.0.0
    SOVERSION 1
    # window 兼容
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin、
    # macOS 未知 需要完成
)




