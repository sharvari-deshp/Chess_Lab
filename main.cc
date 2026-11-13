#include <assert.h>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"

void test_part1_4x4_1()
{
    // Config file content:
    // 0
    // 4 4
    // w r 3 2
    // b b 1 3
    // b r 1 1
    // w r 2 3
    // ~
    // isValidScan

    // Corresponding code
    Student::ChessBoard sBoard(4, 4);
    sBoard.createChessPiece(White, Rook, 3, 2);
    sBoard.createChessPiece(Black, Bishop, 1, 3);
    sBoard.createChessPiece(Black, Rook, 1, 1);
    sBoard.createChessPiece(White, Rook, 2, 3);

    // Calls isValidMove() from every position to every
    // other position on the chess board for all pieces.

    return;
}


void test_rook()
{
    Student::ChessBoard b(5, 5);
    b.createChessPiece(Black, Rook, 4, 4);
    assert(b.isValidMove(4, 4, 4, 0));
    assert(b.isValidMove(4, 4, 0, 4));
    assert(b.isValidMove(4, 4, 4, 3));
    assert(!b.isValidMove(4, 4, 3, 3));
    assert(!b.isValidMove(4, 4, 2, 3));
    assert(!b.isValidMove(4, 4, 4, 4));
    assert(!b.isValidMove(4, 4, 5, 4));
    assert(!b.isValidMove(4, 4, 4, 5));

    b.createChessPiece(Black, Rook, 4, 2);
    b.createChessPiece(White, Rook, 2, 4);
    assert(b.isValidMove(4, 4, 4, 3));
    assert(!b.isValidMove(4, 4, 4, 2));
    assert(!b.isValidMove(4, 4, 4, 1));
    assert(b.isValidMove(4, 4, 2, 4));
    assert(!b.isValidMove(4, 4, 1, 4));

    assert(b.isValidMove(2, 4, 3, 4));
    assert(b.isValidMove(2, 4, 4, 4));
    assert(b.isValidMove(2, 4, 2, 0));
}

void test_bishop()
{
    Student::ChessBoard b(5, 5);
    b.createChessPiece(White, Bishop, 0, 4);
    assert(b.isValidMove(0, 4, 4, 0));
    assert(b.isValidMove(0, 4, 1, 3));
    assert(!b.isValidMove(0, 4, 1, 4));
    assert(!b.isValidMove(0, 4, 0, 0));
    assert(!b.isValidMove(0, 4, 2, 3));
    assert(!b.isValidMove(0, 4, -1, 5));
    assert(!b.isValidMove(0, 4, 1, 5));

    b.createChessPiece(Black, Rook, 2, 2);
    assert(b.isValidMove(0, 4, 1, 3));
    assert(b.isValidMove(0, 4, 2, 2));
    assert(!b.isValidMove(0, 4, 3, 1));

    b.createChessPiece(White, Rook, 2, 2);
    assert(!b.isValidMove(0, 4, 2, 2));
    assert(!b.isValidMove(0, 4, 3, 1));

    Student::ChessBoard e(4, 4);
    e.createChessPiece(Black, Bishop, 3, 2);
    assert(e.isValidMove(3, 2, 2, 1));
    assert(e.isValidMove(3, 2, 2, 3));
    assert(e.isValidMove(3, 2, 1, 0));
    assert(!e.isValidMove(3, 2, 4, 1));
    assert(!e.isValidMove(3, 2, 4, 3));
}

