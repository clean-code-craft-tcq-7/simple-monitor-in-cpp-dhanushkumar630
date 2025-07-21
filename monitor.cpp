#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

void Warning(const std::string& message) {
  cout << message << "\n";
  for (int i = 0; i < 6; i++) {
    cout << "\r* " << flush;
    sleep_for(seconds(1));
    cout << "\r *" << flush;
    sleep_for(seconds(1));
  }
}

bool Temperature_check(float temperature) {
  if (temperature < 95 || temperature > 102) {
    Warning("Temperature is critical!");
    return false;
  }
  return true;
}

bool Pulse_check(float pulseRate) {
  if (pulseRate < 60 || pulseRate > 100) {
    Warning("Pulse Rate is out of range!");
    return false;
  }
  return true;
}

bool Oxygen_check(float spo2) {
  if (spo2 < 90) {
    Warning("Oxygen Saturation out of range!");
    return false;
  }
  return true;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
  return Temperature_check(temperature) && Pulse_check(pulseRate) && Oxygen_check(spo2);
}
