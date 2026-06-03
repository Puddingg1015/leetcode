#define _min(a, b) ({int _a = a; int _b = b; (_a > _b ? _b : _a);})
#define min(a, b) (a > b ? b : a)
#define max(a, b) (a > b ? a : b)


int earliestFinishTime(int* landStartTime, int landStartTimeSize, int* landDuration, int landDurationSize, int* waterStartTime, int waterStartTimeSize, int* waterDuration, int waterDurationSize) {
    // welp brute force aint workin time to use brain
    int min_end = 0x7FFFFFFF;
    int min_land_end = 0x7FFFFFFF;
    int min_water_end = 0x7FFFFFFF;
    for (int i = 0; i < landStartTimeSize; i++) {
        min_land_end = min(min_land_end, landStartTime[i] + landDuration[i]);
    }
    for (int j = 0; j < waterStartTimeSize; j++) {
        int delay = max(0, waterStartTime[j] - min_land_end);
        min_end = min(min_end, min_land_end + delay + waterDuration[j]);
    }
    for (int i = 0; i < waterStartTimeSize; i++) {
        min_water_end = min(min_water_end, waterStartTime[i] + waterDuration[i]);
    }
    for (int j = 0; j < landStartTimeSize; j++) {
        int delay = max(0, landStartTime[j] - min_water_end);
        min_end = min(min_end, min_water_end + delay + landDuration[j]);
    }
    // for (int i = 0; i < landStartTimeSize; i++) {
    //     int land_end = landStartTime[i] + landDuration[i];
    //     for (int j = 0; j < waterStartTimeSize; j++) {
    //         int delay = (land_end >= waterStartTime[j] ? 0 : waterStartTime[j] - land_end);
    //         if (min > land_end + delay + waterDuration[j]) min = land_end + delay + waterDuration[j];
    //     }
    // }
    // for (int i = 0; i < waterStartTimeSize; i++) {
    //     int water_end = waterStartTime[i] + waterDuration[i];
    //     for (int j = 0; j < landStartTimeSize; j++) {
    //         int delay = (water_end >= landStartTime[j] ? 0 : landStartTime[j] - water_end);
    //         if (min > water_end + delay + landDuration[j]) min = water_end + delay + landDuration[j];
    //     }
    // }
    printf("%d", 14 + 30 + 71);
    return min_end;
}