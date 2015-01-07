/*********************************************************************
 *	@file		ColorLayer.cpp
 *	@brief		Implement of ColorLayer.h
 *
 *	Date        Name        Description
 *	06/12/14	MYLS		Creation.
 *
 *********************************************************************/

#include "ColorLayer.h"

/*==========================================================================*/
/*	public Constructor \ Destructor											*/
/*==========================================================================*/

ColorLayer::
ColorLayer() :
	PIECE_RELATIVE_X(- static_cast<int>(TETRISDATA::PIECE_ANCHOR_X)),
	PIECE_RELATIVE_Y(- static_cast<int>(TETRISDATA::PIECE_ANCHOR_Y)),
	m_Field(new unsigned int[TETRISDATA::FIELD_HEIGHT])
{
	/* ATTENTION: COLOR_BITS * FIELD_WIDTH <= sizeof(m_Field[0]) * 8 */
	ClearField();
}


ColorLayer::
~ColorLayer()
{
	delete[]m_Field;
}

/*==========================================================================*/
/*	public Methods, Modify													*/
/*==========================================================================*/

void ColorLayer::
ClearField()
{
	memset(m_Field, 0, sizeof(unsigned int) * TETRISDATA::FIELD_HEIGHT);
}

void ColorLayer::
PlacePiece(const unsigned int type, const unsigned int rotation, const int x, const int y)
{
	if (x < 0 || y < 0 || x >= TETRISDATA::FIELD_WIDTH || y >= TETRISDATA::FIELD_HEIGHT)
		return;

	for (unsigned int i = 0; i < TETRISDATA::PIECE_SIZE; i++)
	{
		if (TETRISDATA::PIECE_COLOR_BITS[type][rotation][i])
		{
			if (PIECE_RELATIVE_X + x >= 0)
				m_Field[PIECE_RELATIVE_Y + y + i] |= TETRISDATA::PIECE_COLOR_BITS[type][rotation][i] << ((PIECE_RELATIVE_X + x) * TETRISDATA::COLOR_BITS);
			else 
				m_Field[PIECE_RELATIVE_Y + y + i] |= TETRISDATA::PIECE_COLOR_BITS[type][rotation][i] >> (-(PIECE_RELATIVE_X + x) * TETRISDATA::COLOR_BITS);
		}
	}
}


void ColorLayer::
DeleteRow(const unsigned int y)
{
	memmove(m_Field + y, m_Field + y + 1, sizeof(unsigned int) * (TETRISDATA::FIELD_HEIGHT - 1 - y));
}

/*==========================================================================*/
/*	public Methods, Query													*/
/*==========================================================================*/

unsigned int ColorLayer::
GetColorIndex(const unsigned int x, const unsigned int y) const
{
	if (x < 0 || y < 0 || x >= TETRISDATA::FIELD_WIDTH || y >= TETRISDATA::FIELD_HEIGHT)
		return 0;
	else 
		return (m_Field[y] >> (x * TETRISDATA::COLOR_BITS)) & TETRISDATA::COLOR_MASK;
}



