//Trevor Bedsaul
//tdb7mw
//traveling.cpp

#include <limits>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include "middleearth.h"

/**
 * This method will compute the full distance of the cycle that starts
 * at the 'start' parameter, goes to each of the cities in the dests
 * vector IN ORDER, and ends back at the 'start' parameter.
 * @param me the MiddleEarth reference
 * @param start string with the start/end of cycle
 * @param dests list of cities
 * @return float with the total distance
 */
float computeDistance (MiddleEarth &me, string start, vector<string> dests);

/**
 * This method will print the entire route, starting and ending at the
 * 'start' parameter.  The output should be of the form:
 * Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
 * @param start string for start and end of cycle
 * @param dests vector<string> list of cities in order
 */
void printRoute (string start, vector<string> dests);

int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    string str = dests[0];
    float min = numeric_limits<float>::max();
    vector<string> temp;

    /**
     * checks all permutations of the cities and computes the distance
     * saves the minimum
     */
    do {
      float dis = computeDistance(me, str, dests);
      if(dis < min) {
	min = dis;
	temp = dests;
      }
    } while(next_permutation(dests.begin(), dests.end()));
    printRoute(str, temp);
    cout << "Length " << min << endl; 
    return 0;
}

/**
 * This method will compute the full distance of the cycle that starts
 * at the 'start' parameter, goes to each of the cities in the dests
 * vector IN ORDER, and ends back at the 'start' parameter.
 * @param me the MiddleEarth reference
 * @param start string with the start/end of cycle
 * @param dests list of cities
 * @return float with the total distance
 */
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
  float sum = me.getDistance(start, dests[0]) + me.getDistance(start, dests[dests.size()-1]);
  for(int i = 0; i < dests.size()-1; i++) {
    sum += me.getDistance(dests[i], dests[i+1]);
  }
  return sum;
}

/**
 * This method will print the entire route, starting and ending at the
 * 'start' parameter.  The output should be of the form:
 * Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
 * @param start string for start and end of cycle
 * @param dests vector<string> list of cities in order
 */
void printRoute (string start, vector<string> dests) {
  cout << start << " -> ";
  for(int i = 0; i < dests.size()-1; i++)
    cout << dests[i] << " -> ";
  cout << start << endl;
}
