#pragma once

#include "utils.h"

struct Cell {
    int i, j;
    char character = ' ';
    bool isValid = true, isHovered = false, isSelected = false, isSuggested = false;

    void drawBox(int level, int background = 0);
    void deleteBox(int level);
};

struct SlidingCell {
    int i, j;
    char character = ' ';
    bool isHovered = false, isSelected = false, isSuggested = false;
    SlidingCell *next;

    void drawBox(int level, int background = 0);
    void deleteBox(int level);
};

int countNodes(SlidingCell *head);
void push(SlidingCell *&head, SlidingCell *p);
