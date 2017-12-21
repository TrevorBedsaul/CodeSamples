#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

class MiddleEarth {
private:
  /** 
   * private variables number of cities, width, height
   */
    int num_city_names, xsize, ysize;

    /** 
     * private float vectors for x and y position
     */
    vector<float> xpos, ypos;
    
    /** 
     * private string vector with city names
     */
    vector<string> cities;

    /** 
     * float pointer fot distances
     */
    float *distances;

    /** 
     * map of strings and ints to contain indices of cities
     */
    map<string, int> indices;

public:
 /** Iluvatar
 *  the creator of Middle-Earth
 *  @param xsize width as int
 *  @param ysize height as int
 *  @param num_cities number of cities as int
 *  @param seed random seed as int
 */
    MiddleEarth (int xsize, int ysize, int numcities, int seed);

 /** Sauron
 *  the destructor of Middle-Earth.
 */
    ~MiddleEarth();

 /** The Mouth of Sauron!
 *  prints out info on the created 'world'
 */   
    void print();

/** 
 * prints a tab-separated table of the distances (this can be loaded
 * into Excel or similar)
 */
    void printTable();

 /** 
 * This method returns the distance between the two passed cities.  If
 * we assume that the hash table (i.e. the map) is O(1), then this
 * method call is also O(1)
 * @param city1 first city string
 * @param city2 second city string
 * @return float distance between two cities
 */
    float getDistance (string city1, string city2);

/** 
 * Returns the list of cities to travel to.  The first city is the
 * original start point as well as the end point.  The number of
 * cities passed in does not include this start/end point (so there
 * will be length+1 entries in the returned vector).
 * @param length - number of cities passed as unsigned int
 * @return vector<string> list of cities to travel to
 */
    vector<string> getItinerary(unsigned int length);
};

#endif