void test_pawn()
{
    Student::ChessBoard b(8, 8);
    b.createChessPiece(Black, Pawn, 1, 4);
    assert(b.isValidMove(1, 4, 2, 4));
    assert(b.isValidMove(1, 4, 3, 4));
    assert(!b.isValidMove(1, 4, 4, 4));
    assert(!b.isValidMove(1, 4, 0, 4));
    assert(!b.isValidMove(1, 4, 1, 5));
    assert(!b.isValidMove(1, 4, 2, 3));
    assert(!b.isValidMove(1, 4, 2, 5));
    assert(!b.isValidMove(1, 4, 3, 6));

    b.createChessPiece(White, Rook, 2, 3);
    b.createChessPiece(Black, Rook, 2, 5);
    assert(b.isValidMove(1, 4, 2, 3));
    assert(!b.isValidMove(1, 4, 2, 5));

    b.createChessPiece(White, Bishop, 3, 4);
    assert(b.isValidMove(1, 4, 2, 4));
    assert(!b.isValidMove(1, 4, 3, 4));

    b.createChessPiece(White, Bishop, 2, 4);
    assert(!b.isValidMove(1, 4, 2, 4));
    assert(!b.isValidMove(1, 4, 3, 4));

    Student::ChessBoard m(8, 8);
    m.createChessPiece(Black, Pawn, 2, 7);
    assert(m.isValidMove(2, 7, 3, 7));
    assert(!m.isValidMove(2, 7, 4, 7));
    assert(!m.isValidMove(2, 7, 3, 8));

    m.createChessPiece(Black, Pawn, 7, 0);
    assert(!m.isValidMove(7, 0, 8, 0));
    assert(!m.isValidMove(7, 0, 6, 0));

    Student::ChessBoard k(8, 8);
    k.createChessPiece(White, Pawn, 6, 0);
    assert(k.isValidMove(6, 0, 5, 0));
    assert(k.isValidMove(6, 0, 4, 0));
    assert(!k.isValidMove(6, 0, 7, 0));
    assert(!k.isValidMove(6, 0, 5, -1));
    k.createChessPiece(Black, Pawn, 5, 1);
    assert(k.isValidMove(6, 0, 5, 1));
    assert(k.isValidMove(5, 1, 6, 0));

    k.createChessPiece(White, Pawn, 4, 7);
    assert(k.isValidMove(4, 7, 3, 7));
    assert(!k.isValidMove(4, 7, 2, 7));
}

void test_non_square()
{
    Student::ChessBoard w(5, 7);
    w.createChessPiece(White, Pawn, 3, 6);
    w.createChessPiece(Black, Pawn, 1, 0);
    assert(w.isValidMove(3, 6, 2, 6));
    assert(w.isValidMove(3, 6, 1, 6));
    assert(!w.isValidMove(3, 6, 2, 7));
    assert(w.isValidMove(1, 0, 2, 0));
    assert(w.isValidMove(1, 0, 3, 0));

    w.createChessPiece(White, Rook, 3, 0);
    assert(!w.isValidMove(1, 0, 3, 0));
    assert(w.isValidMove(3, 0, 3, 5));
    assert(!w.isValidMove(3, 0, 3, 6));
    assert(!w.isValidMove(3, 0, 3, 7));
    assert(w.isValidMove(3, 0, 1, 0));
    assert(!w.isValidMove(3, 0, 0, 0));

    w.createChessPiece(Black, Bishop, 0, 0);
    assert(w.isValidMove(0, 0, 4, 4));
    assert(!w.isValidMove(0, 0, 4, 5));
    assert(!w.isValidMove(0, 0, 5, 5));

    Student::ChessBoard s(7, 3);
    s.createChessPiece(White, Pawn, 5, 1);
    s.createChessPiece(Black, Bishop, 6, 2);
    s.createChessPiece(Black, Rook, 0, 0);
    assert(s.isValidMove(5, 1, 3, 1));
    assert(!s.isValidMove(6, 2, 4, 0));
    assert(s.isValidMove(6, 2, 5, 1));
    assert(!s.isValidMove(6, 2, 5, 3));
    assert(s.isValidMove(0, 0, 6, 0));
    assert(!s.isValidMove(0, 0, 0, 3));
}

void test_path_clear_and_symbols()
{
    Student::ChessBoard b(5, 5);
    b.createChessPiece(Black, Rook, 4, 4);
    b.createChessPiece(White, Bishop, 0, 0);
    b.createChessPiece(White, Pawn, 3, 2);
    Student::ChessPiece *rook = b.getPiece(4, 4);
    Student::ChessPiece *bishop = b.getPiece(0, 0);
    Student::ChessPiece *pawn = b.getPiece(3, 2);

    assert(rook->isPathClear(4, 0));
    assert(rook->isPathClear(4, 3));
    assert(rook->isPathClear(0, 0));
    assert(bishop->isPathClear(4, 4));
    b.createChessPiece(Black, Pawn, 2, 2);
    assert(!rook->isPathClear(0, 0));
    assert(rook->isPathClear(2, 2));

    assert(std::string(rook->toString()) == "♜");
    assert(std::string(bishop->toString()) == "♗");
    assert(std::string(pawn->toString()) == "♙");
    b.createChessPiece(White, Rook, 4, 4);
    b.createChessPiece(Black, Bishop, 0, 0);
    assert(std::string(b.getPiece(4, 4)->toString()) == "♖");
    assert(std::string(b.getPiece(0, 0)->toString()) == "♝");
    assert(std::string(b.getPiece(2, 2)->toString()) == "♟");
}

