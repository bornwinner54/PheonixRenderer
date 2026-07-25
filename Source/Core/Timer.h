#pragma once 

class Timer
{
    public:
        Timer();
        void Reset();
        void Tick();

        double GetDeltaTime() const;
        double GetTotalTime() const;
        double GetFPS() const;

    private:
        long long m_Frequency = 0;
        long long m_StartTime = 0;
        long long m_PreviousTime = 0;
        long long m_CurrentTime = 0;

        double m_DeltaTime = 0.0;
        double m_TotalTime = 0.0;
        double m_FPS = 0.0;

};