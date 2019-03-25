cmake_minimum_required(VERSION 3.9.0)
project (library)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES
	include/BookStand.h
	include/Chest.h
	include/ChillRoom.h
	include/Chimney.h
	include/ChocoBar.h
	include/Cola.h
	include/Corridor.h
	include/Enemy.h
	include/Hero
	include/Inventory.h
	include/Items.h
	include/ItemsVisitor.h
	include/Key.h
	include/Knife.h
	include/MysteryRoom.h
	include/PushItemVisitor.h
	include/Rifle.h
	include/Rooms.h
	include/Talisman.h
	include/Torch.h
	include/Zgredek.h
	include/Fight.h
	include/GameBody.h
	include/Map.h
	src/BookStand.cpp
	src/Chest.cpp
	src/Chimney.cpp
	src/ChocoBar.cpp
	src/Cola.cpp
	src/Corridor.cpp
	src/Enemy.cpp
	src/Hero.cpp
	src/Inventory.cpp
	src/Key.cpp
	src/Knife.cpp
	src/MysteryRoom.cpp
	src/PushItemVisitor.cpp
	src/Rifle.cpp
	src/Talisman.cpp
	src/Torch.cpp
	src/Zgredek.cpp
	src/Rooms.cpp
	src/Fight.cpp
	src/GameBody.cpp
	src/Map.cpp
		src/Draw.cpp include/Draw.h)

add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_THESTRANGEHOUSE
	test/master.cpp
	test/BookStandTest.cpp
	test/ChestTest.cpp
	test/ChimneyTest.cpp
	test/ChocoBarTest.cpp
	test/ColaTest.cpp
	test/CorridorTest.cpp
	test/EnemyTest.cpp
	test/HeroTest.cpp
	test/InventoryTest.cpp
	test/KeyTest.cpp
	test/KnifeTest.cpp
	test/MysteryRoomTest.cpp
	test/PushItemVisitorTest.cpp
	test/RifleTest.cpp
	test/TalismanTest.cpp
	test/TorchTest.cpp
	test/ZgredekTest.cpp
	test/FightTest.cpp
	test/GameBodyTest.cpp
		test/MapTest.cpp src/Draw.cpp include/Draw.h)

add_executable (BookStandTest ${SOURCE_TEST_THESTRANGEHOUSE})
add_executable (ChestTest ${SOURCE_TEST_THESTRANGEHOUSE})
add_executable (ChimneyTest ${SOURCE_TEST_THESTRANGEHOUSE})
add_executable (ChocoBarTest ${SOURCE_TEST_THESTRANGEHOUSE})
add_executable (ColaTest ${SOURCE_TEST_THESTRANGEHOUSE})
add_executable (CorridorTest ${SOURCE_TEST_THESTRANGEHOUSE})
add_executable (EnemyTest ${SOURCE_TEST_THESTRANGEHOUSE})
add_executable (GoWithoutKeyTest ${SOURCE_TEST_THESTRANGEHOUSE})
add_executable (HeroTest ${SOURCE_TEST_THESTRANGEHOUSE})
add_executable (InventoryTest ${SOURCE_TEST_THESTRANGEHOUSE})
add_executable (KeyTest ${SOURCE_TEST_THESTRANGEHOUSE})
add_executable (KnifeTest ${SOURCE_TEST_THESTRANGEHOUSE})
add_executable (MysteryRoomTest ${SOURCE_TEST_THESTRANGEHOUSE})
add_executable (PushItemVisitorTest ${SOURCE_TEST_THESTRANGEHOUSE})
add_executable (RifleTest ${SOURCE_TEST_THESTRANGEHOUSE})
add_executable (TalismanTest ${SOURCE_TEST_THESTRANGEHOUSE})
add_executable (TorchTest ${SOURCE_TEST_THESTRANGEHOUSE})
add_executable (UseKeyAndGoInsideTest ${SOURCE_TEST_THESTRANGEHOUSE})
add_executable (ZgredekTest ${SOURCE_TEST_THESTRANGEHOUSE})


