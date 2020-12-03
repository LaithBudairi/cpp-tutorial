#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <algorithm>
#include "add/test.h"
#include "mainalternatives/headers/mymain.h"
#include "mainalternatives/headers/variables.h"
#include "mainalternatives/headers/arrays.h"
#include "mainalternatives/headers/pointers.h"
#include "mainalternatives/headers/functions.h"
#include "mainalternatives/headers/oop.h"
#include "mainalternatives/headers/memory.h"
#include "mainalternatives/headers/filestream.h"
#include "mainalternatives/headers/trycatch.h"
#include "mainalternatives/headers/templates.h"
#include "mainalternatives/headers/stl/vectors.h"
#include "mainalternatives/headers/namespaces.h"
#include "mainalternatives/headers/preprocessor.h"

void* operator new(size_t size) {

    std::cout << "Allocation size: " << size << '\n';
    return malloc(size);
}

union foo {
    int x;
    short y;
};

int main() {
    //myMain();

    // variables practice
    //variables();

    // arrays practice
    //arrays();

    // pointers practice
    //pointers();

    // functions practice
    //functions();

    // oop practice
    //oop();
    std::cout << '\n';

    // memory management
    //memoryManagement();

    // file streams
    //fileStreams();

    // exception handling
    //exceptions();

    // templates
    //templates();

    // vectors
    //vectors();

    // namespaces
    //namespaces();

    // preprocessors
    preprocessor();

}