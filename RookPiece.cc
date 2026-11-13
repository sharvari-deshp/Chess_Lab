#include "RookPiece.hh"
#include "ChessBoard.hh"

using Student::RookPiece;

bool RookPiece::canMoveToLocation(int toRow, int toColumn)
{
    if ((toRow==getRow()) == (toColumn==getColumn()))
        return false;

    if (!canLandOn(toRow, toColumn))
        return false;

    return isPathClear(toRow, toColumn);
}

const char *RookPiece::toString()
{
    if (getColor() == White)
    {
        return "♖";
    }
    else
    {
        return "♜";
    }
}