target_link_libraries (BookStandTest
	Library
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
enable_testing()
add_test(TestBiblioteki BookStandTest
	--report_level=detailed
	--log_level=all
	--color_output=yes
)

target_link_libraries (ChestTest
	Library
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
enable_testing()
add_test(TestBiblioteki ChestTest
	--report_level=detailed
	--log_level=all
	--color_output=yes
)

target_link_libraries (ChimneyTest
	Library
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
enable_testing()
add_test(TestBiblioteki ChimneyTest
	--report_level=detailed
	--log_level=all
	--color_output=yes
)

target_link_libraries (ChocoBarTest
	Library
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
enable_testing()
add_test(TestBiblioteki ChocoBarTest
	--report_level=detailed
	--log_level=all
	--color_output=yes
)

target_link_libraries (ColaTest
	Library
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
enable_testing()
add_test(TestBiblioteki ColaTest
	--report_level=detailed
	--log_level=all
	--color_output=yes
)

target_link_libraries (CorridorTest
	Library
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
enable_testing()
add_test(TestBiblioteki CorridorTest
	--report_level=detailed
	--log_level=all
	--color_output=yes
)

target_link_libraries (EnemyTest
	Library
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
enable_testing()
add_test(TestBiblioteki EnemyTest
	--report_level=detailed
	--log_level=all
	--color_output=yes
)

target_link_libraries (GoWithoutKeyTest
	Library
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
enable_testing()
add_test(TestBiblioteki GoWithoutKeyTest
	--report_level=detailed
	--log_level=all
	--color_output=yes
)

target_link_libraries (HeroTest
	Library
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
enable_testing()
add_test(TestBiblioteki HeroTest
	--report_level=detailed
	--log_level=all
	--color_output=yes
)

target_link_libraries (InventoryTest
	Library
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
enable_testing()
add_test(TestBiblioteki InventoryTest
	--report_level=detailed
	--log_level=all
	--color_output=yes
)

target_link_libraries (KeyTest
	Library
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
enable_testing()
add_test(TestBiblioteki KeyTest
	--report_level=detailed
	--log_level=all
	--color_output=yes
)

target_link_libraries (KnifeTest
	Library
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
enable_testing()
add_test(TestBiblioteki KnifeTest
	--report_level=detailed
	--log_level=all
	--color_output=yes
)

target_link_libraries (MysteryRoomTest
	Library
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
enable_testing()
add_test(TestBiblioteki MysteryRoomTest
	--report_level=detailed
	--log_level=all
	--color_output=yes
)

target_link_libraries (PushItemVisitorTest
	Library
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
enable_testing()
add_test(TestBiblioteki PushItemVisitorTest
	--report_level=detailed
	--log_level=all
	--color_output=yes
)

target_link_libraries (RifleTest
	Library
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
enable_testing()
add_test(TestBiblioteki RifleTest
	--report_level=detailed
	--log_level=all
	--color_output=yes
)

target_link_libraries (TalismanTest
	Library
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
enable_testing()
add_test(TestBiblioteki TalismanTest
	--report_level=detailed
	--log_level=all
	--color_output=yes
)

target_link_libraries (TorchTest
	Library
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
enable_testing()
add_test(TestBiblioteki TorchTest
	--report_level=detailed
	--log_level=all
	--color_output=yes
)

target_link_libraries (UseKeyAndGoInsideTest
	Library
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
enable_testing()
add_test(TestBiblioteki UseKeyAndGoInsideTest
	--report_level=detailed
	--log_level=all
	--color_output=yes
)

target_link_libraries (ZgredekTest
	Library
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
enable_testing()
add_test(TestBiblioteki ZgredekTest
	--report_level=detailed
	--log_level=all
	--color_output=yes
)

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
