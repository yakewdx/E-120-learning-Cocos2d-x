/*********************************************************************
 *	@file		TetrisPiece.hpp
 *	@brief		Class TetrisPiece
 *
 *	Date        Name        Description
 *	04/12/14	MYLS		Creation.
 *	06/12/14	MYLS		Separate out data.
 *
 *********************************************************************/

#pragma once

#include <vector>

#include "TetrisData.h"

/**
 *	\brief	Tetris's Pieces;
 */

class TetrisPiece {

public:

	/*==========================================================================*/
	/*	public Constructor \ Destructor											*/
	/*==========================================================================*/

	/**
	 *	\brief Constructor[Overloaded], all of the parameters.
	 *
	 *	\param	type		e.g. 'O', 'I', 'S', 'Z', 'L', 'J', 'T'.
	 *	\param	rotation	times of rotation
	 */
	TetrisPiece(const char type, const unsigned int rotation);

	/**
	 *	\brief Constructor[Overloaded], all of the parameters.
	 *
	 *	\param	type		e.g. 0u, 1u, 2u, 3u, 4u, 5u, 6u, 7u.
	 *	\param	rotation	times of rotation
	 */
	explicit TetrisPiece(const unsigned int type = 0u, const unsigned int rotation = 0);

	/**
	 *	\brief	Destructor
	 */
	~TetrisPiece();

	/*==========================================================================*/
	/*	public Methods, Modify													*/
	/*==========================================================================*/
	
	/**
	 *	\brief	Set up a new piece
	 *
	 *	\param	type	e.g. 0u, 1u, 2u, 3u, 4u, 5u, 6u, 7u.
	 */
	void Refresh(const unsigned int type);

	/**
	 *	\brief	Rotate
	 *
	 *	\param	times	Number of rotations
	 */
	void Rotate(const int times);

	/**
	 *	\brief	Set Type
	 *
	 *	\param	type	e.g. 'O', 'I', 'S', 'Z', 'L', 'J', 'T'.
	 */
	void SetType(const char type);

	/**
	 *	\brief	Set Type
	 *
	 *	\param	type	e.g. 0u, 1u, 2u, 3u, 4u, 5u, 6u, 7u.
	 */
	void SetType(const unsigned int type);

	/**
	 *	\brief	Set piece's x coordinate
	 *
	 *	\param	x	new x coordinate.
	 */
	void SetX(const unsigned int x);

	/**
	 *	\brief	Set piece's y coordinate
	 *
	 *	\param	y	new y coordinate.
	 */
	void SetY(const unsigned int y);

	/*==========================================================================*/
	/*	public Methods, Query													*/
	/*==========================================================================*/

	/**
	 *	\brief	Get piece's type index
	 *
	 *	\return type index
	 */
	unsigned int GetType(void) const;

	/**
	 *	\brief	Get piece's rotation index
	 *
	 *	\return rotation index
	 */
	unsigned int GetRotation(void) const;

	/**
	 *	\brief	Get piece's maximum type of rotation
	 *
	 *	\return maximum type of rotation
	 */
	unsigned int GetRotationMax(void) const;

	/**
	 *	\brief	Get piece's x coordinate
	 *
	 *	\return x
	 */
	unsigned int GetX(void) const;

	/**
	 *	\brief	Get piece's y coordinate
	 *
	 *	\return y
	 */
	unsigned int GetY(void) const;

	/**
	 *	\brief	Get piece's color
	 *
	 *	\param	x	piece's X
	 *	\param	y	piece's Y
	 *
	 *	\return index of color
	 */
	unsigned int GetColorIndex(const unsigned int x, const unsigned int y) const;


private:

	/*==========================================================================*/
	/*	private Variables / Constants											*/
	/*==========================================================================*/

	unsigned int m_Type;										/**< current piece's type */
	unsigned int m_Rotation;									/**< current piece's rotation */
	unsigned int m_X;											/**< current piece's x coordinate */
	unsigned int m_Y;											/**< current piece's y coordinate */
};

