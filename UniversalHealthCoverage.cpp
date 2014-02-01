/* File: UniversalHealthCoverage.cpp
 *
 * A program that determines whether or not it is possible to provide
 * coverage to everyone using a fixed number of hospitals.
 */
#include <iostream>
#include <string>
#include "set.h"
#include "vector.h"
#include "console.h"
using namespace std;

/* Function prototypes */
bool canOfferUniversalCoverage(Set<string>& cities,
                               Vector< Set<string> >& locations,
                               int numHospitals,
                               Vector< Set<string> >& result);
bool canOfferUniversalCoverageRec(Set<string>& cities,
                                  Vector< Set<string> >& locations,
                                  int numHospitals,
                                  Vector< Set<string> >& result, Set<string> & citiesUsed);

/* Main function */
int main() {
	Set<string> cities;
    cities.add("CityA");
    cities.add("CityB");
    cities.add("CityC");
    cities.add("CityD");
    cities.add("CityE");
    Vector< Set<string> > locations;
    Set<string> location1;
    location1.add("CityA");
    location1.add("CityB");
    Set<string> location2;
    location1.add("CityC");
    location1.add("CityD");
    location1.add("CityE");
    locations.add(location1);
    locations.add(location2);
    int numHospitals = 2;
    Vector< Set<string> > result;
    bool canOffer = canOfferUniversalCoverage(cities, locations, numHospitals, result);
    if (canOffer == 1) {
        cout << "Yes, can offer health care to all!" << endl;
    } else {
        cout << "No, some cities are not covered." << endl;
    }
	return 0;
}


/* Function: canOfferUniversalCoverage(Set<string>& cities,
 *                                     Vector< Set<string> >& locations,
 *                                     int numHospitals,
 *                                     Vector< Set<string> >& result);
 * Usage: if (canOfferUniversalCoverage(cities, locations, 4, result)
 * ==================================================================
 * Given a set of cities, a list of what cities various hospitals can
 * cover, and a number of hospitals, returns whether or not it's
 * possible to provide coverage to all cities with the given number of
 * hospitals.  If so, one specific way to do this is handed back in the
 * result parameter.
 */
bool canOfferUniversalCoverage(Set<string>& cities,
                               Vector< Set<string> >& locations,
                               int numHospitals,
                               Vector< Set<string> >& result) {
	Set<string> citiesUsed;
    return canOfferUniversalCoverageRec(cities, locations, numHospitals, result, citiesUsed);
}


bool canOfferUniversalCoverageRec(Set<string>& cities,
                                  Vector< Set<string> >& locations,
                                  int numHospitals,
                                  Vector< Set<string> >& result, Set<string> & citiesUsed) {
    /* Base case: If the maximum number of hospitals have been built,
     * then compare the cities covered so far to the total list of cities
     */
    if (numHospitals == 0) {
        return citiesUsed.size() == cities.size();
    } else {
        for (int i = 0; i < locations.size(); i ++) {
        Set<string> currentLocation = locations[i];
        foreach(string city in currentLocation) {
                citiesUsed.add(city);
        }
        if (canOfferUniversalCoverageRec(cities, locations, numHospitals -1, result, citiesUsed))
            result.add(currentLocation);
            return true;
        }
    }
    return false;
}
    


















