#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

using Student::ChessBoard;

std::ostringstream ChessBoard::displayBoard()
{
    std::ostringstream outputString;
    // top scale
    outputString << "  ";
    for (int i = 0; i < numCols; i++){
        outputString << i << " ";
    }
    outputString << std::endl << "  ";
    // top border
    for (int i = 0; i < numCols; i++){
        outputString << "– ";
    }
    outputString << std::endl;

    for (int row = 0; row < numRows; row++){
        outputString << row << "|";
        for (int column = 0; column < numCols; column++){
            ChessPiece *piece = board.at(row).at(column);
            outputString << (piece == nullptr ? " " : piece->toString()) << " ";
        }
        outputString << "|" << std::endl;
    }

    // bottom border
    outputString << "  ";
    for (int i = 0; i < numCols; i++){
        outputString << "– ";
    }
    outputString << std::endl << std::endl;

    return outputString;
}


using Student::ChessPiece;
using Student::KingPiece;

// ChessPiece functions

ChessPiece::ChessPiece(ChessBoard &board, Color color, int row, int column)
    : board(board), color(color), type(Pawn), row(row), column(column)
{
}

Color ChessPiece::getColor()
{
    return color;
}

Type ChessPiece::getType()
{
    return type;
}

int ChessPiece::getRow()
{
    return row;
}

int ChessPiece::getColumn()
{
    return column;
}

void ChessPiece::setType(Type newType)
{
    type = newType;
}

void ChessPiece::setPosition(int newRow, int newColumn)
{
    row = newRow;
    column = newColumn;
}

bool ChessPiece::isPathClear(int toRow, int toColumn)
{
    if (toRow < 0 || toRow >= board.getNumRows() ||
        toColumn < 0 || toColumn >= board.getNumCols())
    {
        return false;
    }

    int dRow = toRow - row;
    int dCol = toColumn - column;

    if (dRow == 0 && dCol == 0)
    {
        return false;
    }

    int absRow = dRow < 0 ? -dRow : dRow;
    int absCol = dCol < 0 ? -dCol : dCol;

    // Movement must be straight or diagonal
    if (dRow != 0 && dCol != 0 && absRow != absCol)
    {
        return false;
    }

    int rowStep = 0;
    int colStep = 0;

    if (dRow > 0)
    {
        rowStep = 1;
    }
    else if (dRow < 0)
    {
        rowStep = -1;
    }

    if (dCol > 0)
    {
        colStep = 1;
    }
    else if (dCol < 0)
    {
        colStep = -1;
    }

    int r = row + rowStep;
    int c = column + colStep;

    // Check each square between the start and end
    while (r != toRow || c != toColumn)
    {
        if (board.getPiece(r, c) != nullptr)
        {
            return false;
        }

        r += rowStep;
        c += colStep;
    }

    return true;
}

// KingPiece functions

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

// ChessBoard functions

ChessBoard::ChessBoard(int numRow, int numCol)
    : numRows(numRow), numCols(numCol),
      board(numRow, std::vector<ChessPiece *>(numCol, nullptr))
{
}

ChessBoard::~ChessBoard()
{
    // Delete all pieces when the board is destroyed
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            delete board[row][col];
        }
    }
}

void ChessBoard::createChessPiece(Color color, Type type, int row, int column)
{
    if (row < 0 || row >= numRows || column < 0 || column >= numCols)
    {
        return;
    }

    ChessPiece *newPiece = nullptr;

    if (type == Pawn)
    {
        newPiece = new Student::PawnPiece(*this, color, row, column);
    }
    else if (type == Rook)
    {
        newPiece = new Student::RookPiece(*this, color, row, column);
    }
    else if (type == Bishop)
    {
        newPiece = new Student::BishopPiece(*this, color, row, column);
    }
    else if (type == King)
    {
        newPiece = new KingPiece(*this, color, row, column);
    }
    else
    {
        return;
    }

    // Delete the old piece before replacing it
    delete board[row][column];
    board[row][column] = newPiece;
}

bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn)
{
    // Make sure both squares are inside the board
    if (fromRow < 0 || fromRow >= numRows ||
        fromColumn < 0 || fromColumn >= numCols ||
        toRow < 0 || toRow >= numRows ||
        toColumn < 0 || toColumn >= numCols)
    {
        return false;
    }

    if (fromRow == toRow && fromColumn == toColumn)
    {
        return false;
    }

    ChessPiece *piece = board[fromRow][fromColumn];

    if (piece == nullptr)
    {
        return false;
    }

    ChessPiece *target = board[toRow][toColumn];

    // Cannot capture a piece with the same color
    if (target != nullptr && target->getColor() == piece->getColor())
    {
        return false;
    }

    return piece->canMoveToLocation(toRow, toColumn);
}

// Part 2 functions
bool ChessBoard::movePiece(int, int, int, int)
{
    return false;
}

bool ChessBoard::isPieceUnderThreat(int, int)
{
    return false;
}
