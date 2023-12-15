#include "task1-functions.h"
#include <iostream>

#define KM_PER_MILE 1.609344

int setEngineMode(int S, int B) {
    // Convert speed from miles per hour to kilometers per hour
    int S_kmh = round(S * KM_PER_MILE);

    // Display the converted speed
    std::cout << S_kmh << std::endl;

    // Check if the battery level is greater than 25%
    if (B > 25) {
        // Check if the speed is less than or equal to 10 km/h
        if (S_kmh <= 10) {
            // Set Engine Mode to Battery (0) and display it
            std::cout << "Battery" << std::endl;
            return 0;
        }
        else {
            // Set Engine Mode to Petrol (1) and display it
            std::cout << "Petrol" << std::endl;
            return 1;
        }
    }
    else {
        // Set Engine Mode to Battery (0) and display it
        std::cout << "Battery" << std::endl;
        return 0;
    }
}
