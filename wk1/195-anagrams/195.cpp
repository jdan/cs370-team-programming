/*
* Jack Farzan
* problem 195 in cpp
*/

#include <string>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include "stdlib.h"
#include <list>

//make-a the anagrams
std::list<std::string> anagram2(std::string s1, std::string s2, std::list<std::string> strings)
{
    std::string news1, news2;
    int i;

    std::cout << strings.size() << std::endl;
    if(s1.length() == 0)
    {
    	strings.push_back(s2);
    	//std::cout << s2 << std::endl;
    }

   	for(i = 0; i < s1.length(); i++)
   	{
   		news1 = s1.substr(0, i) + s1.substr(i+1, s1.length());
   		news2 = s1[i] + s2;
   		anagram2(news1, news2, strings);
   	}
   	
   	for(std::string c : strings)
   		std::cout << c << std::endl;

    return strings;
}

//anagram wrapper
void anagram(std::string s)   
{
    std::list<std::string> strings; 
    std::list<std::string> grams = anagram2(s, "", strings);
    //grams.sort(); //sort the anagrams
    //grams.unique(); //remove duplicates
    for(std::string c : grams)
        std::cout << c << std::endl;
}

//ok so this thing works why doesnt the other thing

/*void anagram3(std::string s1, std::string s2)
{
    std::string news1, news2;
    int i;
    if(s1.length() == 0)
    	std::cout << s2 << std::endl;

   	for(i = 0; i < s1.length(); i++)
   	{
   		news1 = s1.substr(0, i) + s1.substr(i+1, s1.length());
   		news2 = s1[i] + s2;
   		anagram3(news1, news2);
   	}
}*/


int main()
{
    int size, i, j;
    std::list<std::string> potato, empty, full;
    /*std::string arr[] = {"pop", "Pufh", "kadhae", "pop"};
    for(i = 0; i < 4; i++)
    	potato.push_back(arr[i]);
    potato.sort();
    potato.unique();
    for(std::string c : potato)
    	std::cout << c << std::endl;*/

    std::string orange = "abc";
    //anagram3("orange", "");
	full = anagram2(orange, "", empty);

	//anagram("abc");
	for(std::string c : full)
		std::cout<< c << std::endl;
	
    /*while (scanf("%d %s", &n) > 2)
    {

		for(i=m+1;i<=n;i++) 
		{
		    temp = cycle(i);
		    if (temp > max)
			max = temp;
		}
		printf("%d %d %d\n",);
    }*/
    return(0);
}