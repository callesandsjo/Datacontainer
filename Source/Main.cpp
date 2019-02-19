#include "DataContainer.h"
#include "Vector.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <list>
#include <random>
#include <fstream>

using namespace std::chrono;

typedef time_point<steady_clock, duration<unsigned int, std::nano>> SteadyClockTimePoint;


int main()
{   


    Vector<int> intVector;
    std::vector<int> intStandardVector;

    LinkedList<int> intList;
    std::list<int> intStandardList;

    Vector<std::string> stringVector;
    std::vector<std::string> stringStandardVector;

    LinkedList<std::string> stringList;
    std::list<std::string> stringStandardList;

    bool sameElements;
    std::string boolOutput;
    std::default_random_engine engine;
    
    //creating array with 10000 random integers.
    int randomArray[9999];
    for(unsigned long long i = 0; i < 10000; i++)
        randomArray[i] = engine();

    //creating array with words from file.
    std::string wordArray[12197];
    std::ifstream wordFile;
    wordFile.open("../Data/Lab4_TestFile");
    int wordArrIndex = 0;
    std::string word;
    while(wordFile.good())
    {
        getline(wordFile, wordArray[wordArrIndex], '\n');
        //std::cout << wordArray[wordArrIndex] << std::endl;
        ++wordArrIndex;
    }



    //test vector int
    std::cout << "-----------------Integer vector test begins.-----------------" << std::endl;

    SteadyClockTimePoint totalPushbackVec;
    SteadyClockTimePoint totalPushfrontVec;
    SteadyClockTimePoint totalPushbackStdVec;
    SteadyClockTimePoint totalPushfrontStdVec;
    SteadyClockTimePoint start;
    SteadyClockTimePoint end;
    
    for(unsigned long long i = 0; i < 10000; i = i + 2)
    {
        start = steady_clock::now();
        intVector.PushBack(randomArray[i]);
        end = steady_clock::now();
        totalPushbackVec += (end - start);
        start = steady_clock::now();
        intVector.PushFront(randomArray[i+1]);
        end = steady_clock::now();
        totalPushfrontVec += (end - start);
    }

    
    for(unsigned long long i = 0; i < 10000; i = i + 2)
    {
        start = steady_clock::now();
        intStandardVector.push_back(randomArray[i]);
        end = steady_clock::now();
        totalPushbackStdVec += (end - start);
        start = steady_clock::now();
        intStandardVector.insert(intStandardVector.begin(), randomArray[i+1]);
        end = steady_clock::now();
        totalPushfrontStdVec += (end - start);
    }

    //adding every element into one element
    unsigned long long sumElements;
    for(unsigned long long i = 0; i < 10000; i++)
        sumElements += intVector[i];
    intVector.PushBack(sumElements);

    //std::cout << sumElements << std::endl;

    sumElements = 0;
    for(unsigned long long i = 0; i < 10000; i++)
        sumElements += intStandardVector[i];
    intStandardVector.push_back(sumElements);
    //std::cout << sumElements << std::endl;

    //adding every 100 element into one element
    sumElements = 0;
    for(unsigned long long i = 0; i < 10000; i = i+100)
        sumElements += intVector[i];
    intVector.PushBack(sumElements);

    //std::cout << sumElements << std::endl;

    sumElements = 0;
    for(unsigned long long i = 0; i < 10000; i = i+100)
        sumElements += intStandardVector[i];
    intStandardVector.push_back(sumElements);

    //std::cout << sumElements << std::endl;

    //testing if elements are in the same order
    sameElements = true;

    for(unsigned long long i = 0; i < 10002; i++){
        if(intVector[i] != intStandardVector[i])
            sameElements = false;
    }

    if (sameElements == true)
        boolOutput = "True";
    else
        boolOutput = "False";


    std::cout << "Same elements(true/false): " << boolOutput << std::endl;
    std::cout << "Your vector PushBack() test time: " << duration_cast<microseconds>(totalPushbackVec.time_since_epoch()).count() << " microseconds." << std::endl;
    std::cout << "Your vector PushFront() test time: " << duration_cast<milliseconds>(totalPushfrontVec.time_since_epoch()).count() << " milliseconds." << std::endl;
    std::cout << "Standard vector PushBack() test time: " << duration_cast<microseconds>(totalPushbackStdVec.time_since_epoch()).count() << " microseconds." << std::endl;
    std::cout << "Standard vector PushFront() test time: " << duration_cast<milliseconds>(totalPushfrontStdVec.time_since_epoch()).count() << " milliseconds." << std::endl;
    std::cout << "-----Integer vector test done. Press enter to continue.------" << std::endl;
    std::cin.get();

    //test list int
    std::cout << "-------------------Integer list test begins.-----------------" << std::endl;

    SteadyClockTimePoint totalPushbackList;
    SteadyClockTimePoint totalPushfrontList;
    SteadyClockTimePoint totalPushbackStdList;
    SteadyClockTimePoint totalPushfrontStdList;

    for(unsigned long long i = 0; i < 10000; i = i + 2)
    {
        start = steady_clock::now();
        intList.PushBack(randomArray[i]);
        end = steady_clock::now();
        totalPushbackList += (end - start);
        start = steady_clock::now();
        intList.PushFront(randomArray[i+1]);
        end = steady_clock::now();
        totalPushfrontList += (end - start);
    }

    for(unsigned long long i = 0; i < 10000; i = i + 2)
    {
        start = steady_clock::now();
        intStandardList.push_back(randomArray[i]);
        end = steady_clock::now();
        totalPushbackStdList += (end - start);
        start = steady_clock::now();
        intStandardList.push_front(randomArray[i+1]);
        end = steady_clock::now();
        totalPushfrontStdList += (end - start);
    }

    //testing if elements are in the same order
    sameElements = true;

    int index = 0;
    for(auto elem: intStandardList)
    {
        if (elem != intList[index])
            sameElements = false;
        ++index;
    }

    if (sameElements == true)
        boolOutput = "True";
    else
        boolOutput = "False";

    std::cout << "Same elements(true/false): " << boolOutput << std::endl;
    std::cout << "Your list PushBack() test time: " << duration_cast<microseconds>(totalPushbackList.time_since_epoch()).count() << " microseconds." << std::endl;
    std::cout << "Your list PushFront() test time: " << duration_cast<microseconds>(totalPushfrontList.time_since_epoch()).count() << " microseconds." << std::endl;
    std::cout << "Standard list PushBack() test time: " << duration_cast<microseconds>(totalPushbackStdList.time_since_epoch()).count() << " microseconds." << std::endl;
    std::cout << "Standard list PushFront() test time: " << duration_cast<microseconds>(totalPushfrontStdList.time_since_epoch()).count() << " microseconds." << std::endl;
    std::cout << "-------Integer list test done. Press enter to continue.------" << std::endl;
    std::cin.get();

    //test vector string
    std::cout << "-----------------String vector test begins.------------------" << std::endl;

    SteadyClockTimePoint totalStringPushbackVec;
    SteadyClockTimePoint totalStringPushfrontVec;
    SteadyClockTimePoint totalStringPushbackStdVec;
    SteadyClockTimePoint totalStringPushfrontStdVec;

    for(unsigned long long i = 0; i < 12196; i = i + 2)
    {
        start = steady_clock::now();
        stringVector.PushBack(wordArray[i]);
        end = steady_clock::now();
        totalStringPushbackVec += (end - start);
        start = steady_clock::now();
        stringVector.PushFront(wordArray[i+1]);
        end = steady_clock::now();
        totalStringPushfrontVec += (end - start);
    }

    for(unsigned long long i = 0; i < 12196; i = i + 2)
    {
        start = steady_clock::now();
        stringStandardVector.push_back(wordArray[i]);
        end = steady_clock::now();
        totalStringPushbackStdVec += (end - start);
        start = steady_clock::now();
        stringStandardVector.insert(stringStandardVector.begin(), wordArray[i+1]);
        end = steady_clock::now();
        totalStringPushfrontStdVec += (end - start);
    }

    //testing if elements are in the same order
    sameElements = true;

    for(unsigned long long i = 0; i < 12196; i++){
        if(stringVector[i] != stringStandardVector[i])
            sameElements = false;
    }

    if (sameElements == true)
        boolOutput = "True";
    else
        boolOutput = "False";

    std::cout << "Same elements(true/false): " << boolOutput << std::endl;
    std::cout << "Your vector PushBack() test time: " << duration_cast<microseconds>(totalStringPushbackVec.time_since_epoch()).count() << " microseconds." << std::endl;
    std::cout << "Your vector PushFront() test time: " << duration_cast<milliseconds>(totalStringPushfrontVec.time_since_epoch()).count() << " milliseconds." << std::endl;
    std::cout << "Standard vector PushBack() test time: " << duration_cast<microseconds>(totalStringPushbackStdVec.time_since_epoch()).count() << " microseconds." << std::endl;
    std::cout << "Standard vector PushFront() test time: " << duration_cast<milliseconds>(totalStringPushfrontStdVec.time_since_epoch()).count() << " milliseconds." << std::endl;
    std::cout << "-----String vector test done. Press enter to continue.-------" << std::endl;
    std::cin.get();

    //test list string
    std::cout << "------------------String list test begins.-------------------" << std::endl;

    SteadyClockTimePoint totalStringPushbackList;
    SteadyClockTimePoint totalStringPushfrontList;
    SteadyClockTimePoint totalStringPushbackStdList;
    SteadyClockTimePoint totalStringPushfrontStdList;

    for(unsigned long long i = 0; i < 12196; i = i + 2)
    {
        start = steady_clock::now();
        stringList.PushBack(wordArray[i]);
        end = steady_clock::now();
        totalStringPushbackList += (end - start);
        start = steady_clock::now();
        stringList.PushFront(wordArray[i+1]);
        end = steady_clock::now();
        totalStringPushfrontList += (end - start);
        
    }

    for(unsigned long long i = 0; i < 12196; i = i + 2)
    {
        start = steady_clock::now();
        stringStandardList.push_back(wordArray[i]);
        end = steady_clock::now();
        totalStringPushbackStdList += (end - start);
        start = steady_clock::now();
        stringStandardList.push_front(wordArray[i+1]);
        end = steady_clock::now();
        totalStringPushfrontStdList += (end - start);
    }

    //testing if elements are in the same order
    sameElements = true;

    index = 0;
    for(auto elem: stringStandardList)
    {
        if (elem != stringList[index])
            sameElements = false;
        ++index;
    }

    if (sameElements == true)
        boolOutput = "True";
    else
        boolOutput = "False";

    std::cout << "Same elements(true/false): " << boolOutput << std::endl;
    std::cout << "Your list PushBack() test time: " << duration_cast<microseconds>(totalStringPushbackList.time_since_epoch()).count() << " microseconds." << std::endl;
    std::cout << "Your list PushFront() test time: " << duration_cast<microseconds>(totalStringPushfrontList.time_since_epoch()).count() << " microseconds." << std::endl;
    std::cout << "Standard list PushBack() test time: " << duration_cast<microseconds>(totalStringPushbackStdList.time_since_epoch()).count() << " microseconds." << std::endl;
    std::cout << "Standard list PushFront() test time: " << duration_cast<microseconds>(totalStringPushfrontStdList.time_since_epoch()).count() << " microseconds." << std::endl;
    std::cout << "------String list test done. Press enter to continue.--------" << std::endl;
    std::cin.get();

    return 0;
}