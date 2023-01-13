/**
 * @brief Initializes the global variables
 * 
 */

// sensor messuring
const short int MAX_DATA_ARRAY_LENGTH = 20;        // 200us
short int isMessuringSensorFlag = 0;
short int isWakingSensorFlag = 0;
// short int data[MAX_DATA_ARRAY_LENGTH];
short int bitEvalData[12];
short int measurementBits[40];

char tempString [20] = {0};
char humString [20] = {0};

float borderRedHum = 70.0;
float borderYellowHum = 60.0;




