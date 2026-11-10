#include <stdio.h>

#define MAX_ZONES 10
#define MAX_READINGS 10

double average(double data[][MAX_READINGS], int zone, int count) {
    double sum = 0;

    for (int i = 0; i < count; i++) {
        sum += data[zone][i];
    }

    return sum / count;
}

int greenIndex(double temp, double humidity, double airQuality) {
    int score = 100;

    if (temp > 30)
        score -= (int)(temp - 30) * 2;

    if (humidity < 50)
        score -= (int)(50 - humidity);

    if (airQuality > 50)
        score -= (int)(airQuality - 50) / 2;

    if (score < 0) score = 0;
    if (score > 100) score = 100;

    return score;
}

int main(void) {
    double temperature[MAX_ZONES][MAX_READINGS];
    double humidity[MAX_ZONES][MAX_READINGS];
    double airQuality[MAX_ZONES][MAX_READINGS];
    int zones, readings;

    printf("Number of zones (1-%d): ", MAX_ZONES);
    scanf("%d", &zones);

    printf("Readings per zone (1-%d): ", MAX_READINGS);
    scanf("%d", &readings);

    if (zones < 1 || zones > MAX_ZONES ||
        readings < 1 || readings > MAX_READINGS) {
        printf("Invalid number of zones or readings.\n");
        return 1;
    }

    for (int z = 0; z < zones; z++) {
        printf("\nZone %d\n", z + 1);

        for (int i = 0; i < readings; i++) {
            printf("Reading %d - temperature, humidity, air quality: ",
                   i + 1);
            scanf("%lf %lf %lf",
                  &temperature[z][i],
                  &humidity[z][i],
                  &airQuality[z][i]);
        }
    }

    for (int z = 0; z < zones; z++) {
        double avgTemp = average(temperature, z, readings);
        double avgHumidity = average(humidity, z, readings);
        double avgAir = average(airQuality, z, readings);
        int index = greenIndex(avgTemp, avgHumidity, avgAir);

        printf("\nZone %d results\n", z + 1);
        printf("Average temperature: %.1f C\n", avgTemp);
        printf("Average humidity: %.1f%%\n", avgHumidity);
        printf("Average air quality: %.1f\n", avgAir);
        printf("Green Index: %d/100\n", index);

        if (avgTemp > 35 || avgHumidity < 30 || avgAir > 100) {
            printf("Risk zone: Yes\n");
            printf("Suggestion: Add shade or plants, improve ventilation, "
                   "and check pollution sources.\n");
        } else {
            printf("Risk zone: No\n");
            printf("Suggestion: Continue monitoring and maintain greenery.\n");
        }
    }

    return 0;
}
