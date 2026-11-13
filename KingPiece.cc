#include "KingPiece.hh"
#include "ChessBoard.hh"

using Student::KingPiece;

KingPiece::KingPiece(ChessBoard &board, Color color, int row, int column)
    : ChessPiece(board, color, row, column)
{
    setType(King);
}

//checks validity of kingpiece movement
bool KingPiece::canMoveToLocation(int toRow, int toColumn)
{
    int dRow = toRow - getRow();
    int dCol = toColumn - getColumn();

    // King cannot stay in the same square
    if (dRow == 0 && dCol == 0)
    {
        return false;
    }

    // King can only move one square in any direction
    if (dRow > 1 || dRow < -1 || dCol > 1 || dCol < -1)
    {
        return false;
    }

    return canLandOn(toRow, toColumn);
}
const char *KingPiece::toString()
{
    if (getColor() == White)
    {
        return "♔";
    }
    else
    {
        return "♚";
    }
}
