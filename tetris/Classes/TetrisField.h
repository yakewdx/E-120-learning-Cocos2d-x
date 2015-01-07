/*********************************************************************
 *	@file		TetrisField.h
 *	@brief		Class TetrisField, includes collision detection, 
 *				color information and so on.
 *
 *	Date        Name        Description
 *	06/12/14	MYLS		Creation.
 *
 *********************************************************************/

#include "TetrisData.h"
#include "Timer.h"
#include "RandomNumberGenerator.h"
#include "TetrisPiece.h"
#include "CollisionLayer.h"
#include "ColorLayer.h"


#pragma once

/**
 *	\brief	TetrisField.
 *			Includes collision detection, color information and so on.
 */

class TetrisField {

public:

	/*==========================================================================*/
	/*	public Constructor \ Destructor											*/
	/*==========================================================================*/

	/**
	 *	\brief Constructor
	 */
	TetrisField();
	
	/**
	 *	\brief	Destructor
	 */
	~TetrisField();

	/*==========================================================================*/
	/*	public Methods, Modify													*/
	/*==========================================================================*/
	
	/**
	 *	\brief	Update
	 *			Determine whether the piece falls.
	 */
	void Update();

	/**
	 *	\brief	Rotate Piece
	 *			if IsCollided() == false.
	 */
	void Rotate(int times);
	
	/**
	 *	\brief	Move Piece Horizontally
	 *			if IsCollided() == false.
	 *
	 *	\param	deltaX		positive number is rightward.
	 */
	void MoveX(int deltaX);

	/**
	 *	\brief	Move Piece Vertical
	 *			if IsCollided() == false.
	 *
	 *	\param	deltaY		positive number is upward.
	 */
	void MoveY(int deltaY);

	/*==========================================================================*/
	/*	public Methods, Query													*/
	/*==========================================================================*/

	/**
	 *	\brief	Get the color of a point
	 *
	 *	\param	width		width of the array
	 *	\param	height		height of the array
	 *	
	 *	\return	index of color.
	 */
	void CopyColors(unsigned int * colors) const;

	/**
	 *	\brief	Get width of field
	 *	
	 *	\return	Width.
	 */
	unsigned int GetWidth(void) const;

	/**
	 *	\brief	Get height of field
	 *	
	 *	\return	height.
	 */
	unsigned int GetHeight(void) const;


private:

	/*==========================================================================*/
	/*	private Methods															*/
	/*==========================================================================*/

	/**
	 *	\brief	Place Piece
	 *			Add current piece to m_Color && m_Collision
	 *			(No collision detection !)
	 */
	void PlacePiece();

	/**
	 *	\brief	find a full line and delete it if it exists
	 *			begin >= end
	 *
	 *	\param	begin		the line beginning (inclusive).
	 *	\param	end			the line end (not inclusive). 
	 */
	void DeleteFullLine(const int begin, const int end);

	/*==========================================================================*/
	/*	private Variables / Constants											*/
	/*==========================================================================*/


	// TODO:
	// Score... so on.

	bool m_IsRunning;											/**< Whether the game running. */

	Timer m_Timer;											/**< Control whether the piece falls. */
	RandomNumberGenerator<unsigned int> m_Generator;		/**< Generates a random number. */

	TetrisPiece m_Piece;									/**< Piece Manager. */
	ColorLayer m_Color;										/**< Color Layer */
	CollisionLayer m_Collision;								/**< Collision Layer */
};

