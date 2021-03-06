/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "main.h"

void p12() {
    cout << "The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:\n"
            "1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...\n"
            "Let us list the factors of the first seven triangle numbers:\n"
            " 1: 1\n"
            " 3: 1,3\n"
            " 6: 1,2,3,6\n"
            "10: 1,2,5,10\n"
            "15: 1,3,5,15\n"
            "21: 1,3,7,21\n"
            "28: 1,2,4,7,14,28\n"
            "We can see that 28 is the first triangle number to have over five divisors.\n"
            "What is the value of the first triangle number to have over five hundred divisors?\n\n";

    //1. define variables
    vector<unsigned long long int> tri;
    tri.push_back(0);
    vector<unsigned long long int> div;
    unsigned long long int num, temp;

    //2. use a for loop to create a sequence of triangle numbers
    for (int x = 1; x != 0; x++) {
        tri.push_back(x + tri[x - 1]);
        div.push_back(1);
        div.push_back(tri[x]);
        temp = tri[x];

        //3. find the divisors of each triangle number
        for(int y = 2; y < temp; y++){
            if(tri[x] % y == 0){
                div.push_back(y);

                //4. if y is not a square root of the triangle number, then also push back the other factor of y
                //   Also change temp to the other factor of y to skip repeats of factors
                if(tri[x]/y != y){
                    div.push_back(tri[x]/y);
                    temp = tri[x]/y;
                }
            }
        }
        //5. once the divisor size reaches 500, end the for loop, we found the number
        if(div.size() >= 500){
            num = tri[x];
            break;
        }
        //6. clear divisor vector
        div.clear();
    }
    
    //7. print out num and clear vector
    cout << "The first triangle number with 500 divisors is: " << num << endl;
    tri.clear();
    return;
}