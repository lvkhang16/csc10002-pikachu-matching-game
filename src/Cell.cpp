#include "Cell.h"

char box[5][10] = {
            {"*-------*"},
            {"|       |"},
            {"|       |"},
            {"|       |"},
            {"*-------*"}
}; // For printing out the border of a cell

void Cell::drawBox(int level, int background)
{
    if (!isValid)
        return;

    int x = j + 1;
    int y = i + 1;

    int paddingX, paddingY;

    switch (level) // Getting the paddings for each level
    {
        case 1:
            paddingX = 7;
            paddingY = 8;
            break;
        case 2:
            paddingX = 4;
            paddingY = 6;
            break;
        case 3:
            paddingX = 2;
            paddingY = 3;
            break;
    }



    for (int i = 0; i < 5; i++)
    {
        goTo(paddingX + x * 8, paddingY + y * 4 + i);
        cout << box[i];
    }

    if (background != 0)
    {
        setColor(background * 16 + (character % 6) + 1);
        for (int i = 1; i < 4; i++)
        {
            goTo(paddingX + x * 8 + 1, paddingY + y * 4 + i);
            cout << "       ";
        }
        goTo(paddingX + x * 8 + 4, paddingY + y * 4 + 2);
        cout << character;
        setColor(15);
    }
    else if (isSelected)
    {
        setColor(224 + (character % 6) + 1);

        for (int i = 1; i < 4; i++)
        {
            goTo(paddingX + x * 8 + 1, paddingY + y * 4 + i);
            cout << "       ";
        }
        goTo(paddingX + x * 8 + 4, paddingY + y * 4 + 2);
        cout << character;
        setColor(15);
    }
    else if (isHovered) {
        setColor(240 + (character % 6) + 1);
        for (int i = 1; i < 4; i++)
        {
            goTo(paddingX + x * 8 + 1, paddingY + y * 4 + i);
            cout << "       ";
        }
        goTo(paddingX + x * 8 + 4, paddingY + y * 4 + 2);
        cout << character;
        setColor(15);
    } else if (isSuggested) {
        setColor(144 + (character % 6) + 1);

        for (int i = 1; i < 4; i++) {
            goTo(paddingX + x * 8 + 1, paddingY + y * 4 + i);
            cout << "       ";
        }
        goTo(paddingX + x * 8 + 4, paddingY + y * 4 + 2);
        cout << character;
        setColor(15);
    } else {
        goTo(paddingX + x * 8 + 4, paddingY + y * 4 + 2);
        setColor((character % 6) + 1);
        cout << character;
    }

    setColor(15);
}

void Cell::deleteBox(int level) {
    int x = j + 1;
    int y = i + 1;

    int paddingX, paddingY;

    // Getting the paddings for each level
    switch (level) {
        case 1:
            paddingX = 7;
            paddingY = 8;
            break;
        case 2:
            paddingX = 4;
            paddingY = 6;
            break;
        case 3:
            paddingX = 2;
            paddingY = 3;
            break;
    }

    for (int i = 0; i < 5; i++) {
        goTo(paddingX + x * 8, paddingY + y * 4 + i);
        cout << "         ";
    }
}

void SlidingCell::drawBox(int level, int background) {
    int x = j + 1;
    int y = i + 1;

    int paddingX, paddingY;

    // Getting the paddings for each level
    switch (level) {
        case 1:
            paddingX = 7;
            paddingY = 8;
            break;
        case 2:
            paddingX = 4;
            paddingY = 6;
            break;
        case 3:
            paddingX = 2;
            paddingY = 3;
            break;
    }

    for (int i = 0; i < 5; i++) {
        goTo(paddingX + x * 8, paddingY + y * 4 + i);
        cout << box[i];
    }

    if (isSelected) {
        if (background == 0) {
            setColor(224 + (character % 6) + 1);
            for (int i = 1; i < 4; i++)
            {
                goTo(paddingX + x * 8 + 1, paddingY + y * 4 + i);
                cout << "       ";
            }
            goTo(paddingX + x * 8 + 4, paddingY + y * 4 + 2);
            cout << character;
            setColor(15);
        } else {
            setColor(background * 16 + (character % 6) + 1);
            for (int i = 1; i < 4; i++)
            {
                goTo(paddingX + x * 8 + 1, paddingY + y * 4 + i);
                cout << "       ";
            }
            goTo(paddingX + x * 8 + 4, paddingY + y * 4 + 2);
            cout << character;
            setColor(15);
        }
    }
    else if (isHovered) {
        setColor(240 + (character % 6) + 1);
        for (int i = 1; i < 4; i++) {
            goTo(paddingX + x * 8 + 1, paddingY + y * 4 + i);
            cout << "       ";
        }
        goTo(paddingX + x * 8 + 4, paddingY + y * 4 + 2);
        cout << character;
        setColor(15);
    } else if (isSuggested) {
        setColor(176 + (character % 6) + 1);
        for (int i = 1; i < 4; i++) {
            goTo(paddingX + x * 8 + 1, paddingY + y * 4 + i);
            cout << "       ";
        }
        goTo(paddingX + x * 8 + 4, paddingY + y * 4 + 2);
        cout << character;
        setColor(15);
    } else {
        goTo(paddingX + x * 8 + 4, paddingY + y * 4 + 2);
        setColor((character % 6) + 1);
        cout << character;
    }

    setColor(15);
}

void SlidingCell::deleteBox(int level) {
    int x = j + 1;
    int y = i + 1;

    int paddingX, paddingY;

    // Getting the paddings for each level
    switch (level) {
        case 1:
            paddingX = 7;
            paddingY = 8;
            break;
        case 2:
            paddingX = 4;
            paddingY = 6;
            break;
        case 3:
            paddingX = 2;
            paddingY = 3;
            break;
    }

    for (int i = 0; i < 5; i++) {
        goTo(paddingX + x * 8, paddingY + y * 4 + i);
        cout << "         ";
    }
}

// Counts the number of cells left in a row
int countNodes(SlidingCell *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Inserts a cell at the beginning of a row
void push(SlidingCell *&head, SlidingCell *p) {
    if (head == NULL) {
        head = p;
    } else {
        SlidingCell *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
}
