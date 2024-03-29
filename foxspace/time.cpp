#include <chrono>
#include <foxspace/time.hpp>
#include <thread>

void Fox::sleep_for(uint32_t ms_duration) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms_duration));
}
uint64_t Fox::get_timepoint() {
    return std::chrono::time_point_cast<std::chrono::milliseconds>(
               std::chrono::high_resolution_clock::now())
        .time_since_epoch()
        .count();
}
Fox::Timer::Timer(uint32_t _duration) : duration{_duration} {
    old_time = get_timepoint();
}
bool Fox::Timer::done() {
    return (get_timepoint() - old_time) > duration;
}
void Fox::Timer::pause() {
    paused_state = get_timepoint() - old_time;
}
void Fox::Timer::resume() {
    duration = paused_state;
    old_time = get_timepoint();
}
