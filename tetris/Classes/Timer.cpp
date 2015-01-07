/*********************************************************************
 *	@file		Timer.cpp
 *	@brief		Implement of Timer.hpp
 *
 *	Date        Name        Description
 *	23/11/14	MYLS		Creation.
 *	08/12/14	MYLS		Modify comment.
 *
 *********************************************************************/


#include <time.h>

#include "Timer.h"


/*==========================================================================*/
/*	public Constructor \ Destructor											*/
/*==========================================================================*/

Timer::
Timer()
	: m_Status(TIMER_STOP),
	m_TimePaused(0),
	m_TimeInitial(0)
{}

Timer::
~Timer()
{}


/*==========================================================================*/
/*	public Methods, Modify													*/
/*==========================================================================*/

void Timer::
Start(void)
{
	m_Status = TIMER_RUNNINNG;
	m_TimeInitial = clock();
	m_TimePaused = 0;
}

void Timer::
Pause(void)
{
	if (m_Status != TIMER_RUNNINNG)
		return;

	m_Status = TIMER_PAUSED;
	m_TimePaused = clock();
}

void Timer::
Resume(void)
{
	if (m_Status != TIMER_PAUSED)
		return;

	m_Status = TIMER_RUNNINNG;
	m_TimeInitial += clock() - m_TimePaused;
	m_TimePaused = 0;
}

void Timer::
Stop(void)
{
	m_Status = TIMER_STOP;
	m_TimeInitial = 0;
	m_TimePaused = 0;
}


/*==========================================================================*/
/*	public Methods, Query													*/
/*==========================================================================*/

unsigned int Timer::
GetElapsedTime(void) const
{
	if (m_Status == TIMER_RUNNINNG)
		return clock() - m_TimeInitial;
	else if (m_Status == TIMER_PAUSED)
		return m_TimePaused - m_TimeInitial;
	else if (m_Status == TIMER_STOP)
		return 0;
	else
		return -1;
}


