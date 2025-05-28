
//  rainOrShine.cpp
//  C++Projects
//
//  Created by Aqila Nasiry on 3/25/25.


//#include "rainOrShine.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int NUM_OF_DAYS_IN_MONTH = 30;
const int NUM_MONTHS = 3;

void readWeatherData(char weatherData[][NUM_OF_DAYS_IN_MONTH], const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    for (int month = 0; month < NUM_MONTHS; ++month) {
        for (int day = 0; day < NUM_OF_DAYS_IN_MONTH; ++day) {
            inputFile >> weatherData[month][day];
        }
    }
    inputFile.close();
}

void countWeatherConditions(const char weatherData[][NUM_OF_DAYS_IN_MONTH],
                           int counts[][3], int& totalRainy,
                           int& totalCloudy, int& totalSunny) {
    totalRainy = totalCloudy = totalSunny = 0;
    
    for (int month = 0; month < NUM_MONTHS; ++month) {
        counts[month][0] = counts[month][1] = counts[month][2] = 0;
        
        for (int day = 0; day < NUM_OF_DAYS_IN_MONTH; ++day) {
            switch (weatherData[month][day]) {
                case 'R':
                    counts[month][0]++;
                    totalRainy++;
                    break;
                case 'C':
                    counts[month][1]++;
                    totalCloudy++;
                    break;
                case 'S':
                    counts[month][2]++;
                    totalSunny++;
                    break;
            }
        }
    }
}

void printMonthlyReport(const int counts[][3], const string months[]) {
    cout << "Monthly Weather Report:\n";
    
    for (int month = 0; month < NUM_MONTHS; ++month) {
        cout << months[month] << ":\n";
        cout << "  Rainy days: " << counts[month][0] << endl;
        cout << "  Cloudy days: " << counts[month][1] << endl;
        cout << "  Sunny days: " << counts[month][2] << endl << endl;
    }
}

void printSeasonalReport(int totalRainy, int totalCloudy, int totalSunny) {
    cout << "Here is three Months report:\n";
    cout << "Total rainy days: " << totalRainy << endl;
    cout << "Total cloudy days: " << totalCloudy << endl;
    cout << "Total sunny days: " << totalSunny << endl << endl;
}

string findRainiestMonth(const int counts[][3], const string months[]) {
    int maxRain = counts[0][0];
    string rainiestMonth = months[0];
    
    for (int month = 1; month < NUM_MONTHS; ++month) {
        if (counts[month][0] > maxRain) {
            maxRain = counts[month][0];
            rainiestMonth = months[month];
        }
    }
    
    return rainiestMonth;
}

int main() {
    char weatherData[NUM_MONTHS][NUM_OF_DAYS_IN_MONTH];
    int counts[NUM_MONTHS][3]; // [month][0=rainy, 1=cloudy, 2=sunny]
    int totalRainy, totalCloudy, totalSunny;
    string months[NUM_MONTHS] = {"June", "July", "August"};
    
    readWeatherData(weatherData, "RainOrShine.txt");
    
    countWeatherConditions(weatherData, counts, totalRainy, totalCloudy, totalSunny);
    
    // Generate reports
    printMonthlyReport(counts, months);
    printSeasonalReport(totalRainy, totalCloudy, totalSunny);
    
    // Find and display rainiest month
    string rainiestMonth = findRainiestMonth(counts, months);
    cout << "The month with the most rainy days was " << rainiestMonth << "." << endl;
    
    return 0;
}
