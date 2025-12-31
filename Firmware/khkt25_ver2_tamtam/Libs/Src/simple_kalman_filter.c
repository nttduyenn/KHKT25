#include "simple_kalman_filter.h"
#include <math.h>

void SKF_Init(SimpleKalmanFilter *kf,
              float mea_e,
              float est_e,
              float q)
{
    kf->err_measure  = mea_e;
    kf->err_estimate = est_e;
    kf->q            = q;

    /* Initial states */
    kf->current_estimate = 0.0f;
    kf->last_estimate    = 0.0f;
    kf->kalman_gain      = 0.0f;
}

double SKF_UpdateEstimate(SimpleKalmanFilter *kf,
                         double measurement)
{
    /* Calculate Kalman Gain */
    kf->kalman_gain =
        kf->err_estimate /
        (kf->err_estimate + kf->err_measure);

    /* Update current estimate */
    kf->current_estimate =
        kf->last_estimate +
        kf->kalman_gain *
        (measurement - kf->last_estimate);

    /* Update estimation error */
    kf->err_estimate =
        (1.0f - kf->kalman_gain) * kf->err_estimate +
        fabsf(kf->last_estimate - kf->current_estimate) * kf->q;

    /* Save state for next iteration */
    kf->last_estimate = kf->current_estimate;

    return kf->current_estimate;
}

void SKF_SetMeasurementError(SimpleKalmanFilter *kf, float mea_e)
{
    kf->err_measure = mea_e;
}

void SKF_SetEstimateError(SimpleKalmanFilter *kf, float est_e)
{
    kf->err_estimate = est_e;
}

void SKF_SetProcessNoise(SimpleKalmanFilter *kf, float q)
{
    kf->q = q;
}

float SKF_GetKalmanGain(SimpleKalmanFilter *kf)
{
    return kf->kalman_gain;
}

float SKF_GetEstimateError(SimpleKalmanFilter *kf)
{
    return kf->err_estimate;
}
