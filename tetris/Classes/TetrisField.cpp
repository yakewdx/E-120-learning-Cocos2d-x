/*********************************************************************
 *	@file		TetrisField.cpp
 *	@brief		Implement of TetrisField.h
 *
 *	Date        Name        Description
 *	06/12/14	MYLS		Creation.
 *
 *********************************************************************/

#include <algorithm>

#include "TetrisField.h"

/*==========================================================================*/
/*	public Constructor \ Destructor											*/
/*==========================================================================*/

TetrisField::
TetrisField() : 
	m_IsRunning(true),
	m_Timer(),
	m_Generator(0u, TETRISDATA::PIECE_TYPE_MAX - 1u),
	m_Piece(0u, 0),
	m_Collision(),
	m_Color()
{
	m_Piece.Refresh(m_Generator.Rand());
	m_Timer.Start();
}

TetrisField::
~TetrisField()
{}


/*==========================================================================*/
/*	public Methods, Modify													*/
/*==========================================================================*/

void TetrisField::
Update()
{
	if (m_Timer.GetElapsedTime() > 500u)
	{
		MoveY(-1);
		m_Timer.Start();
	}
}

void TetrisField::
Rotate(int times)
{
	if (times == 0 || !m_IsRunning)
		return;

	unsigned int pieceType = m_Piece.GetType();
	unsigned int pieceX = m_Piece.GetX();
	unsigned int pieceY = m_Piece.GetY();

	int direction = times > 0 ? 1 : -1;
	unsigned int pieceRotationMax = std::min(m_Piece.GetRotationMax(), static_cast<unsigned int>(direction * times));
	for (unsigned int i = 0; i < pieceRotationMax; i++)
	{
		m_Piece.Rotate(direction);
		if (m_Collision.IsCollided(pieceType, m_Piece.GetRotation(), pieceX, pieceY))
		{
			m_Piece.Rotate(-direction);
			return ;
		}
	}

	if (m_Piece.GetRotationMax() < static_cast<unsigned int>(direction * times))
	{
		m_Piece.Rotate(times);
	}
}

	
void TetrisField::
MoveX(int deltaX)
{
	if (deltaX == 0 || !m_IsRunning)
		return;

	unsigned int pieceType = m_Piece.GetType();
	unsigned int pieceRotation = m_Piece.GetRotation();
	unsigned int pieceX = m_Piece.GetX();
	unsigned int pieceY = m_Piece.GetY();

	int direction = deltaX > 0 ? 1 : -1;
	while (deltaX)
	{
		if (m_Collision.IsCollided(pieceType, pieceRotation, pieceX + direction, pieceY))
			break ;

		pieceX += direction;
		deltaX -= direction;
	}

	m_Piece.SetX(pieceX);
}


void TetrisField::
MoveY(int deltaY)
{
	if (deltaY >= 0 || !m_IsRunning)
		return;

	unsigned int pieceType = m_Piece.GetType();
	unsigned int pieceRotation = m_Piece.GetRotation();
	unsigned int pieceX = m_Piece.GetX();
	unsigned int pieceY = m_Piece.GetY();

	bool needs2BePlaced = false;
	int direction = deltaY > 0 ? 1 : -1;
	while (deltaY)
	{
		if (m_Collision.IsCollided(pieceType, pieceRotation, pieceX, pieceY + direction))
		{
			needs2BePlaced = true;
			break ;
		}

		pieceY += direction;
		deltaY -= direction;
	}

	m_Piece.SetY(pieceY);

	if (needs2BePlaced)
	{
		PlacePiece();
		DeleteFullLine(pieceY + TETRISDATA::PIECE_SIZE - TETRISDATA::PIECE_ANCHOR_Y, 
					   (pieceY > TETRISDATA::PIECE_ANCHOR_Y) ? (pieceY - TETRISDATA::PIECE_ANCHOR_Y) : 0);

		m_Piece.Refresh(m_Generator.Rand());
		if (m_Collision.IsCollided(m_Piece.GetType(), m_Piece.GetRotation(), m_Piece.GetX(), m_Piece.GetY()))
			m_IsRunning = false;
	}
}


/*==========================================================================*/
/*	public Methods, Query													*/
/*==========================================================================*/

void TetrisField::
CopyColors(unsigned int * colors) const
{
	for (unsigned int y = 0; y < TETRISDATA::FIELD_HEIGHT; y++)
		for (unsigned int x = 0; x < TETRISDATA::FIELD_WIDTH; x++)
			colors[x + y * TETRISDATA::FIELD_WIDTH] = m_Color.GetColorIndex(x, y);

	int startingPointX = m_Piece.GetX() - TETRISDATA::PIECE_ANCHOR_X;
	int startingPointY = m_Piece.GetY() - TETRISDATA::PIECE_ANCHOR_Y;

	for (unsigned int deltaY = 0; deltaY < TETRISDATA::PIECE_SIZE; deltaY++)
	{
		for (unsigned int deltaX = 0; deltaX < TETRISDATA::PIECE_SIZE; deltaX++)
		{
			int index = (startingPointX + deltaX) + (startingPointY + deltaY) * TETRISDATA::FIELD_WIDTH;
			if (0 <= index && index < TETRISDATA::FIELD_HEIGHT * TETRISDATA::FIELD_WIDTH && m_Piece.GetColorIndex(deltaX, deltaY) != 0u)
				colors[index] = m_Piece.GetColorIndex(deltaX, deltaY);
		}
	}
}

unsigned int TetrisField::
GetWidth() const 
{
	return TETRISDATA::FIELD_WIDTH;
}

unsigned int TetrisField::
GetHeight() const 
{
	return TETRISDATA::FIELD_HEIGHT;
}


/*==========================================================================*/
/*	private Methods															*/
/*==========================================================================*/

void TetrisField::
PlacePiece()
{
	m_Collision.PlacePiece(m_Piece.GetType(), m_Piece.GetRotation(), m_Piece.GetX(), m_Piece.GetY());
	m_Color.PlacePiece(m_Piece.GetType(), m_Piece.GetRotation(), m_Piece.GetX(), m_Piece.GetY());
}

// TODO:
// "unsigned int" cause a lot of problems
void TetrisField::
DeleteFullLine(const int begin = TETRISDATA::FIELD_HEIGHT - 1, const int end = 0)
{
	for (int y = begin; y >= end; y--)
	{
		if (m_Collision.IsLineFull(y))
		{
			m_Collision.DeleteRow(y);
			m_Color.DeleteRow(y);
			// TODO: Score++ ?
		}
	}
}

