/*
    Name: Carlos Aldaco Flores, 5008406281, 1006, 5
    Description: Main file for the pokemon assignment
    Input: Pond data file and duration of simulation in weeks
    Output: Weight of fish and plants each week after simultions
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "herbivore.h"
#include "plant.h"
#include "organism.h"
#include "randNum.h"

using namespace std;

// Length of pond
const int ROWS = 5;
// Width of pond
const int COLS = 5;

/*
* function_identifier: Populates pond
* parameters: File stream with pond data and the pond 2d array
* return value: Void
*/
void buildPondSimulator(ifstream&, organism***);

/*
* function_identifier: Simulates a week of activity
* parameters: Pond array and a randNum object
* return value: Void
*/
void simulateAWeek(organism***, randNum&);

/*
* function_identifier: Displays weight of organism
* parameters: A single organism object
* return value: Void
*/
void outputOrganism(organism*);

/*
* function_identifier: Deallocates pond array
* parameters: Pond array
* return value: Void
*/
void clearSimulation(organism***);

int main(int argc, char** argv)
{ 
    // Pond allocation
    organism *** pond = new organism**[ROWS];
    ifstream infile;
    // Store name of pond data file
    string filename;
    randNum rN("RandomNums.txt");
    // Stores simulation duration
    int weeks;

    // Set each position to nullptr (should already be null tho)
    for (int row = 0; row < ROWS; row++)
    {
        pond[row] = new organism*[COLS];
        for (int col = 0; col < COLS; col++)
        {
            pond[row][col] = nullptr;
        }
    }

    // Get file name
    filename = argv[1];
    // Open file
    infile.open(filename);
    cout << "Reading data from " << filename << " file..." << endl;
    // Error message if file fails to open
    if (!infile.is_open()) {
      cout << "Error: File failed to open." << endl;
      return 1;
    }
    // Get duration
    weeks = stoi(argv[2]);
    cout << "Reading amount of weeks '" << weeks << "' for the simulation..." << endl;

    // Build pond
    buildPondSimulator(infile, pond);

    // Runs once for each week of simulation
    for (int week = 0; week < weeks; week++)
    {
      cout << "WEEK " << week+1 << " RESULTS" << endl;

      // Simulate a week 100 times per week?
      for (int i = 0; i < 100; i++)
      {
         simulateAWeek(pond, rN);
      }

      // Iterate through every spot in pond
      for (int row = 0; row < ROWS; row++)
      {
         for (int col = 0; col < COLS; col++)
         {
            // If an organism is here
            if (pond[row][col])
            {
               // Simulate a week
               pond[row][col]->simulateWeek();
               // If it's dead
               if (!pond[row][col]->isAlive())
               {
                  // Deallocate
                  delete pond[row][col];
                  // Assign nullptr
                  pond[row][col] = nullptr;
               }
               // Display weight
               outputOrganism(pond[row][col]);
            }
         }
      }
    }
    cout << "Ending simulation" << endl;

    //destroy the simulation
    clearSimulation(pond);

    return 0;
}

// Definition of buildPondSimulator
void buildPondSimulator(ifstream& file, organism*** pond)
{
    // Store entire line
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        // Declare variables to store organism data
        string type;
        double size;
        double growthRate;
        int x;
        int y;

        // Get type
        getline(ss, type, ',');
        // Get size
        ss >> size;
        // Ignore the coma
        ss.ignore(1);
        // Get rate
        ss >> growthRate;
        // Ignore coma
        ss.ignore(1);
        // Get x coordinate
        ss >> x;
        // Ignore comma
        ss.ignore(1);
        // Get y coordinate
        ss >> y;

        // Create organism instance
        organism* newOrganism = nullptr;

        // Check type
        if (type == "PLANT")
        {
            // Assign new plant to instance
            newOrganism = new plant(size, growthRate);
            // Add to pond
            pond[x][y] = newOrganism;
        }
        else if (type == "FISH")
        {
            // Assign new fish to instance
            newOrganism = new herbivore(size, growthRate, size * 0.1);
            // Add to pond
            pond[x][y] = newOrganism;
        }
    }
}

// Definition of simulateAWeek
void simulateAWeek(organism*** pond, randNum& rN)
{
   // Stores coordinates
   int x1, x2, y1, y2;
   // Get all coordinates
   x1 = rN.getNextRand() % ROWS;
   y1 = rN.getNextRand() % COLS;
   x2 = rN.getNextRand() % ROWS;
   y2 = rN.getNextRand() % COLS;

   // Pick two organisms 
   organism* o1 = pond[x1][y1];
   organism* o2 = pond[x2][y2];

   // If both herbivore
   if ((o1 && dynamic_cast<herbivore*>(o1) && !o2) || 
       (o2 && dynamic_cast<herbivore*>(o2) && !o1) || 
       (o1 && o2 && dynamic_cast<herbivore*>(o1) && dynamic_cast<herbivore*>(o2)))
   {
      // Swap
      organism* temp = pond[x1][y1];
      pond[x1][y1] = pond[x2][y2];
      pond[x2][y2] = temp;
   }
   // If one herbivore and one plant
   if (o1 && dynamic_cast<herbivore*>(o1) && o2 && dynamic_cast<plant*>(o2))
   {
      // Cast them into their types
      herbivore* h1 = dynamic_cast<herbivore*>(o1);
      plant* p1 = dynamic_cast<plant*>(o2);
      h1->nibble(*p1);
      // Swap
      organism* temp = pond[x1][y1];
      pond[x1][y1] = pond[x2][y2];
      pond[x2][y2] = temp;
   }
   // If one plant and one herbivore
   if (o2 && dynamic_cast<herbivore*>(o2) && o1 && dynamic_cast<plant*>(o1))
   {
      // Cast them into their types
      herbivore* h2 = dynamic_cast<herbivore*>(o2);
      plant* p2 = dynamic_cast<plant*>(o1);
      h2->nibble(*p2);
      // Swap
      organism* temp = pond[x1][y1];
      pond[x1][y1] = pond[x2][y2];
      pond[x2][y2] = temp;
   }
}

// Definition of outputOrganism
void outputOrganism(organism* org)
{
   if (org == nullptr) return;

   // Check type
   if (dynamic_cast<plant*>(org))
   {
      cout << "Plant weight " << org->getSize() << endl;
   }
   else if (dynamic_cast<herbivore*>(org))
   {
      cout << "Fish with weight " << org->getSize() << endl;
   }
}

// Definition of clearSimulation
void clearSimulation(organism*** pond)
{
   for (int row = 0; row < ROWS; row++)
   {
      for (int col = 0; col < COLS; col++)
      {
         // Delete organism
         delete pond[row][col];
      }
      // Delete row
      delete[] pond[row];
   }
   // Delete pond
   delete[] pond;
}