void test_threats()
{
    Student::ChessBoard b(5, 7);
    b.createChessPiece(Black, Rook, 3, 3);
    b.createChessPiece(White, Rook, 3, 6);
    assert(b.isPieceUnderThreat(3, 3));

    b.createChessPiece(Black, Pawn, 3, 5);
    assert(!b.isPieceUnderThreat(3, 3));

    Student::ChessBoard d(5, 7);
    d.createChessPiece(Black, Rook, 2, 2);
    d.createChessPiece(White, Pawn, 3, 3);
    assert(d.isPieceUnderThreat(2, 2));

    Student::ChessBoard s(5, 7);
    s.createChessPiece(Black, Rook, 2, 2);
    s.createChessPiece(White, Pawn, 3, 2);
    assert(!s.isPieceUnderThreat(2, 2));

    assert(!s.isPieceUnderThreat(0, 6));
    assert(!s.isPieceUnderThreat(-1, 0));
    assert(!s.isPieceUnderThreat(5, 0));
}

void test_threat_edge_cases()
{
    Student::ChessBoard b(4, 4);
    b.createChessPiece(Black, Pawn, 1, 2);
    b.createChessPiece(White, Rook, 2, 3);
    b.createChessPiece(White, Bishop, 0, 1);
    assert(b.isPieceUnderThreat(2, 3));
    assert(b.isPieceUnderThreat(1, 2));
    assert(!b.isPieceUnderThreat(0, 1));
    assert(!b.isPieceUnderThreat(3, 3));
    assert(!b.isPieceUnderThreat(4, 0));

    Student::ChessBoard k(4, 4);
    k.createChessPiece(White, Pawn, 2, 2);
    k.createChessPiece(Black, Rook, 3, 3);
    k.createChessPiece(Black, Bishop, 1, 1);
    k.createChessPiece(White, Rook, 0, 1);
    assert(!k.isPieceUnderThreat(3, 3));
    assert(k.isPieceUnderThreat(1, 1));
    assert(k.isPieceUnderThreat(2, 2));

    Student::ChessBoard s(4, 4);
    s.createChessPiece(White, Rook, 3, 3);
    s.createChessPiece(Black, Rook, 0, 0);
    assert(!s.isPieceUnderThreat(3, 3));
    assert(s.movePiece(3, 3, 3, 0));
    assert(s.isPieceUnderThreat(3, 0));
    assert(s.isPieceUnderThreat(0, 0));
    assert(!s.isPieceUnderThreat(3, 3));
}

void test_rules_in_can_move()
{
    Student::ChessBoard b(4, 4);
    b.createChessPiece(Black, Rook, 3, 3);
    b.createChessPiece(Black, Bishop, 2, 2);
    b.createChessPiece(Black, Pawn, 1, 1);
    b.createChessPiece(Black, Rook, 3, 1);
    b.createChessPiece(Black, Pawn, 2, 0);

    Student::ChessPiece *rook = b.getPiece(3, 3);
    Student::ChessPiece *bishop = b.getPiece(2, 2);
    Student::ChessPiece *pawn = b.getPiece(1, 1);

    assert(!rook->canMoveToLocation(3, 3));
    assert(!bishop->canMoveToLocation(2, 2));
    assert(!pawn->canMoveToLocation(1, 1));

    assert(!rook->canMoveToLocation(3, 1));
    assert(!bishop->canMoveToLocation(1, 1));
    assert(!pawn->canMoveToLocation(2, 0));

    assert(!rook->canMoveToLocation(4, 3));
    assert(!rook->canMoveToLocation(3, -1));
    assert(!bishop->canMoveToLocation(4, 4));
    assert(!bishop->canMoveToLocation(-1, -1));
    assert(!pawn->canMoveToLocation(-1, 1));
    assert(!pawn->canMoveToLocation(1, 4));
}

void test_move_captures()
{
    Student::ChessBoard b(5, 5);
    b.createChessPiece(White, Bishop, 4, 0);
    b.createChessPiece(Black, Bishop, 2, 2);
    b.createChessPiece(Black, Pawn, 1, 1);

    assert(b.movePiece(4, 0, 2, 2));
    assert(b.getPiece(4, 0) == nullptr);
    assert(b.getPiece(2, 2)->getColor() == White);
    assert(b.getPiece(2, 2)->getType() == Bishop);
    assert(b.getPiece(2, 2)->getRow() == 2);
    assert(b.getPiece(2, 2)->getColumn() == 2);

    assert(b.movePiece(1, 1, 2, 2));
    assert(b.getPiece(1, 1) == nullptr);
    assert(b.getPiece(2, 2)->getColor() == Black);
    assert(b.getPiece(2, 2)->getType() == Pawn);
    assert(b.getPiece(2, 2)->getRow() == 2);
    assert(b.getPiece(2, 2)->getColumn() == 2);

    Student::ChessBoard s(4, 4);
    s.createChessPiece(White, Bishop, 3, 0);
    s.createChessPiece(White, Rook, 1, 2);
    assert(!s.movePiece(3, 0, 1, 2));
    assert(s.getPiece(3, 0)->getType() == Bishop);
    assert(s.getPiece(1, 2)->getType() == Rook);
}

