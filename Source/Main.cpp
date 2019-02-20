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

int main()
{
    //test setup
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
    const unsigned int arrLength = 10000;
    int randomArray[arrLength];
    for(unsigned long long i = 0; i < arrLength; i++)
        randomArray[i] = engine();

    //creating vector with words from file.
    std::vector<std::string> wordVector;
    std::ifstream wordFile;
    wordFile.open("../Data/Lab4_TestFile"); //../Data
    std::string word;
    while(wordFile.good())
    {
        getline(wordFile, word);
        wordVector.push_back(word);
    }

    //test vector int
    std::cout << "--------------------------------Integer vector test begins.--------------------------------" << std::endl;
    
    std::chrono::duration<unsigned int, std::nano> total;
    std::chrono::time_point<std::chrono::steady_clock> start;
    std::chrono::time_point<std::chrono::steady_clock> end;

    //pushback
    for(unsigned long long i = 0; i < arrLength; i++)
    {
        start = std::chrono::steady_clock::now();
        intVector.PushBack(randomArray[i]);
        end = std::chrono::steady_clock::now();
        total += (end - start); 
    }
    //std::cout << "Your vector PushBack() test time:                                        " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    //total = end - end; //reset //gemensam tid

    //pushfront
    for (unsigned long long i = arrLength/2; i < arrLength; i++)
    {
        start = std::chrono::steady_clock::now();
        intVector.PushFront(randomArray[i]);
        end = std::chrono::steady_clock::now();
        total += (end - start);
    }

    std::cout << "Your vector PushBack() and PushFront() test time:                        " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;
    
    for(unsigned long long i = 0; i < arrLength/2; i++)
    {
        start = std::chrono::steady_clock::now();
        intStandardVector.push_back(randomArray[i]);
        end = std::chrono::steady_clock::now();
        total += (end - start);
    }
    //std::cout << "Standard vector PushBack() test time:                                    " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    //total = end - end;

    for(unsigned long long i = arrLength/2; i < arrLength; i++)
    {
        start = std::chrono::steady_clock::now();
        intStandardVector.insert(intStandardVector.begin(), randomArray[i]);
        end = std::chrono::steady_clock::now();
        total += (end - start);
    }
    std::cout << "Standard vector PushBack() and PushFront() test time:                    " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

    //adding every element into one element
    unsigned long long sumElements = 0;
    start = std::chrono::steady_clock::now(); //hela operationens exekveringstid mäts
    for(unsigned long long i = 0; i < arrLength; i++)
    {
        sumElements += intVector[i];
    }
    end = std::chrono::steady_clock::now();
    total = (end - start);
    std::cout << "Your vector adding every element into one element test time:             " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

    sumElements = 0;
    start = std::chrono::steady_clock::now();
    for(unsigned long long i = 0; i < arrLength; i++)
    {
        sumElements += intStandardVector[i];
    }
    end = std::chrono::steady_clock::now();
    total = (end - start);
    std::cout << "Standard vector adding every element into one element test time:         " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

    //adding every 100 element into one element
    sumElements = 0;
    start = std::chrono::steady_clock::now();
    for(unsigned long long i = 0; i < arrLength; i = i+100)
    {
        sumElements += intVector[i];
    }
    end = std::chrono::steady_clock::now();
    total = (end - start);
    std::cout << "Your vector adding every hundred element into one element test time:     " << std::chrono::duration_cast<std::chrono::nanoseconds>(total).count() << " nanoseconds." << std::endl;
    total = end - end;

    sumElements = 0;
    start = std::chrono::steady_clock::now();
    for(unsigned long long i = 0; i < arrLength; i = i+100)
    {
        sumElements += intStandardVector[i];
    }
    end = std::chrono::steady_clock::now();
    total = (end - start);
    std::cout << "Standard vector adding every hundred element into one element test time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(total).count() << " nanoseconds." << std::endl;
    total = end - end;

    //testing if elements are in the same order
    sameElements = true;

    for(unsigned long long i = 0; i < arrLength; i++){
        if(intVector[i] != intStandardVector[i])
            sameElements = false;
    }

    if (sameElements)
        boolOutput = "True";
    else
        boolOutput = "False";

    std::cout << "Same elements(True/False):                                               " << boolOutput << std::endl;
    std::cout << "----------------------------------Integer vector test done.--------------------------------" << std::endl;
    std::cout << std::endl;

    //test list int
    std::cout << "----------------------------------Integer list test begins.--------------------------------" << std::endl;

    for(unsigned int i = 0; i < arrLength/2; i++)
    {
        start = std::chrono::steady_clock::now();
        intList.PushBack(randomArray[i]);
        end = std::chrono::steady_clock::now();
        total += (end - start);
    }
    //std::cout << "Your list PushBack() test time:                                          " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    //total = end - end;

    for(unsigned int i = arrLength/2; i < arrLength; i++)
    {
        start = std::chrono::steady_clock::now();
        intList.PushFront(randomArray[i]);
        end = std::chrono::steady_clock::now();
        total += (end - start);
    }
    std::cout << "Your list PushBack() and PushFront() test time:                          " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

    for(unsigned int i = 0; i < arrLength/2; i++)
    {
        start = std::chrono::steady_clock::now();
        intStandardList.push_back(randomArray[i]);
        end = std::chrono::steady_clock::now();
        total += (end - start);
    }
    //std::cout << "Standard list PushBack() test time:                                      " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    //total = end - end;

    for(unsigned int i = arrLength/2; i < arrLength; i++)
    {
        start = std::chrono::steady_clock::now();
        intStandardList.push_front(randomArray[i]);
        end = std::chrono::steady_clock::now();
        total += (end - start);
    }
    std::cout << "Standard list PushBack() and PushFront() test time:                      " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

    //summing elements into one element
    sumElements = 0;
    start = std::chrono::steady_clock::now();
    for(unsigned int i = 0; i < arrLength; i++)
    {
        sumElements += intList[i];
    }
    end = std::chrono::steady_clock::now();
    total = end - start;
    std::cout << "Your list adding every element into one element test time:               " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

    sumElements = 0;
    start = std::chrono::steady_clock::now(); //taking time of the whole for-loop because std::list has no index operator
    for(auto i: intStandardList)
        sumElements += i;
    end = std::chrono::steady_clock::now();
    total = end - start;
    std::cout << "Standard list adding every element into one element test time:           " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

    //every hundred
    sumElements = 0;
    start = std::chrono::steady_clock::now();
    for(unsigned int i = 0; i < arrLength; i = i+100)
    {
        sumElements += intList[i];
    }
    end = std::chrono::steady_clock::now();
    total = end - start;
    std::cout << "Your list adding every hundred element into one element test time:       " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

    sumElements = 0;
    unsigned int counter = 0;
    start = std::chrono::steady_clock::now();
    for(auto i: intStandardList){
        if (counter == 100 || counter == 0)
        {
            sumElements += i;
            counter = 0;
        }
        ++counter;
    }
    end = std::chrono::steady_clock::now();
    total = end - start;
    std::cout << "Standard list adding every hundred element into one element test time:   " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

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

    std::cout << "Same elements(true/false):                                               " << boolOutput << std::endl;
    std::cout << "----------------------------------Integer list test done.----------------------------------" << std::endl;
    std::cout << std::endl;

    //test vector string
    std::cout << "--------------------------------String vector test begins.---------------------------------" << std::endl;

    for(unsigned long long i = 0; i < wordVector.size()/2; i++)
    {
        start = std::chrono::steady_clock::now();
        stringVector.PushBack(wordVector[i]); //pushback
        end = std::chrono::steady_clock::now();
        total += end - start;
    }
    //std::cout << "Your vector PushBack() test time:                                        " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    //total = end - end;

    for(unsigned long long i = wordVector.size()/2; i < wordVector.size(); i++)
    {
    start = std::chrono::steady_clock::now();
    stringVector.PushFront(wordVector[i]); //pushfront for next element
    end = std::chrono::steady_clock::now();
    total += end - start;
    }
    std::cout << "Your vector PushBack() and PushFront() test time:                        " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

    for(unsigned long long i = 0; i < wordVector.size()/2; i++)
    {
        start = std::chrono::steady_clock::now();
        stringStandardVector.push_back(wordVector[i]);
        end = std::chrono::steady_clock::now();
        total += end - start;
        
    }
    //std::cout << "Standard vector PushBack() test time:                                    " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    //total = end - end;

    for(unsigned long long i = wordVector.size()/2; i < wordVector.size(); i++)
    {
        start = std::chrono::steady_clock::now();
        stringStandardVector.insert(stringStandardVector.begin(), wordVector[i]);
        end = std::chrono::steady_clock::now();
        total += end - start;
    }
    std::cout << "Standard vector PushBack() and PushFront() test time:                    " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

    //adding elements
    std::string sumStringElements = "";
    start = std::chrono::steady_clock::now();
    for(unsigned int i = 0; i < stringVector.Size(); i++)
    {
        sumStringElements += stringVector[i];
    }
    end = std::chrono::steady_clock::now();
    total = end - start;
    std::cout << "Your vector adding every element into one element test time:             " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

    sumStringElements = "";
    start = std::chrono::steady_clock::now();
    for(unsigned int i = 0; i < stringStandardVector.size(); i++)
    {
        sumStringElements += stringStandardVector[i]; 
    }
    end = std::chrono::steady_clock::now();
    total = end - start;
    std::cout << "Standard vector adding every element into one element test time:         " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

    //every hundred
    sumStringElements = "";
    start = std::chrono::steady_clock::now();
    for(unsigned int i = 0; i < stringVector.Size(); i = i+100)
    {
        sumStringElements += stringVector[i]; 
    }
    end = std::chrono::steady_clock::now();
    total = end - start;
    std::cout << "Your vector adding every hundred element into one element test time:     " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

    sumStringElements = "";
    start = std::chrono::steady_clock::now();
    for(unsigned int i = 0; i < stringStandardVector.size(); i = i+100)
    {
        sumStringElements += stringStandardVector[i];
    }
    end = std::chrono::steady_clock::now();
    total = end - start;
    std::cout << "Standard vector adding every hundred element into one element test time: " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

    //testing if elements are in the same order
    sameElements = true;

    for(unsigned long long i = 0; i < wordVector.size(); i++){
        if(stringVector[i] != stringStandardVector[i])
            sameElements = false;
    }

    if (sameElements == true)
        boolOutput = "True";
    else
        boolOutput = "False";

    std::cout << "Same elements(true/false):                                               " << boolOutput << std::endl;
    std::cout << "---------------------------------String vector test done.----------------------------------" << std::endl;
    
    std::cout << std::endl;
    //test list string
    std::cout << "---------------------------------String list test begins.----------------------------------" << std::endl;

    for(unsigned long long i = 0; i < wordVector.size()/2; i++)
    {
        start = std::chrono::steady_clock::now();
        stringList.PushBack(wordVector[i]);
        end = std::chrono::steady_clock::now();
        total += end - start;
    }
    //std::cout << "Your list PushBack() test time:                                          " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    //total = end - end;

    for(unsigned long long i = wordVector.size()/2; i < wordVector.size(); i++)
    {
        start = std::chrono::steady_clock::now();
        stringList.PushFront(wordVector[i]);
        end = std::chrono::steady_clock::now();
        total += end - start;
    }
    std::cout << "Your list PushBack() and PushFront() test time:                          " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

    for(unsigned long long i = 0; i < wordVector.size()/2; i++)
    {
        start = std::chrono::steady_clock::now();
        stringStandardList.push_back(wordVector[i]);
        end = std::chrono::steady_clock::now();
        total += end - start;
    }
    //std::cout << "Standard list PushBack() test time:                                      " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    //total = end - end;

    for(unsigned long long i = wordVector.size()/2; i < wordVector.size(); i++)
    {
        start = std::chrono::steady_clock::now();
        stringStandardList.push_front(wordVector[i]);
        end = std::chrono::steady_clock::now();
        total += end - start;
    }
    std::cout << "Standard list PushBack() and PushFront() test time:                      " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

    //adding every elem
    sumStringElements = "";
    start = std::chrono::steady_clock::now();
    for(unsigned int i = 0; i < stringList.Size(); i++)
    {   
        sumStringElements += stringList[i];  
    }
    end = std::chrono::steady_clock::now();
    total = end - start;
    std::cout << "Your list adding every element into one element test time:               " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

    sumStringElements = "";
    start = std::chrono::steady_clock::now();
    for(auto i: stringStandardList)
        sumStringElements += i;
    end = std::chrono::steady_clock::now();
    total = end - start;
    std::cout << "Standard list adding every element into one element test time:           " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

    //every hundred
    sumStringElements = "";
    start = std::chrono::steady_clock::now();
    for(unsigned int i = 0; i < stringList.Size(); i = i+100)
    {
        sumStringElements += stringList[i];
    }
    end = std::chrono::steady_clock::now();
    total = end - start;
    std::cout << "Your list adding every hundred element into one element test time:       " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

    sumStringElements = "";
    counter = 0;
    start = std::chrono::steady_clock::now();
    for(auto i: stringStandardList){
        if (counter == 100 || counter == 0)
        {
            sumStringElements += i;
            counter = 0;
        }
        ++counter;
    }
    end = std::chrono::steady_clock::now();
    total = end - start;
    std::cout << "Standard list adding every hundred element into one element test time:   " << std::chrono::duration_cast<std::chrono::microseconds>(total).count() << " microseconds." << std::endl;
    total = end - end;

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

    std::cout << "Same elements(true/false):                                               " << boolOutput << std::endl;
    std::cout << "---------------------String list test done. Press enter to continue.-----------------------" << std::endl;

    std::cin.get();
    return 0;
}