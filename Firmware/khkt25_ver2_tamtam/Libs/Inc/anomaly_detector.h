#ifndef ANOMALY_DETECTOR_H
#define ANOMALY_DETECTOR_H

#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

/* ===== CONFIG ===== */
#define MAX_BUFFER_SIZE   100
#define MAX_TIMES_SIZE    1000

#define DEFAULT_Z_THRESHOLD   1.666
#define DEFAULT_MIN_VALUES    10

/* ===== STATUS ENUM ===== */
typedef enum {
    DETECTOR_TRAINING = 0,
    DETECTOR_NORMAL,
    DETECTOR_ANOMALY,
    DETECTOR_FAKE_ANOMALY
} DetectorStatus;

/* ===== RESULT (DEBUG) ===== */
typedef struct {
    double value;
    double mean;
    double std;
    double z_score;
    uint16_t buffer_size;
    DetectorStatus status;
    bool is_anomaly;
    bool is_fake_anomaly;
} DetectionResult;

/* ===== STATISTICS (DEBUG) ===== */
typedef struct {
    uint32_t total_values;
    uint32_t normal_count;
    uint32_t anomaly_count;
    uint32_t fake_anomaly_count;
    uint16_t buffer_size;

    double anomaly_rate;
    double fake_anomaly_rate;
    double current_mean;
    double current_std;
    bool training_complete;
} DetectorStatistics;

/* ===== DETECTOR ===== */
typedef struct {
    double z_threshold;
    uint16_t min_values;

    double buffer[MAX_BUFFER_SIZE];
    uint16_t buffer_count;

    uint32_t total_count;
    uint32_t normal_count;
    uint32_t anomaly_count;
    uint32_t fake_anomaly_count;
} RealTimeAnomalyDetector;

/* ===== API ===== */
void Detector_Init(RealTimeAnomalyDetector *det);
void Detector_AddValue(RealTimeAnomalyDetector *det,
                       double value,
                       DetectionResult *result);

void Detector_GetStatistics(RealTimeAnomalyDetector *det,
                            DetectorStatistics *stats);

void Detector_Reset(RealTimeAnomalyDetector *det);

#endif
