/*********************************************************************
 *	@file		CollisionLayer.cpp
 *	@brief		Implement of CollisionLayer.h
 *
 *	Date        Name        Description
 *	06/12/14	MYLS		Creation.
 *	13/12/14	MYLS		Fix a bug.
 *
 *********************************************************************/

#include "CollisionLayer.h"

/*==========================================================================*/
/*	public Constructor \ Destructor											*/
/*==========================================================================*/

CollisionLayer::
CollisionLayer() :
	PIECE_RELATIVE_X(TETRISDATA::LOC_DELTA_X - TETRISDATA::PIECE_ANCHOR_X),
	PIECE_RELATIVE_Y(TETRISDATA::LOC_DELTA_Y - TETRISDATA::PIECE_ANCHOR_Y),
	m_Field(new unsigned int[TETRISDATA::FIELD_HEIGHT + 2 * TETRISDATA::LOC_DELTA_Y])
{
	ClearField();
}

CollisionLayer::
~CollisionLayer()
{
	delete[]m_Field;
}


/*==========================================================================*/
/*	public Methods, Modify													*/
/*==========================================================================*/

void CollisionLayer::
ClearField()
{
	int sizeMax = TETRISDATA::FIELD_HEIGHT + 2 * TETRISDATA::LOC_DELTA_Y;
	memset(m_Field, TETRISDATA::FILLER_FULL, sizeof(unsigned int) * TETRISDATA::LOC_DELTA_Y);
	for (int y = TETRISDATA::LOC_DELTA_Y; y < sizeMax; y++)
		m_Field[y] =TETRISDATA::FILLER_EMPTY;
}

void CollisionLayer::
PlacePiece(const unsigned int type, const unsigned int rotation, const int x, const int y)
{
	if (x < 0 || y < 0 || x >= TETRISDATA::FIELD_WIDTH || y >= TETRISDATA::FIELD_HEIGHT)
		return;

	for (unsigned int i = 0; i < TETRISDATA::PIECE_SIZE; i++)
	{
		if (TETRISDATA::PIECE_STATE_BITS[type][rotation][i])
		{
			if (PIECE_RELATIVE_X + x >= 0)
				m_Field[PIECE_RELATIVE_Y + y + i] |= TETRISDATA::PIECE_STATE_BITS[type][rotation][i] << (PIECE_RELATIVE_X + x);
			else 
				m_Field[PIECE_RELATIVE_Y + y + i] |= TETRISDATA::PIECE_STATE_BITS[type][rotation][i] >> -(PIECE_RELATIVE_X + x);
		}
	}
}

void CollisionLayer::
DeleteRow(const unsigned int y)
{
	memmove(m_Field + TETRISDATA::LOC_DELTA_Y + y, 
			m_Field + TETRISDATA::LOC_DELTA_Y + y + 1, 
			sizeof(unsigned int) * (TETRISDATA::FIELD_HEIGHT + 2 * TETRISDATA::LOC_DELTA_Y - TETRISDATA::LOC_MIN_Y - 1 - y));
}


/*==========================================================================*/
/*	public Methods, Query													*/
/*==========================================================================*/

bool CollisionLayer::
IsCollided(const unsigned int type, const unsigned int rotation, const unsigned int x, const unsigned int y) const
{
	if (x >= TETRISDATA::FIELD_WIDTH || y >= TETRISDATA::FIELD_HEIGHT)
		return true;

	for (unsigned int i = 0; i < TETRISDATA::PIECE_SIZE; i++)
		if (m_Field[PIECE_RELATIVE_Y + y + i] & (TETRISDATA::PIECE_STATE_BITS[type][rotation][i] << (PIECE_RELATIVE_X + x)))
			return true;

	return false;
}

bool CollisionLayer::
IsLineFull(const unsigned int y) const
{
	if (y >= TETRISDATA::FIELD_HEIGHT)
		return false;
	
	return m_Field[y + TETRISDATA::LOC_MIN_Y] == TETRISDATA::FILLER_FULL;
}



