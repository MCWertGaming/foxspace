namespace Fox {
// waits the given time before continuing
void sleep_for(uint32_t);
// returns a std::chrono time point in milliseconds
uint64_t get_timepoint();

/* Fully managed timer for creating time based loops or measuring time for time
 * based or delayed events. Comes with various tools like pause, resume.
 */
class Timer {
   private:
    uint32_t duration;
    uint64_t old_time;
    uint64_t paused_state = 0;

   public:
    // constructor of the timer class, starts the timer automatically
    Timer(uint32_t);
    virtual ~Timer() = default;
    // returns true, if the timer is done
    bool done();
    // pauses the timer
    void pause();
    // resumes the timer, pause() must have been called before
    void resume();
};
}  // namespace Fox