void test_move_turns()
{
    Student::ChessBoard b(4, 4);
    b.createChessPiece(White, Bishop, 3, 0);
    b.createChessPiece(Black, Bishop, 0, 0);

    assert(!b.movePiece(0, 0, 1, 1));
    assert(b.getPiece(0, 0) != nullptr);
    assert(b.getPiece(1, 1) == nullptr);
    assert(b.isValidMove(0, 0, 1, 1));

    assert(b.movePiece(3, 0, 2, 1));
    assert(!b.movePiece(2, 1, 3, 2));
    assert(b.getPiece(2, 1) != nullptr);
    assert(b.getPiece(3, 2) == nullptr);

    assert(b.movePiece(0, 0, 1, 1));
    assert(!b.movePiece(1, 1, 0, 2));
    assert(b.movePiece(2, 1, 3, 2));
}

void test_move_invalid_then_valid()
{
    Student::ChessBoard b(4, 4);
    b.createChessPiece(White, Bishop, 3, 3);
    b.createChessPiece(Black, Rook, 0, 0);

    assert(!b.movePiece(3, 3, 3, 2));
    assert(b.getPiece(3, 3) != nullptr);
    assert(b.getPiece(3, 2) == nullptr);
    assert(b.getPiece(3, 3)->getRow() == 3);
    assert(b.getPiece(3, 3)->getColumn() == 3);

    assert(!b.movePiece(3, 3, 3, 3));
    assert(!b.movePiece(3, 3, 4, 4));
    assert(!b.movePiece(3, 3, 2, 4));
    assert(!b.movePiece(-1, 3, 3, 3));
    assert(!b.movePiece(3, -1, 3, 3));

    assert(!b.movePiece(0, 0, 0, 1));
    assert(b.movePiece(3, 3, 2, 2));
    assert(!b.movePiece(0, 0, 1, 1));
    assert(b.movePiece(0, 0, 0, 1));
}

void test_move_pawn_two_step()
{
    Student::ChessBoard b(9, 4);
    b.createChessPiece(White, Pawn, 7, 1);
    b.createChessPiece(Black, Pawn, 1, 2);

    assert(b.movePiece(7, 1, 5, 1));
    assert(b.movePiece(1, 2, 3, 2));
    assert(!b.movePiece(5, 1, 3, 1));
    assert(b.getPiece(5, 1) != nullptr);
    assert(b.getPiece(3, 1) == nullptr);
    assert(b.movePiece(5, 1, 4, 1));
    assert(!b.movePiece(3, 2, 5, 2));
    assert(b.movePiece(3, 2, 4, 2));

    Student::ChessBoard s(9, 4);
    s.createChessPiece(White, Pawn, 7, 1);
    s.createChessPiece(Black, Pawn, 1, 2);
    assert(s.movePiece(7, 1, 6, 1));
    assert(s.movePiece(1, 2, 2, 2));
    assert(!s.movePiece(6, 1, 4, 1));
    assert(s.movePiece(6, 1, 5, 1));
    assert(!s.movePiece(2, 2, 4, 2));
}

void test_move_from_empty()
{
    Student::ChessBoard b(4, 4);
    b.createChessPiece(White, Bishop, 3, 3);
    b.createChessPiece(Black, Bishop, 0, 3);

    assert(!b.movePiece(1, 1, 2, 2));
    assert(b.getPiece(1, 1) == nullptr);
    assert(b.getPiece(2, 2) == nullptr);

    assert(b.movePiece(3, 3, 2, 2));
    assert(!b.movePiece(3, 3, 1, 1));
    assert(b.getPiece(1, 1) == nullptr);

    assert(b.movePiece(0, 3, 1, 2));
}

int main()
{
    test_part1_4x4_1();
    test_rook();
    test_bishop();
    test_pawn();
    test_non_square();
    test_path_clear_and_symbols();
    test_threats();
    test_threat_edge_cases();
    test_rules_in_can_move();
    test_move_captures();
    test_move_turns();
    test_move_invalid_then_valid();
    test_move_pawn_two_step();
    test_move_from_empty();
    return EXIT_SUCCESS;
}
