#include "Core/Timer.h"
#include <Windows.h>

Timer::Timer()
{   
    LARGE_INTEGER freq;
    
    QueryPerformanceFrequency(&freq);
    m_Frequency = freq.QuadPart;

    Reset();
}

void Timer::Reset()
{
    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);

    m_StartTime = counter.QuadPart;
    m_PreviousTime = m_StartTime;
    m_CurrentTime = m_StartTime;

    m_DeltaTime = 0.0;
    m_TotalTime = 0.0;
    m_FPS = 0.0;
}

void Timer::Tick()
{
    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);

    m_CurrentTime = counter.QuadPart;

    m_DeltaTime = static_cast<double>(m_CurrentTime - m_PreviousTime) / m_Frequency;
    m_TotalTime = static_cast<double>(m_CurrentTime - m_StartTime) / m_Frequency;

    if (m_DeltaTime > 0.0)
        m_FPS = 1.0 / m_DeltaTime;
    else
        m_FPS = 0.0;

    m_PreviousTime = m_CurrentTime;
}

double Timer::GetDeltaTime() const
{
    return m_DeltaTime;
}

double Timer::GetTotalTime() const
{
    return m_TotalTime;
}

double Timer::GetFPS() const
{
    return m_FPS;
}