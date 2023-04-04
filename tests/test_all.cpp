#include "test.hpp"
#include "test_map.hpp"
#include "test_vector.hpp"

using namespace ft;

void test_all()
{
    	std::cout<<"Vector test is starting..."<<std::endl;
//iterators
	testBegin();
	
	testPushBack();
 	testEnd();
	testRbegin();
	testRend();

//capacity
	testSize();
	testMaxSize();
	testResize(); 
	testEmpty();
 	testReserve();

//element access
	testBoxBrackets();
	testAt();
	testFront();
	testBack();

//Modifiers:
	testAssign();
 	testPushBack();
	testPopBack();
	testInsert();
	testErase();
	testSwap();
	testClear();
	testGetAllocator(); 
	

	std::cout<<"Vector test finished"<<std::endl;
        std::cout << "Map test is starting..." << std::endl;
    mapBegin();
    mapEnd();
    mapRBegin();
    mapREnd();
    mapEmpty();
    mapSize();
    mapMaxSize();

    mapBoxBrackets();
    mapInsert();
    mapErase();
    mapSwap();
    mapClear();

    mapKeyComp();
    mapValueComp();

    mapFind();
    mapCount();
    mapLowerBound();
    mapUpperBound();
    mapEqualRange();

    std::cout << "Map test finished" << std::endl;
}