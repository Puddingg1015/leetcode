#define _min(a, b) ({int _a = a; int _b = b; (_a > _b ? _b : _a);})
#define min(a, b) (a > b ? b : a)
#define max(a, b) (a > b ? a : b)


int earliestFinishTime(int* landStartTime, int landStartTimeSize, int* landDuration, int landDurationSize, int* waterStartTime, int waterStartTimeSize, int* waterDuration, int waterDurationSize) {
    // well that was simple, time to be goofy
    // I present: one of the O(MN) solutions everf
    int min_end = 0x7FFFFFFF, min_land_end = 0x7FFFFFFF, min_water_end = 0x7FFFFFFF;
    for (int i = 0; i < landStartTimeSize; i++) min_land_end = min(min_land_end, landStartTime[i] + landDuration[i]);
    for (int j = 0; j < waterStartTimeSize; j++) min_end = min(min_end, min_land_end + max(0, waterStartTime[j] - min_land_end) + waterDuration[j]);
    for (int i = 0; i < waterStartTimeSize; i++) min_water_end = min(min_water_end, waterStartTime[i] + waterDuration[i]);
    for (int j = 0; j < landStartTimeSize; j++) min_end = min(min_end, min_water_end + max(0, landStartTime[j] - min_water_end) + landDuration[j]);
    return min_end;
}