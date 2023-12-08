// Copyright (C) 2023 Ethan Uppal. All rights reserved.

#include "sensor.h"

template<typename T>
T Sensor<T>::read() {
    while (!measurements.empty())
        ;  // wait
    T result = measurements.front();
    measurements.pop_front();
    return result;
}
