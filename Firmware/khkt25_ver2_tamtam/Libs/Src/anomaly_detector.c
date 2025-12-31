#include "anomaly_detector.h"

/* ===== INTERNAL UTILS ===== */
static double calculate_mean(double *arr, uint16_t size)
{
    if (size == 0) return 0.0;

    double sum = 0.0;
    for (uint16_t i = 0; i < size; i++)
        sum += arr[i];

    return sum / size;
}

static double calculate_std(double *arr, uint16_t size, double mean)
{
    if (size == 0) return 0.0;

    double sum = 0.0;
    for (uint16_t i = 0; i < size; i++) {
        double d = arr[i] - mean;
        sum += d * d;
    }
    return sqrt(sum / size);
}

/* ===== API IMPLEMENTATION ===== */
void Detector_Init(RealTimeAnomalyDetector *det)
{
    memset(det, 0, sizeof(RealTimeAnomalyDetector));
    det->z_threshold = DEFAULT_Z_THRESHOLD;
    det->min_values  = DEFAULT_MIN_VALUES;
}

void Detector_AddValue(RealTimeAnomalyDetector *det,
                       double value,
                       DetectionResult *res)
{
    det->total_count++;

    /* reset result */
    memset(res, 0, sizeof(DetectionResult));
    res->value = value;
    res->buffer_size = det->buffer_count;

    /* ===== TRAINING ===== */
    if (det->buffer_count < det->min_values) {
        det->buffer[det->buffer_count++] = value;
        det->normal_count++;

        res->status = DETECTOR_TRAINING;
        res->buffer_size = det->buffer_count;
        return;
    }

    /* ===== CALCULATION ===== */
    double mean = calculate_mean(det->buffer, det->buffer_count);
    double std  = calculate_std(det->buffer, det->buffer_count, mean);

    double z = 0.0;
    if (std > 0)
        z = (value - mean) / std;

    res->mean = mean;
    res->std  = std;
    res->z_score = z;

    /* ===== CLASSIFICATION ===== */
    if (z > det->z_threshold) {
        /* REAL ANOMALY */
        res->status = DETECTOR_ANOMALY;
        res->is_anomaly = true;
        det->anomaly_count++;
    }
    else if (z < -det->z_threshold) {
        /* FAKE ANOMALY */
        res->status = DETECTOR_FAKE_ANOMALY;
        res->is_fake_anomaly = true;
        det->fake_anomaly_count++;
    }
    else {
        /* NORMAL */
        res->status = DETECTOR_NORMAL;
        det->normal_count++;

        if (det->buffer_count < MAX_BUFFER_SIZE) {
            det->buffer[det->buffer_count++] = value;
        }
    }

    res->buffer_size = det->buffer_count;
}

void Detector_GetStatistics(RealTimeAnomalyDetector *det,
                            DetectorStatistics *stats)
{
    memset(stats, 0, sizeof(DetectorStatistics));

    stats->total_values       = det->total_count;
    stats->normal_count       = det->normal_count;
    stats->anomaly_count      = det->anomaly_count;
    stats->fake_anomaly_count = det->fake_anomaly_count;
    stats->buffer_size        = det->buffer_count;

    if (det->total_count > 0) {
        stats->anomaly_rate =
            (double)det->anomaly_count / det->total_count;

        stats->fake_anomaly_rate =
            (double)det->fake_anomaly_count / det->total_count;
    }

    stats->current_mean =
        calculate_mean(det->buffer, det->buffer_count);

    stats->current_std =
        calculate_std(det->buffer,
                      det->buffer_count,
                      stats->current_mean);

    stats->training_complete =
        (det->buffer_count >= det->min_values);
}

void Detector_Reset(RealTimeAnomalyDetector *det)
{
    det->buffer_count = 0;
    det->total_count = 0;
    det->normal_count = 0;
    det->anomaly_count = 0;
    det->fake_anomaly_count = 0;
}
