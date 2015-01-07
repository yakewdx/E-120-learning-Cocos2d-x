/*********************************************************************
 *	@file		Timer.hpp
 *	@brief		Class Timer
 *
 *	Date        Name        Description
 *	23/11/14	MYLS		Creation.
 *
 *********************************************************************/

#pragma once

/**
 *	\brief	A timer, just for timing;
 */
class Timer {

public:

	/*==========================================================================*/
	/*	public Constructor \ Destructor											*/
	/*==========================================================================*/
	
	/**
	 *	\brief Constructor
	 */
	Timer();

	/**
	 *	\brief	Destructor
	 */
	~Timer();

	/*==========================================================================*/
	/*	public Methods, Modify													*/
	/*==========================================================================*/

	/**
	 *	\brief	Clear and Start Timer
	 */
	void Start(void);

	/**
	 *	\brief	Pause Timer
	 *			While running
	 */
	void Pause(void);

	/**
	 *	\brief	Resume Timer
	 *			while paused
	 */
	void Resume(void);

	/**
	 *	\brief	Reset the timer
	 */
	void Stop(void);

	/*==========================================================================*/
	/*	public Methods, Query													*/
	/*==========================================================================*/

	/**
	 *	\brief	Get Elapsed Time...
	 */
	unsigned int GetElapsedTime(void) const;

private:

	/*==========================================================================*/
	/*	private Variables / Constants											*/
	/*==========================================================================*/
	
	/**
	 *	\brief	a enum representative timer status
	 */
	enum TimerStatus : unsigned char {
		TIMER_STOP,											/**< status stop */
		TIMER_RUNNINNG,										/**< status running */
		TIMER_PAUSED										/**< status paused */
	};

	TimerStatus m_Status;									/**< timer's Status */
	unsigned int m_TimePaused;								/**< time when pause timer */
	unsigned int m_TimeInitial;								/**< time when start timer */
};

