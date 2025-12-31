#ifndef SIMPLE_KALMAN_FILTER_H
#define SIMPLE_KALMAN_FILTER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    /* Measurement noise (R) */
    float err_measure;

    /* Estimation error covariance (P) */
    float err_estimate;

    /* Process noise (Q) */
    float q;

    /* Kalman gain (K) */
    float kalman_gain;

    /* Current filtered value */
    float current_estimate;

    /* Previous filtered value */
    float last_estimate;

} SimpleKalmanFilter;

/* Initialize Kalman filter */
void SKF_Init(SimpleKalmanFilter *kf,
              float mea_e,
              float est_e,
              float q);

/* Update filter with new measurement */
double SKF_UpdateEstimate(SimpleKalmanFilter *kf,
                         double measurement);

/* Setters */
void SKF_SetMeasurementError(SimpleKalmanFilter *kf, float mea_e);
void SKF_SetEstimateError(SimpleKalmanFilter *kf, float est_e);
void SKF_SetProcessNoise(SimpleKalmanFilter *kf, float q);

/* Getters */
float SKF_GetKalmanGain(SimpleKalmanFilter *kf);
float SKF_GetEstimateError(SimpleKalmanFilter *kf);

#ifdef __cplusplus
}
#endif

#endif /* SIMPLE_KALMAN_FILTER_H */
