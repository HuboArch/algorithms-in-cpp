cmake_minimum_required(VERSION 3.10)
project(algorithms-in-cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        # algorithm
        algorithm/sort/sort-test-util/SortTestUtil.h

        #data structure
        data-structure/list/singly-linked-list/Node.cpp
        data-structure/list/singly-linked-list/header/Node.h
        data-structure/list/singly-linked-list/SinglyLinkedList.cpp
        data-structure/list/singly-linked-list/header/SinglyLinkedList.h
        data-structure/queue/CircularQueue.cpp data-structure/queue/header/CircularQueue.h
        )

add_executable(algorithms-in-cpp ${SOURCE_FILES})