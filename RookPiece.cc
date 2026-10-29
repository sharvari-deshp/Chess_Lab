#include "RookPiece.hh"
#include "ChessBoard.hh"

using Student::RookPiece;

bool RookPiece::canMoveToLocation(int toRow, int toColumn)
{
    //one of row/column should change
    if ((toRow==getRow()) == (toColumn==getColumn()))
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

