/************************************************************************
 * Author:          sugarfreeoh
 * Date:            6 March 2016
 * Description:     Each line includes a test case with a number of
 *                  vampires, zombies, witches, and houses that they
 *                  visited. vampires get 3 candies, zombies get 4,
 *                  and witches get 5 candies. Program determines how
 *                  much candy each child receives.
 ***********************************************************************/

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <math.h>

using namespace std;

struct costumes
{
    int v;
    int z;
    int w;
};

const int VAMPIRE = 3;
const int ZOMBIE = 4;
const int WITCH = 5;

int main(int argc, char *argv[])
{
    ifstream inputFile;

    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        string line;

        while(getline(inputFile,line))
        {
            string temp;
            stringstream lineStream;

            int totalCandy = 0;
            int houses = 0;
            int monsterCount = 0;

            costumes c;

            lineStream << line;

            while(getline(lineStream,temp,','))
            {
                int candy = 0;
                size_t spaceLoc = 0;

                string tempAmount;

                if(temp[0] == ' ')
                    temp = temp.substr(1,temp.size()-1);

                stringstream ss;

                spaceLoc = temp.find(' ');

                tempAmount = temp.substr(spaceLoc+1,temp.size()-spaceLoc);

                ss << tempAmount;

                ss >> candy;

                if(strncmp(temp.c_str(),"V",1) == 0)
                {
                    c.v = candy;
                }
                else if(strncmp(temp.c_str(),"Z",1) == 0)
                {
                    c.z = candy;
                }
                else if(strncmp(temp.c_str(),"W",1) == 0)
                {
                    c.w = candy;
                }
                else if(strncmp(temp.c_str(),"H",1) == 0)
                {
                    houses = candy;
                }

                ss.str("");
                ss.clear();
            }

            totalCandy = (c.v*VAMPIRE*houses) + (c.z*ZOMBIE*houses) + (c.w*WITCH*houses);

            monsterCount = c.v + c.z + c.w;

            //cout << "Total Candy: " << totalCandy << endl;

            cout << floor(totalCandy/monsterCount) << endl;
        }
        
        inputFile.close();
    }
    else
    {
        cout << "Error opening input file" << endl;
    }

    return 0;
}
