cmake_minimum_required(VERSION 3.12)

project(main LANGUAGES CXX)

include(CTest)

set(MAIN_SOURCE src/main.cpp)

file(GLOB_RECURSE PROJECT_COMMON_SOURCES CONFIGURE_DEPENDS
	src/*.cpp
)
list(REMOVE_ITEM PROJECT_COMMON_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/${MAIN_SOURCE}")

add_executable(main ${MAIN_SOURCE} ${PROJECT_COMMON_SOURCES})
target_include_directories(main PRIVATE include)
target_compile_features(main PRIVATE cxx_std_17)

if(BUILD_TESTING)
	file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
		tests/*.cpp
	)

	foreach(test_src IN LISTS TEST_SOURCES)
		file(RELATIVE_PATH rel_test "${CMAKE_SOURCE_DIR}/tests" "${test_src}")
		get_filename_component(test_name_we "${rel_test}" NAME_WE)
		get_filename_component(test_dir "${rel_test}" DIRECTORY)

		if(test_dir STREQUAL "")
			set(test_target "${test_name_we}")
		else()
			string(REPLACE "/" "_" test_dir_flat "${test_dir}")
			set(test_target "${test_dir_flat}_${test_name_we}")
		endif()

		add_executable(${test_target} ${test_src} ${PROJECT_COMMON_SOURCES})
		target_include_directories(${test_target} PRIVATE include)
		target_compile_features(${test_target} PRIVATE cxx_std_17)
		add_test(NAME ${test_target} COMMAND ${test_target})
	endforeach()
endif()
