#include "KingPiece.hh"
#include "ChessBoard.hh"

using Student::KingPiece;

KingPiece::KingPiece(ChessBoard &board, Color color, int row, int column)
    : ChessPiece(board, color, row, column)
{
    setType(King);
}

bool KingPiece::canMoveToLocation(int, int)
{
    return false;
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
