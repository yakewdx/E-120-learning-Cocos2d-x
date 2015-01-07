/*********************************************************************
 *	@file		TetrisPiece.cpp
 *	@brief		Implement of TetrisPiece.h
 *
 *	Date        Name        Description
 *	04/12/14	MYLS		Creation.
 *	06/12/14	MYLS		Separate out data.
 *
 *********************************************************************/

#include "TetrisPiece.h"

/*==========================================================================*/
/*	public Constructor \ Destructor											*/
/*==========================================================================*/

TetrisPiece::
TetrisPiece(const char type, const unsigned int rotation) :
	m_Type(0),
	m_Rotation(rotation),
	m_X(TETRISDATA::LOC_START_X),
	m_Y(TETRISDATA::LOC_START_Y)
{
	SetType(type);
}

TetrisPiece::
TetrisPiece(const unsigned int type, const unsigned int rotation) :
	m_Type(0),
	m_Rotation(rotation),
	m_X(TETRISDATA::LOC_START_X),
	m_Y(TETRISDATA::LOC_START_Y)
{
	SetType(type);
}

TetrisPiece::
~TetrisPiece()
{}


/*==========================================================================*/
/*	public Methods, Modify													*/
/*==========================================================================*/
void TetrisPiece::
Refresh(const unsigned int type)
{
	SetType(type);
	m_Rotation = 0u;
	m_X = TETRISDATA::LOC_START_X;
	m_Y = TETRISDATA::LOC_START_Y;
}

void TetrisPiece::
Rotate(const int direction)
{
	m_Rotation += direction;
	m_Rotation %= TETRISDATA::PIECE_ROTATION[m_Type];
	if (m_Rotation < 0)
		m_Rotation += TETRISDATA::PIECE_ROTATION[m_Type];
}

void TetrisPiece::
SetType(const char type)
{
	if ('A' <= type && type <= 'Z' && TETRISDATA::PIECE_NAME2INDEX[type - 'A'] >= 0)
		m_Type = TETRISDATA::PIECE_NAME2INDEX[type - 'A'];
}

void TetrisPiece::
SetType(const unsigned int type)
{
	if (type < TETRISDATA::PIECE_TYPE_MAX)
		m_Type = type;
}

void TetrisPiece::
SetX(const unsigned int x)
{
	m_X = x;
}

void TetrisPiece::
SetY(const unsigned int y)
{
	m_Y = y;
}

/*==========================================================================*/
/*	public Methods, Query													*/
/*==========================================================================*/

unsigned int TetrisPiece::
GetType(void) const
{
	return m_Type;
}

unsigned int TetrisPiece::
GetRotation(void) const
{
	return m_Rotation;
}

unsigned int TetrisPiece::
GetRotationMax(void) const
{
	return TETRISDATA::PIECE_ROTATION[m_Type];
}

unsigned int TetrisPiece::
GetX(void) const
{
	return m_X;
}

unsigned int TetrisPiece::
GetY(void) const
{
	return m_Y;
}

unsigned int TetrisPiece::
GetColorIndex(const unsigned int x, const unsigned int y) const
{
	if (x >= TETRISDATA::FIELD_WIDTH || y >= TETRISDATA::FIELD_HEIGHT)
		return 0;
	else 
		return (TETRISDATA::PIECE_COLOR_BITS[m_Type][m_Rotation][y] >> (x * TETRISDATA::COLOR_BITS)) & TETRISDATA::COLOR_MASK;

}

