/*********************************************************************
 *	@file		TetrisData.hpp
 *	@brief		Class RandomNumberGenerator, for generating random number.
 *
 *	Date        Name        Description
 *	11/12/14	MYLS		Creation.
 *
 *********************************************************************/

#pragma once

#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <functional>
#include <iomanip>
#include <unordered_map>
#include <random>

/**
 *	\brief	A small class, RandomNumberGenerator, for generating random number.
 */
template <typename T>
class RandomNumberGenerator {

public:
	
	/*==========================================================================*/
	/*	public Constructor \ Destructor											*/
	/*==========================================================================*/
	
	/**
	 *	\brief Constructor
	 *
	 *	\param	left	left bound
	 *	\param	right	right bound
	 */
	RandomNumberGenerator(const T & left, const T & right) : 
		m_Engine(static_cast<T>(time(NULL))),
		m_Distribution(left, right)
	{}

	/**
	 *	\brief	Destructor
	 */
	~RandomNumberGenerator() {}


	/*==========================================================================*/
	/*	public Methods, Query													*/
	/*==========================================================================*/

	/**
	 *	\brief	Get a random number
	 */
	T Rand() const
	{
		static auto generator = std::bind(m_Distribution, m_Engine);
		return generator();
	}


private:


	/*==========================================================================*/
	/*	private Variables / Constants											*/
	/*==========================================================================*/

	std::mt19937 m_Engine;										/**< engine of random number generator */
	std::uniform_int_distribution<T> m_Distribution;			/**< distribution of random number */

};

