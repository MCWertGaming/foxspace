namespace Fox
{
    // waits the given time before continuing
    void sleep_for();
    // returns a std::chrono time point in milliseconds
    unsigned int get_timepoint();

    /* Fully managed timer for creating time based loops or measuring time for time based or delayed events.
     * Comes with various tools like pause, resume.
     */
    class Timer {
        private:
            unsigned int duration;
            unsigned int old_time;
            unsigned int paused_state = 0;
        public:
            // constructor of the timer class, starts the timer automatically
            Timer(unsigned int);
            virtual ~Timer() = default;
            // returns true, if the timer is done
            bool done();
            // pauses the timer
            void pause();
            // resumes the timer, pause() must have been called before
            void resume();
    };
}
